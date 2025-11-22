#include "lex.h"
#include "synt.h"
#include <stdio.h>


int main(int argc, char *argv[]) {
  int acept = 0;
  char *nome_arquivo_entrada;
  printf("\nEntre com o nome do arquivo de teste: ");
  scanf("%s", nome_arquivo_entrada);

  printf("Iniciando Analise Sintatica no arquivo: %s...\n",
         nome_arquivo_entrada);

  initLex(nome_arquivo_entrada);

  lookahead = getToken();

  acept = expr();

  // Verifica se a cadeia pertence à linguagem
  if (acept) {
    printf("\t[SUCESSO] Cadeia PERTENCENTE à linguagem\n");
  } else {
    printf("\t[ERRO] Cadeia NÃO pertencente à linguagem\n");
  }

  return 0;
}
