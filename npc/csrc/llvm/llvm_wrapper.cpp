// llvm_wrapper.cpp - LLVM C包装器
// 作用：提供一个C语言接口，用于初始化LLVM反汇编器，执行RISC-V指令反汇编，并管理相关资源

#include "llvm/Support/raw_ostream.h"              // 提供输出流功能，用于格式化输出
#include "llvm/Support/Error.h"                    // 提供错误处理功能
#include "llvm/MC/TargetRegistry.h"                // 提供目标架构注册表，用于查找目标架构
#include "llvm/Support/InitLLVM.h"                 // 提供LLVM初始化功能
#include "llvm/ADT/ArrayRef.h"                     // 提供ArrayRef类，用于管理字节数组
#include "llvm/MC/MCAsmInfo.h"                     // 提供汇编信息类，包含汇编器相关设置
#include "llvm/MC/MCContext.h"                     // 提供MC上下文类，管理反汇编环境
#include "llvm/MC/MCDisassembler/MCDisassembler.h" // 提供反汇编器基类
#include "llvm/MC/MCInst.h"                        // 提供机器指令类，表示单条指令
#include "llvm/MC/MCInstPrinter.h"                 // 提供指令打印功能，将指令转换为字符串
#include "llvm/MC/MCRegisterInfo.h"                // 提供寄存器信息类，描述目标架构的寄存器
#include "llvm/MC/MCSubtargetInfo.h"               // 提供子目标信息类，描述目标架构的特性
#include "llvm/MC/MCTargetOptions.h"               // 提供目标选项类，配置目标特定选项
#include "llvm/MC/MCInstrInfo.h"                   // 提供指令信息类，描述目标架构的指令集
#include "llvm/Target/TargetMachine.h"             // 提供目标机器类，管理目标架构的编译和代码生成
#include "llvm/Support/TargetSelect.h"             // 提供目标选择函数，用于初始化目标架构

// C接口结构体
// 作用：封装LLVM反汇编所需的各种对象，方便管理和传递
struct LLVMDisasmContext
{
    const llvm::Target *target;                           // 目标架构对象，指向选定的目标（如RISC-V）
    std::unique_ptr<llvm::MCAsmInfo> asmInfo;             // 汇编信息，包含汇编器设置（如指令语法）
    std::unique_ptr<llvm::MCRegisterInfo> registerInfo;   // 寄存器信息，描述目标架构的寄存器集
    std::unique_ptr<llvm::MCInstrInfo> instrInfo;         // 指令信息，描述目标架构的指令集
    std::unique_ptr<llvm::MCSubtargetInfo> subtargetInfo; // 子目标信息，描述目标架构的特性（如指令扩展）
    std::unique_ptr<llvm::MCContext> context;             // 反汇编上下文，管理反汇编环境
    std::unique_ptr<llvm::MCDisassembler> disassembler;   // 反汇编器对象，执行指令解码
    std::unique_ptr<llvm::MCInstPrinter> instPrinter;     // 指令打印器，将解码的指令转换为字符串
};

// 全局上下文指针
// 作用：保存全局唯一的反汇编上下文，避免多次初始化
static LLVMDisasmContext *g_ctx = nullptr;

