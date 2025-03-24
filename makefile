all: automata

automata: main.c
	gcc -Wall -o automata main.c 