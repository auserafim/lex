
compiler: lex.o gen.o compiler.o synt.o
	gcc -o compiler lex.o gen.o compiler.o synt.o -I. -g

tstLex: lex.o tst_lex.o
	gcc -o tstLexCompiler lex.o tst_lex.o -I. -g

run: 
	./compiler

compiler.o: compiler.c
	gcc -c -g compiler.c

lex.o: lex.c
	gcc -c -g lex.c

gen.o: gen.c
	gcc -c -g gen.c


tst_lex.o: tst_lex.c
	gcc -c -g tst_lex.c

# --- Limpeza ---
clean:
	rm -f *.o compiler tstLexCompiler
