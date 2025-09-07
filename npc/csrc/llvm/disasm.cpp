// 动态加载和使用LLVM反汇编器库的C接口实现
// 作用：动态加载LLVM反汇编器共享库，调用其功能进行RISC-V指令反汇编，若加载失败则使用objdump作为后备方案
#include <dlfcn.h>  // 提供动态加载库的函数（如dlopen、dlsym、dlclose）
#include <stdio.h>  // 提供标准输入输出函数（如printf、fprintf）
#include <stdlib.h> // 提供标准库函数（如exit）
#include <cstdlib>  // 提供C++标准库函数（如std::getenv）
#include <cstdint>  // 提供固定宽度整数类型（如uint64_t、uint32_t）
#include <cstring>  // 提供字符串操作函数（如strcspn）
#include <unistd.h> // 提供POSIX系统调用（如write、close、unlink、mkstemp）
#include"disasm.h"

// 函数指针类型定义
// 作用：定义与LLVM反汇编器共享库中函数签名匹配的函数指针类型
typedef int (*llvm_disasm_init_t)(const char *);                                   // 初始化函数指针，接受目标架构三元组
typedef int (*llvm_disasm_instruction_t)(uint64_t, uint32_t, int, char *, size_t); // 反汇编函数指针，处理单条指令
typedef void (*llvm_disasm_cleanup_t)();                                           // 清理函数指针，释放资源

// 全局变量
// 作用：存储动态库句柄和函数指针，跟踪库加载状态
static void *llvm_lib_handle = nullptr;                               // 动态库句柄，指向加载的共享库
static llvm_disasm_init_t f_llvm_disasm_init = nullptr;               // 初始化函数指针
static llvm_disasm_instruction_t f_llvm_disasm_instruction = nullptr; // 反汇编函数指针
static llvm_disasm_cleanup_t f_llvm_disasm_cleanup = nullptr;         // 清理函数指针
static bool lib_loaded = false;                                       // 标记是否成功加载并初始化LLVM库

// 函数：init_disasm_llvm
// 作用：动态加载LLVM反汇编器共享库，初始化反汇编器
extern "C" void init_disasm_llvm()
{
    // 可能的共享库路径列表
    const char *wrapper_libs = "libllvm_wrapper.so";
   // {
       /* "./libllvm_wrapper.so",              // 当前目录下的共享库
        "/usr/local/lib/libllvm_wrapper.so", // 系统标准库路径
        "libllvm_wrapper.so"};*/
    // 依赖系统库路径查找

    // 尝试加载共享库
   // for (int i = 0; i < 3; i++)
    //{
        llvm_lib_handle = dlopen(wrapper_libs, RTLD_LAZY); // RTLD_LAZY表示延迟符号解析
        if (llvm_lib_handle)
        {
            printf("Successfully loaded LLVM wrapper: %s\n", wrapper_libs);
      //      break; // 成功加载后退出循环
        }
    //}

    // 检查是否成功加载共享库
    if (!llvm_lib_handle)
    {
        fprintf(stderr, "Cannot load LLVM wrapper library: %s\n", dlerror()); // 输出错误信息
        fprintf(stderr, "Falling back to system objdump\n");                  // 提示将使用objdump后备方案
        return;
    }

    // 加载共享库中的函数符号
    f_llvm_disasm_init = (llvm_disasm_init_t)dlsym(llvm_lib_handle, "llvm_disasm_init");
    f_llvm_disasm_instruction = (llvm_disasm_instruction_t)dlsym(llvm_lib_handle, "llvm_disasm_instruction");
    f_llvm_disasm_cleanup = (llvm_disasm_cleanup_t)dlsym(llvm_lib_handle, "llvm_disasm_cleanup");

    // 检查是否成功加载所有函数
    if (!f_llvm_disasm_init || !f_llvm_disasm_instruction || !f_llvm_disasm_cleanup)
    {
        fprintf(stderr, "Cannot load LLVM wrapper functions: %s\n", dlerror()); // 输出错误信息
        dlclose(llvm_lib_handle);                                               // 关闭共享库
        llvm_lib_handle = nullptr;                                              // 重置句柄
        return;
    }

    // 初始化LLVM反汇编器，指定目标架构为"riscv32"
    if (f_llvm_disasm_init("riscv32"))
    {
        lib_loaded = true; // 标记初始化成功
        printf("LLVM disassembler initialized successfully\n");
    }
    else
    {
        fprintf(stderr, "Failed to initialize LLVM disassembler\n");
        dlclose(llvm_lib_handle);  // 关闭共享库
        llvm_lib_handle = nullptr; // 重置句柄
    }
}

