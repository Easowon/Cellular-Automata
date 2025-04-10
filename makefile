all: automata

automata: main.c
	gcc -o automata main.c string_handling.c display.c update.c

