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

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
extern word_t vaddr_read(vaddr_t addr, int len);

enum
{
  TK_NOTYPE = 256,
  TK_EQ = 257,
  TK_LEFTBLANK = 258,
  TK_RIGHTBLANK = 259,
  TK_NEQ = 261, // 不相等
  TK_HEX = 262, // 16进制数
  TK_REG = 263,
  TK_AND = 264,
  TK_DEREF = 265, // 解引用
  TK_DECIMAL = 260,//十进制数

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

    /* TODO: Add more rules.
     * Pay attention to the precedence level of different rules.
     */

    {" +", TK_NOTYPE}, // spaces
    {"\\+", '+'},      // plus
    {"-", '-'},
    {"\\*", '*'},
    {"\\/", '/'},
    {"==", TK_EQ},         // equal
    {"\\(", TK_LEFTBLANK}, // blank
    {"\\)", TK_RIGHTBLANK},
    {"!=", TK_NEQ},
    {"&&", TK_AND},
    {"0x[0-9a-fA-F]+", TK_HEX},
    {"\\$[a-z0-9]+", TK_REG},
    {"[0-9]+", TK_DECIMAL},
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];//msg表示信息
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[65536] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

       // Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
         //  i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        if (nr_token < 65536)
        {
          
          tokens[nr_token].type = rules[i].token_type;
          
          if (substr_len < 32)
          {
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
          }
          else
          {
            strncpy(tokens[nr_token].str, substr_start, 31);
            tokens[nr_token].str[31] = '\0';
          }
        

          /* TODO: Now a new token is recognized with rules[i]. Add codes
           * to record the token in the array `tokens'. For certain types
           * of tokens, some extra actions should be performed.
           */
          
          switch (rules[i].token_type)
          {
          case TK_NOTYPE:break;  
          default:
            nr_token++;break;
            
          
        }
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

//括号检查
static bool check_parentheses(int p,int q)
{
  if(p>=q) return false;

    if(tokens[p].type !=TK_LEFTBLANK || tokens[q].type != TK_RIGHTBLANK) return false;

    int count = 0;
    for (int i = p; i <= q;i++){
      if(tokens[i].type==TK_LEFTBLANK)
        {
          count++;
        }else if(tokens[i].type==TK_RIGHTBLANK)
          count--;

      if(count<0)
      return false;
    }
    return count==0;
}


//主运算符位置
static int find_main_operator(int p,int q)
{
  int level = 0;
  int op_pos = -1; //主操作地址
  int min_priority = 100;

  for (int i = p; i <= q;i++){
    if(tokens[i].type==TK_LEFTBLANK)
      level++;
      else if(tokens[i].type==TK_RIGHTBLANK)
        level--;
        else if(level==0){
          int prority = 0;
          switch(tokens[i].type)
          {
            case TK_AND:prority = 1;break;
            case TK_EQ:
            case TK_NEQ:prority = 2;break;
            case '+':
            case '-':
              prority = 3;break;
              case '*':
              case '/':
                prority = 4;break;
            default: continue;
              }

              if(prority<=min_priority){
                min_priority = prority;
                op_pos = i;
              }
        }
  }

  return op_pos;
}


//递归求值
static u_int32_t eval(int p,int q,bool *success)
{
  if(p>q)
  {
    *success = false;
    return 0;
  }

  if(p==q)
  {
    if(tokens[p].type==TK_DECIMAL)
    {
      return atoi(tokens[p].str);

    }else if(tokens[p].type==TK_HEX)
    {
      return strtoul(tokens[p].str, NULL, 16);//转换成16进制
    }else if(tokens[p].type==TK_REG)
    {
      bool reg_success;
      word_t val = isa_reg_str2val(tokens[p].str + 1, &reg_success);

      if(reg_success==0)
        *success = false;

      return val;
    }

    *success = false;
    return 0;

  }

  if(check_parentheses(p,q))
  {
    return eval(p + 1, q - 1, success);
  }


  if(tokens[p].type==TK_DEREF)
  {
    u_int32_t addr = eval(p + 1, q,success);
    if(*success == 0)
      return 0;

    return vaddr_read(addr, 4);
  }

  int op = find_main_operator(p, q);
  if(op==-1)
  {
    *success = false;
    return 0;
  }

  word_t val1 = eval(p, op - 1, success);
    if(!*success)
      return 0;

  word_t val2 = eval(op + 1, q, success);
    if(!*success)
      return 0;

   switch(tokens[op].type)
   {
    case '+':
      return val1 + val2;
    case '-':
      return val1 - val2;
    case '*':
      return val1 * val2;
    case '/':
      if(val2==0)
      {
        *success = false;
        return 0;
      }
      return val1 / val2;

    case TK_EQ:
      return val1 == val2;
    case TK_NEQ:
      return val1 != val2;
    case TK_AND:
      return val1 && val2;

      default:
        *success = false;
        return 0;
      }
}

void cleanup_regex()
{
  for (int i = 0; i < NR_REGEX; i++)
  {
    regfree(&re[i]);
  }
  
}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  for (int i = 0; i < nr_token;i++)
  {
    if(tokens[i].type=='*' && 
    (i==0 || 
      (tokens[i-1].type != TK_DECIMAL &&
        tokens[i-1].type != TK_HEX && 
      tokens[i-1].type != TK_REG)))
      {
        tokens[i].type = TK_DEREF;
      }
  }

    *success = true;
  return eval(0, nr_token - 1, success);
  /* TODO: Insert codes to evaluate the expression. */
    
}



