#ifndef __EXPR_H__
#define __EXPR_H__

#include<common.h>

extern void init_regex();
extern word_t expr(char *e, bool *success);
extern void cleanup_regex();

#endif