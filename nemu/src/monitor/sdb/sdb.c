/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include<memory/vaddr.h>


static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}

static int cmd_si(char *args)
{
  int num = 0;
  if(args!=NULL)
  {
  
  sscanf(args, "%d", &num);
  }
  else
  {
    num = 1;
  }
  cpu_exec(num);
  return 0;
}

static int cmd_q(char *args) {
  nemu_state.state = NEMU_QUIT;
  return -1;
}

static int cmd_help(char *args);

static int cmd_reg_display(char *args){

  if(args!=NULL)
  {
  if(strcmp(args,"r")==0)
  {
    isa_reg_display();
  }else if(strcmp(args,"w")==0)
  {
    printf_point();
  }
  return 0;
}else {
  printf("missing parameter (info r or w)\n");
  return 0;
}
}


static int cmd_scan_pmem(char *args)
{
  if(args!=NULL)
  {
    int n = 0;
    vaddr_t vadd;
    bool success = false;  
    sscanf(args, "%d", &n);

    char *get_vadd = strtok(args," ");

    get_vadd = strtok(NULL, " ");
    

    vadd = expr(get_vadd, &success); // 大于2147483648,小于 2281701375

    for (int i = 0; i < n;i++){
    word_t date;
    date=vaddr_read(vadd+i*4,4);
    printf("0x%x : %u\n ", vadd + i * 4, date);
  }

  return 0;
  }
  else
  {
    printf("missing parameter (x n expr)\n");
    return 0;
  }
}


static int cmd_p(char *args)
{
  if(args!=NULL)
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


static int cmd_t()
{

  FILE *fp = fopen("/home/zxj17/ysyx-workbench/nemu/tools/gen-expr/input", "r");
  if (fp == NULL)
  {
    printf("Failed to open input");
    return 0;
  }

  
  char line[65536] = {};

  while (fgets(line, sizeof(line), fp) != NULL)
  {
    

    line[strcspn(line, "\n")] = 0;

    if(strlen(line)==0)
    {
      break;
    }

    char *true_result = strtok(line, " ");
    char *expression  = strtok(NULL, "");

    bool success = false;
    uint32_t test_result = expr(expression, &success);
    uint32_t expect_result = atoi(true_result);

    if (success == false)
    {
      perror("failed to use expr");
    }
    else if (test_result == expect_result)
    {
      printf("expr:%-30s ,test: %10u ,expect: %10u ,test pass\n",expression,test_result,expect_result);
    }
    else
    {
      printf("expr:%-30s ,test: %10u != expect: %10u, test result wrong\n",expression, test_result, expect_result);
    }
    }
    fclose(fp);
  
  return 0;
}


int count_watchpoint = 0;
static int cmd_w(char *args)
{
  if(args !=NULL)
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
  if(args !=NULL)
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

extern void printf_branchstat();

static int cmd_sb(char *args)
{
  printf_branchstat();
  return 0;
}

static struct
{
  const char *name;
  const char *description;
  int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display information about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit NEMU", cmd_q},
    {"si", "Directly execute n times,(nemu:si n)", cmd_si},
    {"info", "Printf the value of reg (info r or w)", cmd_reg_display},
    {"x", "Scan the pmem (x n EXPR)", cmd_scan_pmem},
    {"p", "get expression value (p expr)", cmd_p},
    {"t", "test the expr (t)", cmd_t},
    {"w", " set watchpoint (w expr) ", cmd_w},
    {"d", "delete watchpoint (d NO)", cmd_d},
    {"st", "set mtrace range", cmd_st},
    {"sb", "look at the beq using times", cmd_sb},

    /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1; 
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
