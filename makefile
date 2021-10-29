all: main.c Codes/TAD_Patricia.c Codes/IndInverso.c Codes/menu.c Codes/ConversaoPalavras.c Codes/tst.c 
	gcc main.c -g Codes/TAD_Patricia.c Codes/IndInverso.c Codes/menu.c Codes/ConversaoPalavras.c Codes/tst.c -lm

run: a.out
	./a.out
            