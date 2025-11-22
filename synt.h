#ifndef SYNT_H
#define SYNT_H

#include "gen.h"
#include "lex.h"
#include "struct_compiler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variavel global lookahead (extern - definida em outro arquivo, no caso,
// compiler.c)
extern type_token *lookahead;
// Variaveis globais de suporte (se necessário)
extern char string[MAX_CHAR];

// Prototipos das funcoes do analisador sintatico
int match(int token_tag);
int factor();
int term();
int termR();
int expr();
int exprR();
int number(); // Note: Foi renomeada para 'number' para manter a consistencia
              // com o codigo

#endif // SYNT_H
