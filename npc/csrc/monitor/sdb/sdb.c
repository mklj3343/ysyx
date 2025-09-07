#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include <memory/vaddr.h>


static int is_batch_mode = false;

static char* rl_gets(){
    static char *line_read = NULL;

    if(line_read){
        free(line_read);
        line_read = NULL;
    }

    line_read = readline("(npc) ");
    if(line_read && *line_read){
        add_history(line_read);
    }

    return line_read;
}

static int cmd_help(char *args);

static int cmd_q(char *args){
    npc_state.state = NPC_QUIT;
    return -1;
}

static int cmd_c(char *args){
    cpu_exec(-1);
    
    return 0;
}

static int cmd_si(char *args){
    int num = 0;
    if(args != NULL){
        sscanf(args, "%d", &num);
    }else{
        num = 1;
    }


    cpu_exec(num);
    return 0;
}


static int cmd_info(char *args){
    if(args != NULL){
        if(strcmp(args,"r") == 0)
        {
           // cmd_reg_info(args);
           // printf("$pc: 0x%08x\n", cpu.pc);
           isa_reg_display();
        }
    }/*else if(strcmp(args,"w") == 0){

    }else{
        printf("missing parameter (info r or w)\n");
    }*/
    return 0;
}

static int cmd_p(char *args)
{
    if (args != NULL)
    {

        word_t num_exp = 0;
        bool success = false;
        num_exp = expr(args, &success);
        printf("%u\n", num_exp);

        return 0;
    }
    else
    {
        printf("missing parameter (p expr)\n");
        return 0;
    }
}
static int cmd_x(char *args)
{


    if (args != NULL )
    {
        int n = 0;
        vaddr_t vadd;
        bool success = false;
        sscanf(args, "%d", &n);

        char *get_vadd = strtok(args, " ");

        get_vadd = strtok(NULL, " ");

        vadd = expr(get_vadd, &success); // 大于2147483648,小于 2281701375

        for (int i = 0; i < n; i++)
        {
            word_t date;
            date = vaddr_read(vadd + i * 4, 4);
            printf("0x%08x : 0x%08x\n ", vadd + i * 4, date);
        }

        return 0;
    }
    else
    {
        printf("missing parameter (x n expr)\n");
        return 0;
    }
}

int count_watchpoint = 0;
static int cmd_w(char *args)
{
    if (args != NULL)
    {
        new_wp(args);

        count_watchpoint++;
        printf("you have set %d watchpoint\n", count_watchpoint);
        return 0;
    }
    else
    {
        printf("missing parameter (w expr)\n");
        return 0;
    }
}

static int cmd_d(char *args)
{
    if (args != NULL)
    {

        int NO = atoi(args);

        free_wp(NO);
        printf("delete watchpoint success\n");
        count_watchpoint--;

        return 0;
    }
    else
    {
        printf("missing parameter (d NO)\n");
        return 0;
    }
}

static int cmd_st(char *args)
{
    vaddr_t start = 0x0;
    vaddr_t end = 0xfffffff;
    sscanf(args, "%x %x", &start, &end);
    mtrace_set_range(start, end);
    return 0;
}

static struct 
{
    const char *name;
    const char *description;
    int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display information about all supported commands", cmd_help},
    {"q", "Exit NPC", cmd_q},
    {"si", "Directly execute n times,(npc: si n)", cmd_si},
    {"c", "Continue the execution of the program", cmd_c},
    {"info", "Display all the reg", cmd_info},
    {"p", "get expression value (p expr)", cmd_p},
    {"x", "Scan the pmem (x n EXPR)", cmd_x},
    {"w", "set watchpoinnt (w expr)", cmd_w},
    {"d", "delete watchpoint (d NO)", cmd_d},
    {"st", "set mtrace range", cmd_st},

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args){
    char *arg = strtok(NULL, " ");
    int i;

    if (arg == NULL){
        for (i = 0; i < NR_CMD; i++){
            printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        }
    }else {
        for (i = 0; i < NR_CMD;i++){
            if(strcmp(arg,cmd_table[i].name) == 0){
                printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
                return 0;
            }
        }

        printf("Unkonwn command '%s'\n", arg);
    }

    return 0;
}


void sdb_set_batch_mode()
{
    is_batch_mode = true;
}

void sdb_mainloop()
{
    if (is_batch_mode)
    {
        cmd_c(NULL);
        return;
    }

    for (char *str; (str = rl_gets()) != NULL;)
    {
        char *str_end = str + strlen(str);


        char *cmd = strtok(str, " ");
        if (cmd == NULL)
        {
            continue;
        }

        char *args = cmd + strlen(cmd) + 1;
        if (args >= str_end)
        {
            args = NULL;
        }

#ifdef CONFIG_DEVICE
        extern void sdl_clear_event_queue();
        sdl_clear_event_queue();
#endif

        int i;
        for (i = 0; i < NR_CMD; i++)
        {
            if (strcmp(cmd, cmd_table[i].name) == 0)
            {
                if (cmd_table[i].handler(args) < 0)
                {
                    return;
                }
                break;
            }
        }

        if (i == NR_CMD)
        {
            printf("Unknown command '%s'\n", cmd);
        }
    }
}