extern "C"
{
    // 函数：llvm_disasm_init
    // 作用：初始化LLVM反汇编器，创建并配置目标架构的上下文
    // 参数：triple_str - 目标架构的三元组字符串（如"riscv32"），指定目标架构
    // 返回：1表示成功，0表示失败，1（重复初始化）表示已经初始化
    int llvm_disasm_init(const char *triple_str)
    {
        // 检查是否已经初始化，避免重复初始化
        if (g_ctx)
        {
            return 1; // 已经初始化
        }

        // 创建全局上下文对象
        g_ctx = new LLVMDisasmContext();

        // 初始化所有目标架构的信息、MC和反汇编器
        llvm::InitializeAllTargetInfos();
        llvm::InitializeAllTargetMCs();
        llvm::InitializeAllDisassemblers();

        // 设置默认目标为"riscv32"，如果未提供triple_str
        std::string Triple = triple_str ? triple_str : "riscv32";
        std::string Error; // 用于存储错误信息

        // 查找目标架构
        g_ctx->target = llvm::TargetRegistry::lookupTarget(Triple, Error);
        if (!g_ctx->target)
        {
            llvm::errs() << "Error looking up target: " << Error << "\n";
            delete g_ctx; // 清理资源
            g_ctx = nullptr;
            return 0; // 失败
        }

        // 创建寄存器信息对象
        g_ctx->registerInfo.reset(g_ctx->target->createMCRegInfo(Triple));
        if (!g_ctx->registerInfo)
        {
            llvm::errs() << "Error creating MCRegisterInfo\n";
            delete g_ctx;
            g_ctx = nullptr;
            return 0;
        }

        // 创建指令信息对象
        g_ctx->instrInfo.reset(g_ctx->target->createMCInstrInfo());
        if (!g_ctx->instrInfo)
        {
            llvm::errs() << "Error creating MCInstrInfo\n";
            delete g_ctx;
            g_ctx = nullptr;
            return 0;
        }

        // 创建汇编信息对象
        llvm::MCTargetOptions MCOptions; // 目标选项，当前未设置具体选项
        g_ctx->asmInfo.reset(g_ctx->target->createMCAsmInfo(*g_ctx->registerInfo, Triple, MCOptions));
        if (!g_ctx->asmInfo)
        {
            llvm::errs() << "Error creating MCAsmInfo\n";
            delete g_ctx;
            g_ctx = nullptr;
            return 0;
        }

        // 创建子目标信息对象
        std::string Features = ""; // 特性字符串，当前未指定额外特性
        g_ctx->subtargetInfo.reset(g_ctx->target->createMCSubtargetInfo(Triple, "", Features));
        if (!g_ctx->subtargetInfo)
        {
            llvm::errs() << "Error creating MCSubtargetInfo\n";
            delete g_ctx;
            g_ctx = nullptr;
            return 0;
        }

        // 创建反汇编上下文
        g_ctx->context.reset(new llvm::MCContext(
            llvm::Triple(Triple),       // 目标三元组
            g_ctx->asmInfo.get(),       // 汇编信息
            g_ctx->registerInfo.get(),  // 寄存器信息
            g_ctx->subtargetInfo.get(), // 子目标信息
            nullptr,                    // 代码生成器（未使用）
            nullptr,                    // 符号表（未使用）
            false,                      // 不使用调试信息
            ""));                       // 无额外选项
        if (!g_ctx->context)
        {
            llvm::errs() << "Error creating MCContext\n";
            delete g_ctx;
            g_ctx = nullptr;
            return 0;
        }

        // 创建反汇编器对象
        g_ctx->disassembler.reset(g_ctx->target->createMCDisassembler(*g_ctx->subtargetInfo, *g_ctx->context));
        if (!g_ctx->disassembler)
        {
            llvm::errs() << "Error creating MCDisassembler\n";
            delete g_ctx;
            g_ctx = nullptr;
            return 0;
        }

        // 创建指令打印器对象
        g_ctx->instPrinter.reset(g_ctx->target->createMCInstPrinter(
            llvm::Triple(Triple),                  // 目标三元组
            g_ctx->asmInfo->getAssemblerDialect(), // 汇编方言
            *g_ctx->asmInfo,                       // 汇编信息
            *g_ctx->instrInfo,                     // 指令信息
            *g_ctx->registerInfo));                // 寄存器信息
        if (!g_ctx->instPrinter)
        {
            llvm::errs() << "Error creating MCInstPrinter\n";
            delete g_ctx;
            g_ctx = nullptr;
            return 0;
        }

        return 1; // 初始化成功
    }

    // 函数：llvm_disasm_instruction
    // 作用：反汇编单条指令，将机器码转换为汇编指令字符串
    // 参数：
    //   - pc: 程序计数器（指令地址）
    //   - instruction_word: 指令的机器码（32位）
    //   - instr_len_bytes: 指令长度（字节）
    //   - output: 输出缓冲区，存储反汇编后的指令字符串
    //   - output_size: 输出缓冲区大小
    // 返回：
    //   - 1: 成功反汇编
    //   - 2: 软失败（可能部分解码）
    //   - 3: 无效指令
    //   - 0: 上下文未初始化
    int llvm_disasm_instruction(uint64_t pc, uint32_t instruction_word,
                                int instr_len_bytes, char *output, size_t output_size)
    {
        // 检查上下文是否初始化
        if (!g_ctx)
        {
            return 0;
        }

        // 将32位指令机器码分解为字节数组（考虑字节序）
        uint8_t bytes[instr_len_bytes];
        for (int i = 0; i < instr_len_bytes; ++i)
        {
            bytes[i] = (instruction_word >> (i * 8)) & 0xFF;
        }

        // 创建字节数组引用，用于反汇编
        llvm::ArrayRef<uint8_t> instruction_bytes(bytes, instr_len_bytes);
        llvm::MCInst MI;   // 存储解码后的指令
        uint64_t Size = 0; // 存储解码的指令长度

        // 执行反汇编
        llvm::MCDisassembler::DecodeStatus status =
            g_ctx->disassembler->getInstruction(MI, Size, instruction_bytes, pc, llvm::nulls());

        // 根据反汇编状态处理结果
        if (status == llvm::MCDisassembler::Success)
        {
            std::string buffer;                                                      // 临时存储反汇编结果
            llvm::raw_string_ostream OS(buffer);                                     // 输出流
            g_ctx->instPrinter->printInst(&MI, Size, "", *g_ctx->subtargetInfo, OS); // 打印指令
            OS.flush();                                                              // 刷新输出流

            // 将结果复制到输出缓冲区
            snprintf(output, output_size, "%s", buffer.c_str());
            return 1; // 成功
        }
        else if (status == llvm::MCDisassembler::SoftFail)
        {
            snprintf(output, output_size, "(Soft Fail)");
            return 2; // 软失败
        }
        else
        {
            snprintf(output, output_size, "(Invalid Instruction)");
            return 3; // 无效指令
        }
    }

    // 函数：llvm_disasm_cleanup
    // 作用：清理反汇编器资源，释放内存
    void llvm_disasm_cleanup()
    {
        if (g_ctx)
        {
            delete g_ctx;    // 释放全局上下文
            g_ctx = nullptr; // 重置指针
        }
    }

} // extern "C"