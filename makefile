# Makefile para Compilador (Versão simplificada)

# 1. Alvo Principal: Compila o compilador completo
compiler: lex.o gen.o compiler.o
	gcc -o compiler lex.o gen.o compiler.o -I. -g

# 2. Alvo de Teste Léxico (Mantido, pois é útil)
tstLex: lex.o tst_lex.o
	gcc -o tstLexCompiler lex.o tst_lex.o -I. -g

# --- Regras de Compilação dos Objetos (.c -> .o) ---

# [MODIFICADO] compiler.o é o novo módulo central (Contém main e sintaxe)
compiler.o: compiler.c
	gcc -c -g compiler.c

lex.o: lex.c
	gcc -c -g lex.c

gen.o: gen.c
	gcc -c -g gen.c

# [REMOVIDO] synt.o não é mais necessário para o alvo 'compiler'

tst_lex.o: tst_lex.c
	gcc -c -g tst_lex.c

# --- Limpeza ---
clean:
	rm -f *.o compiler tstLexCompiler
