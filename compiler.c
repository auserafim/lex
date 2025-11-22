#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lex.h"
#include "struct_compiler.h"
#include "synt.h" // Importa expr()

// --- DEFINIÇÃO DAS VARIÁVEIS GLOBAIS ---
// Elas são definidas aqui (o local real onde nascem) e usadas como 'extern' em
// outros arquivos.
type_token *lookahead;
char string[MAX_CHAR];

/**
 * @brief Funcao principal (main) do compilador
 * * @return int
 */
int main(int argc, char *argv[]) {
  int acept = 0;
  char *nome_arquivo_entrada; // Variável para armazenar o nome do arquivo

  if (argc < 2) {
    // Se o usuário não fornecer um arquivo, usamos "entrada.txt" como padrão.
    printf("Uso: %s <arquivo_opcional>\n", argv[0]);
    nome_arquivo_entrada = "entrada.txt"; // [MODIFICADO] Nome do arquivo padrão
  } else {
    // Se o usuário fornecer um argumento, usamos o argumento.
    nome_arquivo_entrada = argv[1];
  }

  printf("Iniciando Analise Sintatica no arquivo: %s...\n",
         nome_arquivo_entrada);

  // 1. Inicializa o Lexico com o nome do arquivo
  initLex(nome_arquivo_entrada);

  // 2. Carrega o primeiro token
  lookahead = getToken();

  // 3. Chama a função inicial do analisador sintático
  acept = expr();

  // Verifica se a cadeia pertence à linguagem
  if (acept) {
    printf("\t[SUCESSO] Cadeia PERTENCENTE à linguagem\n");
  } else {
    printf("\t[ERRO] Cadeia NÃO pertencente à linguagem\n");
  }

  return 0;
}