// 函数：free_disasm_llvm
// 作用：清理LLVM反汇编器资源，关闭动态库
extern "C" void free_disasm_llvm()
{
    // 如果成功加载并初始化，调用清理函数
    if (lib_loaded && f_llvm_disasm_cleanup)
    {
        f_llvm_disasm_cleanup();
    }

    // 关闭动态库
    if (llvm_lib_handle)
    {
        dlclose(llvm_lib_handle);
        llvm_lib_handle = nullptr;
    }

    lib_loaded = false; // 重置加载状态
}

// 函数：objdump_disasm
// 作用：使用系统objdump工具作为后备方案，反汇编RISC-V指令
// 参数：
//   - pc: 程序计数器（指令地址）
//   - instruction_word: 32位指令机器码
//   - instr_len_bytes: 指令长度（字节）
static void objdump_disasm(long long pc, unsigned int instruction_word, int instr_len_bytes)
{
    char cmd[512];                           // 存储objdump命令
    char temp_file[] = "/tmp/disasm_XXXXXX"; // 临时文件模板
    int fd = mkstemp(temp_file);             // 创建唯一的临时文件

    // 检查临时文件创建是否成功
    if (fd == -1)
    {
        printf("0x%08llx: 0x%08x \t(Error creating temp file)\n", pc,instruction_word);
        return;
    }

    // 将指令机器码分解为字节数组（考虑字节序）
    uint8_t bytes[instr_len_bytes];
    for (int i = 0; i < instr_len_bytes; ++i)
    {
        bytes[i] = (instruction_word >> (i * 8)) & 0xFF;
    }
    // 将字节写入临时文件
    ssize_t temp = write(fd, bytes, instr_len_bytes);
    if (temp < 0)
    {
        perror("write failed");
        close(fd);
        return;
    }
    close(fd); // 关闭文件

    // 构造objdump命令
    // -D: 反汇编整个文件
    // -b binary: 指定输入为二进制
    // -m riscv:rv32: 指定RISC-V 32位架构
    // --adjust-vma: 设置虚拟内存地址
    // grep/sed: 提取反汇编输出中的指令部分
    snprintf(cmd, sizeof(cmd),
             "objdump -D -b binary -m riscv:rv32 --adjust-vma=0x%llx %s 2>/dev/null | "
             "grep -E '^[[:space:]]*%llx:' | head -1 | "
             "sed 's/^[[:space:]]*[0-9a-f]*:[[:space:]]*[0-9a-f]*[[:space:]]*//'",
             pc, temp_file, pc);

    // 执行objdump命令
    FILE *fp = popen(cmd, "r");
    if (fp)
    {
        char result[256]; // 存储反汇编结果
        if (fgets(result, sizeof(result), fp))
        {
            // 移除换行符
            result[strcspn(result, "\n")] = 0;
            if (strlen(result) > 0)
            {
                // 输出格式：地址 机器码 指令
                printf("0x%08llx: 0x%08x \t%s\n", pc, instruction_word, result);
            }
            else
            {
                printf("0x%08llx: 0x%08x \t(Unknown)\n", pc, instruction_word);
            }
        }
        else
        {
            printf("0x%08llx: 0x%08x \t(Unknown)\n", pc, instruction_word);
        }
        pclose(fp); // 关闭管道
    }
    else
    {
        printf("0x%08llx: 0x%08x \t(Disasm failed)\n", pc, instruction_word);
    }

    unlink(temp_file); // 删除临时文件
}

// 函数：itrace_print
// 作用：打印指令跟踪信息，优先使用LLVM反汇编器，若失败则使用objdump
// 参数：
//   - pc: 程序计数器（指令地址）
//   - instruction_word: 32位指令机器码
//   - instr_len_bytes: 指令长度（字节）
extern "C" void itrace_print(long long pc, unsigned int instruction_word, int instr_len_bytes,int p_count_number)
{
    // 优先尝试使用LLVM反汇编器
    if (lib_loaded && f_llvm_disasm_instruction)
    {
        char output[256]; // 存储反汇编结果
        int result = f_llvm_disasm_instruction((uint64_t)pc, instruction_word,instr_len_bytes, output, sizeof(output));

        // 如果反汇编成功，打印结果
        if (result > 0)
        {
            if(p_count_number > 100){
                return;
            }

            printf("0x%08llx: 0x%08x \t%s\n", pc, instruction_word, output);
            return;
        }
    }

    // 如果LLVM不可用或失败，使用objdump后备方案
    objdump_disasm(pc, instruction_word, instr_len_bytes);
}