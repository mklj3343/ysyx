#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <isa.h>
#include <memory/paddr.h>
#include "local-include/reg.h"

#define R(i) gpr(i)

typedef struct
{
    uint32_t name_offset;
    uint32_t value;
    uint32_t size;
    uint64_t call_count;
} FuncSymbol;
// 保存一个函数符号的信号

typedef struct  
{
    const char *alignment;
    const char *length;
    uint64_t count;
    uint64_t total_size;//根据平局值大小进行优化，可以一次复制多个
} MemcpyStat;;

static MemcpyStat memcpy_stats[3][3] = {

    {{"aligned", "short", 0, 0}, {"aligned", "medium", 0, 0}, {"aligned", "long", 0, 0}},
    {{"partially aligned", "short", 0, 0}, {"partially aligned", "medium", 0, 0}, {"partially aligned", "long", 0, 0}},
    {{"unaligned", "short", 0, 0}, {"unaligned", "medium", 0, 0}, {"unaligned", "long", 0, 0}}};

static FuncSymbol *func_symbols = NULL; // 保存所有函数符号信息的数组
static int func_count = 0;
static char *strtab_data = NULL; // 字符串表的内容
static uint32_t strtab_size = 0;
static int indent_level = 0; // 调用层次

// 提取符号表信息
void init_ftrace(const char *elf_file)
{
    FILE *fp = fopen(elf_file, "rb");
    if (!fp)
    {
        printf("Error: Failed to open ELF file: %s \n", elf_file);
        exit(1);
    }
    Elf32_Ehdr ehdr; // 读取 ELF 头，ELF 文件头结构体，包含 ELF 文件的元数据
    if (fread(&ehdr, sizeof(ehdr), 1, fp) != 1)
    {
        printf("Error: Failed to read ELF header\n");
        fclose(fp);
        exit(1);
    }

    // 检查是不是 ELF 文件（魔数检查 \x7fELF）
    if (strncmp((char *)ehdr.e_ident, "\x7f""ELF",4) != 0)
    {
        printf("Error: Not an ELF file\n");
        fclose(fp);
        exit(1);
    }

    // 读取所有节区头（section header）
    Elf32_Shdr *shdr = malloc(ehdr.e_shentsize * ehdr.e_shnum); 

    if (!shdr)
    {
        printf("Error: Failed to allocate memory for section headers\n");
        fclose(fp);
        exit(1);
    }
    fseek(fp, ehdr.e_shoff, SEEK_SET);
    if (fread(shdr, ehdr.e_shentsize, ehdr.e_shnum, fp) != ehdr.e_shnum)
    {
        printf("Error: Failed to read section headers\n");
        free(shdr);
        fclose(fp);
        exit(1);
    }

    // 读取节区字符串表（shstrtab），用于找到.symtab和.strtab
    char *shstrtab = malloc(shdr[ehdr.e_shstrndx].sh_size); 
    if (!shstrtab)
    {
        printf("Error: Failed to allocate memory for shstrtab\n");
        free(shdr);
        fclose(fp);
        exit(1);
    }
    fseek(fp, shdr[ehdr.e_shstrndx].sh_offset, SEEK_SET); 
    if (fread(shstrtab, shdr[ehdr.e_shstrndx].sh_size, 1, fp) != 1)
    {
        printf("Error: Failed to read shstrtab\n");
        free(shstrtab);
        free(shdr);
        fclose(fp);
        exit(1);
    }

    // 查找.symtab和.strtab所在的节区
    Elf32_Shdr *symtab_shdr = NULL, *strtab_shdr = NULL; 
    for (int i = 0; i < ehdr.e_shnum; i++)
    {
        char *name = shstrtab + shdr[i].sh_name;
        if (strcmp(name, ".symtab") == 0)
            symtab_shdr = &shdr[i];
        if (strcmp(name, ".strtab") == 0)
            strtab_shdr = &shdr[i];
    }

    if (!symtab_shdr || !strtab_shdr)
    {
        printf("ErrorL.symtab or .strtab not Found\n");
        free(shstrtab);
        free(shdr);
        fclose(fp);
        exit(1);
    }

    // 读取字符串表
    strtab_size = strtab_shdr->sh_size;
    strtab_data = malloc(strtab_size);
    if (!strtab_data)
    {
        printf("Error: Failed to allocate memory for strtab\n");
        free(shstrtab);
        free(shdr);
        fclose(fp);
        exit(1);
    }
    fseek(fp, strtab_shdr->sh_offset, SEEK_SET);
    if (fread(strtab_data, strtab_size, 1, fp) != 1)
    {
        printf("Error: Failed to read strtab\n");
        free(strtab_data);
        free(shstrtab);
        free(shdr);
        fclose(fp);
        exit(1);
    }

    // 读取符号表
    int sym_count = symtab_shdr->sh_size / sizeof(Elf32_Sym); 
    Elf32_Sym *symtab = malloc(symtab_shdr->sh_size);       
    if (!symtab)
    {
        printf("Error: Failed to allocate memory for symtab\n");
        free(strtab_data);
        free(shstrtab);
        free(shdr);
        fclose(fp);
        exit(1);
    }
    fseek(fp, symtab_shdr->sh_offset, SEEK_SET);
    if (fread(symtab, sizeof(Elf32_Sym), sym_count, fp) != sym_count)
    {
        printf("Error: Failed to read symtab\n");
        free(symtab);
        free(strtab_data);
        free(shstrtab);
        free(shdr);
        fclose(fp);
        exit(1);
    }

    func_count = 0;
    for (int i = 0; i < sym_count; i++)
    {
        
        if (ELF32_ST_TYPE(symtab[i].st_info) == STT_FUNC)
        {
            func_count++;
        }
    }

    func_symbols = malloc(func_count * sizeof(FuncSymbol));
    if (!func_symbols)
    {
        printf("Error: Failed to allocate memory for func_symbols\n");
        free(symtab);
        free(strtab_data);
        free(shstrtab);
        free(shdr);
        fclose(fp);
        exit(1);
    }
    int idx = 0; // 下标
    for (int i = 0; i < sym_count; i++)
    {
        if (ELF32_ST_TYPE(symtab[i].st_info) == STT_FUNC)
        {
            func_symbols[idx].name_offset = symtab[i].st_name;
            func_symbols[idx].value = symtab[i].st_value;
            func_symbols[idx].size = symtab[i].st_size;
            func_symbols[idx].call_count = 0;
            idx++;
        }
    }

    free(symtab);
    free(shstrtab);
    free(shdr);
    fclose(fp);

    Log("ftrace intialized with %d function symbols from %s", func_count, elf_file);
}

