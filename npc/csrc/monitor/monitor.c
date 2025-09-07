#include <isa.h>
#include <memory/paddr.h>
#include<verilog_init.h>
#include<disasm.h>
#include<getopt.h>
#include<difftest.h>

void init_rand();
void init_log(const char *log_file);
void init_mem();
//void init_difftest(char *ref_so_file, long img_size, int port);
void init_device();
void init_sdb();
void init_regex();
void init_wp_pool();
void init_disasm_llvm();

static void welcome()
{
    Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
    IFDEF(CONFIG_TRACE, Log("If trace is enabled, a log file will be generated "
                            "to record the trace. This may lead to a large log file. "
                            "If it is not necessary, you can disable it in menuconfig"));
    Log("Build time: %s, %s", __TIME__, __DATE__);
    printf("Welcome to %s-npc!\n", ANSI_FMT(str(riscv32), ANSI_FG_YELLOW ANSI_BG_RED));
    printf("For help, type \"help\"\n");
}

#ifndef CONFIG_TARGET_AM
#include <getopt.h>

void sdb_set_batch_mode();

static char *diff_so_file = NULL;
static char *img_file = NULL;
static int difftest_port = 1234;//假接口，实际上不需要
static char *log_file = NULL;

static long load_img(){
    if(img_file == NULL){
        Log("No image is given. Use the default build-in image.");
        return 4096;
    }

    FILE *fp = fopen(img_file, "rb");
    Assert(fp, "Can not open %s", img_file);

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);


    fseek(fp, 0, SEEK_SET);
    int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
    assert(ret == 1);
    
    fclose(fp);
    return size;
}

static int parse_args(int argc,char *argv[]){
    const struct option table[] = {
        {"batch",no_argument,NULL,'b'},
        {"log",required_argument,NULL,'l'},
        {"diff",required_argument,NULL,'d'},
        {"port",required_argument,NULL,'p'},
        {"help",no_argument,NULL,'h'},
        {0,0,NULL,0},
        
    };
    int o;
    while((o = getopt_long(argc, argv,"-bhl:d:p:",table,NULL)) != -1){

        switch(o){
            case 'b':
                sdb_set_batch_mode();break;
            case 'p':
                sscanf(optarg, "%d", &difftest_port);break;    
            case 'l':
                log_file = optarg;break;    
            case 'd':
                //printf("344\n");
                diff_so_file = optarg;
               // printf("222%s\n", optarg);
                break;
            case 1:
                img_file = optarg;
                printf("%s\n", optarg);
                return 0;
            default:
                printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
                printf("\t-b,--batch              run with batch mode\n");
                printf("\t-l,--log=FILE           output log to FILE\n");
                printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
                printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
                //printf("\t-e,--elf=FILE           load ELF file for ftrace\n");
                printf("\n");
                exit(0);
            }
    }


    return 0;
}



void init_monitor(int argc, char *argv[])
{

    parse_args(argc, argv);
    
    init_rand();

    long img_size = load_img();

     init_regex();
     init_wp_pool();
     init_disasm_llvm();

     init_verilog(argc, argv);
     // init_sdb();
     init_mem();

     IFDEF(CONFIG_DEVICE, init_device());

     

     init_difftest(diff_so_file, img_size, difftest_port);

     welcome();
}

#else // CONFIG_TARGET_AM
static long load_img()
{
    extern char bin_start, bin_end;
    size_t size = &bin_end - &bin_start;
    Log("img size = %ld", size);
    memcpy(guest_to_host(RESET_VECTOR), &bin_start, size);
    return size;
}

void am_init_monitor()
{
    init_rand();
    init_mem();
    init_isa();
    load_img();
    IFDEF(CONFIG_DEVICE, init_device());
    welcome();
}
#endif