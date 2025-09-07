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

#include "common.h"
#include<string.h>

extern word_t expr(char *e, bool *success);

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  char *str;
  word_t old_value;
  bool enable;
  char type; // b,m,n

  /* TODO: Add more members if necessary */

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;


void new_wp(char *expr_str)
{
  if(free_==NULL){

    printf("no free watchpoints");
    assert(0);
  }

    WP *wp = free_;
    wp->str =strdup(expr_str);

    
      bool success;
      wp->enable = true;

    char temp[3];
    

    for (int i=0; i < strlen(wp->str); i++)
    {
      if (wp->str[i] == 'c' && wp->str[i - 1] == 'p' && wp->str[i - 2] == '$')
      {
        temp[0] = '$';
        temp[1] = 'p';
        temp[2] = 'c';
        break;
      }
    }

    char *search_pc = strstr(wp->str, "0x");

    if (search_pc!=NULL && (strcmp(temp,"$pc")==0))
    {
      wp->type = 'b';
      sscanf(search_pc, "%x", &wp->old_value);
      printf("str:%s   pc:0x%08x\n",wp->str, wp->old_value);
    }
      else
      {
        wp->type = 'm';
        wp->old_value = expr(wp->str, &success);
      }
     free_ = wp->next;

    wp->next = head;
    head = wp;

    printf("watchpoint NO:%-4d type:%-6c set success\n", wp->NO, wp->type);
    return;
}
void free_wp(int NO)
{
  WP *wp = &wp_pool[NO];

  if (wp == NULL)
  {
    return;
  }

    if(head==wp){
    head = head->next;
    }else {
      WP *prev = head;
      while(prev && prev->next != wp)
      {
        prev = prev->next;
      }

      if(prev){
      prev->next = wp->next;
      }
    }
    free(wp->str);
    wp->enable = false;
    wp->old_value = 0;
    wp->type = 'n';
    wp->next = free_;
    free_ = wp;
    printf("Watchpoint %d deleted\n", wp->NO);

}

int monitor_point(uint32_t cpu_pc)
{
  WP *wp = head;
  while (wp != NULL)
  {

    if (wp->old_value == cpu_pc && wp->type == 'b')
    {
      
      printf("Hit an breakpoint NO:%-4d addr:0x%-5x\n", wp->NO, wp->old_value);
      
      return 1;
      continue;
    }

    bool sucess;
    word_t new_value = expr(wp->str, &sucess);

    if (new_value != wp->old_value && wp->type == 'm')
    {
      

      if (strcmp(wp->str, "$pc") == 0)
      {
        printf("Watchpoint %d triggered, %s changed from 0x%08x to 0x%08x\n", wp->NO, wp->str, wp->old_value, new_value);
      }
      else
      {
        printf("Watchpoint %d triggered, %s changed from %u to %u\n", wp->NO, wp->str, wp->old_value, new_value);
      }
      wp->old_value = new_value;
      return 1;
    }
    wp = wp->next;
  }
  return 0;
}

void printf_point()
{
  for (int i = 0; i < NR_WP; i++)
  {
    
    printf("Watchpoint %-5d   str:%-10s  old_value:%-10u  enable:%-4d  type:%-4c\n ", wp_pool[i].NO, wp_pool[i].str, wp_pool[i].old_value, wp_pool[i].enable, wp_pool[i].type);
  }
}

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    wp_pool[i].enable = false;
    wp_pool[i].old_value = 0;
    wp_pool[i].str = NULL;
    wp_pool[i].type = 'n';
  }

  head = NULL;
  free_ = wp_pool;
}
  

/* TODO: Implement the functionality of watchpoint */