const char *addr_to_func(uint32_t addr)
{
    for (int i = 0; i < func_count; i++)
    {
        
        if (addr >= func_symbols[i].value && addr < func_symbols[i].value + func_symbols[i].size)
        {
            return strtab_data + func_symbols[i].name_offset;
        }
    }

    return "???";
}

uint32_t func_to_addr(const char *func_name)
{
    for (int i = 0; i < func_count; i++)
    {
        const char *name = strtab_data + func_symbols[i].name_offset;
        if (strcmp(name, func_name) == 0)
        {
            return func_symbols[i].value;
        }
    }
    return 0;
}

#include <cpu/cpu.h> 

void ftrace_call(uint32_t pc, uint32_t target_addr)
{
    const char *func_name = addr_to_func(target_addr);

    for (int i = 0; i < func_count; i++)
    {
        if (func_symbols[i].value == target_addr)
        {
            func_symbols[i].call_count++;
            break;
        }
    }
    bool is_memcpy = (strcmp(func_name, "memcpy") == 0);

    
    printf("0x%08x: ", pc);
    for (int i = 0; i < indent_level; i++)
    {
        printf("  ");
    }
    printf(" %-6s [%s@0x%08x]", "call", func_name, target_addr);



    if (is_memcpy)
    {

   
        uint32_t dest = R(10); // a0
        uint32_t src = R(11);  // a1
        uint32_t size = R(12); // a2

        // 分析地址对齐
        bool dest_aligned = (dest % 4 == 0); // 4 字节对齐
        bool src_aligned = (src % 4 == 0);
        int align_idx = 0;
        const char *alignment;

        if(dest_aligned && src_aligned)
        {
            align_idx = 0;
            alignment = "aligned";
        }else if(dest_aligned || src_aligned){
            align_idx = 1;
            alignment = "partically aligned";
        }else
        {
            align_idx = 2;
            alignment = "unaligned";
        }

        int length_idx;
        const char *length_category;

        if(size<256)
        {
            length_idx = 0;
            length_category = "short";
        }else if(size < 512)
        {
            length_idx = 1;
            length_category = "medium";
        }else
        {
            length_idx = 2;
            length_category = "long";
        }
        
        printf(" {memcpy: dest=0x%08x, src=0x%08x, size=%u, %s, %s}",dest, src, size, alignment, length_category);

        memcpy_stats[align_idx][length_idx].count++;
        memcpy_stats[align_idx][length_idx].total_size += size;
    }
    printf("\n");
    indent_level++;
}

void ftrace_ret(uint32_t pc)
{
    const char *func_name = addr_to_func(pc);

    if (indent_level > 0)
        indent_level--;

    printf("0x%08x: ", pc);

    for (int i = 0; i < indent_level; i++)
    {
        printf("  ");
    }

    printf(" %-6s [%s]\n", "ret", func_name);
}

void ftrace_print_stats()
{
    printf("\nFunction Call Statistics:\n");
    printf("Function Name\tAddress\t\tCall Count\n");
    for (int i = 0; i < func_count; i++)
    {
        const char *name = strtab_data + func_symbols[i].name_offset;
        printf("%s\t\t0x%08x\t%lu\n", name, func_symbols[i].value, func_symbols[i].call_count);
    }
}


void ftrace_call_memcpy_stats()
{
    printf("\tMemcpy 调用信息统计:\n");
    printf("对齐判断\t长度\t调用次数\t平均大小\n");
    for (int i = 0; i < 3;i++)
    {
        for (int j = 0; j < 3;j++)
            if (memcpy_stats[i][j].count > 0)
            {
                double avg_size = (memcpy_stats[i][j].total_size / memcpy_stats[i][j].count);
                printf("%s\t%s\t%lu\t%.2f\n", memcpy_stats[i][j].alignment, memcpy_stats[i][j].length, memcpy_stats[i][j].count, avg_size);
            }
    }
}
