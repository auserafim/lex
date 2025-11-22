/**
 * @file synt.c
 * @author Prof. Ivairton M. Santos - UFMT - Computacao
 * @brief Implementacao do analisador sintatico (Descendente Recursivo)
 * @version 0.2
 * @date 2021-11-24
 */

#include "synt.h" // Importa protótipos e extern lookahead
#include "gen.h"  // Garante o acesso às funcoes de geracao de codigo
#include "lex.h"  // Garante o getToken

type_token *lookahead;
int number();

/**
 * @brief Verifica se o proximo caracter (a frente) na cadeia eh o esperado
 */
int match(int token_tag) {
  if (lookahead->tag == token_tag) {
    lookahead = getToken(); // Pega o proximo token por meio do lexico
    return true;
  }
  printf("Erro Sintatico: Esperado token %d (Ex: '+', '*') mas encontrado tag "
         "%d (Token: %s)\n",
         token_tag, lookahead->tag, lookahead->lexema);
  return false;
}

/**
 * @brief Regra de derivacao da gramatica: TERM
 */
int term() {
  if (factor() && termR())
    return true;
  return false;
}

/**
 * @brief Regra de derivacao da gramatica: EXPR (Função inicial da sintaxe)
 */
int expr() {
  if (term() && exprR())
    return true;
  return false;
}

/**
 * @brief Regra de derivacao da gramatica: NUMBER
 */
int number() {
// Definimos MAX_TOKEN em struct_compiler.h (assumindo um valor razoável)
#ifndef MAX_TOKEN
#define MAX_TOKEN 100
#endif

  char aux_lexema[MAX_TOKEN];

  if (lookahead) {
    strcpy(aux_lexema, lookahead->lexema);
  } else {
    return false;
  }

  if (match(NUM)) {
    genNum(aux_lexema);
    return true;
  }
  return false;
}

/**
 * @brief Regra de derivacao da gramatica: EXPRR
 */
int exprR() {
  int test1, test2;
  if (lookahead->tag == PLUS) {
    test1 = match(PLUS);
    test2 = term();
    genAdd();
    if (test1 && test2)
      return exprR();
    return false;

  } else if (lookahead->tag == MINUS) {
    test1 = match(MINUS);
    test2 = term();
    genSub();
    if (test1 && test2)
      return exprR();
    return false;
  }
  return true; // Vazio (epsilon)
}

/**
 * @brief Regra de derivacao da gramatica: FACTOR
 */
int factor() {
  if (number())
    return true;
  return false;
}

/**
 * @brief Regra de derivacao da gramatica: TERMR
 */
int termR() {
  int test1, test2;

  if (lookahead->tag == MULT) {
    test1 = match(MULT);

    if (test1 && !factor()) {
      printf("ERRO SINTATICO (TERM_R): Esperado um FATOR "
             "(numero/identificador) apos o operador de multiplicacao (*).\n");
      return false;
    }

    genMulti();

    if (test1) {
      if (termR()) {
        return true;
      } else {
        return false;
      }
    }
    return false;

  } else if (lookahead->tag == DIV) {
    test1 = match(DIV);

    if (test1 && !factor()) {
      printf("ERRO SINTATICO (TERM_R): Esperado um FATOR "
             "(numero/identificador) apos o operador de divisao (/).\n");
      return false;
    }

    genDiv();

    if (test1) {
      if (termR()) {
        return true;
      } else {
        return false;
      }
    }

    return false;
  }

  return true; // vazio
}
