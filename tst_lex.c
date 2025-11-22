

#include <stdio.h>
#include <stdlib.h>

#include "lex.h"
#include "struct_compiler.h"

type_token *lookahead;

int main() {
  int acept = false;

  initLex("entrada.txt");
  lookahead = getToken();

  // Processa todos os tokens a partir da entrada
  while (lookahead->tag != ENDTOKEN) {
    printf("Tag:   %d\n", lookahead->tag);
    printf("Token: %s\n\n", lookahead->lexema);

    if (lookahead->tag == ERROR)
      exit(1);

    lookahead = getToken();
  }
  printf("Tag:   %d\n", lookahead->tag);
  printf("Token: %s\n", lookahead->lexema);

  return 1;
}
