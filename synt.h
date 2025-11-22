#ifndef SYNT_H
#define SYNT_H

#include "gen.h"
#include "lex.h"
#include "struct_compiler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern type_token *lookahead;
// extern char string[MAX_CHAR];

int match(int token_tag);
int factor();
int term();
int termR();
int expr();
int exprR();
int number();
#endif // SYNT_H
