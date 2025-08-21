CC = gcc

VPATH = src # tells make to look in src for prereq files
SRC = main.c string_handling.c display.c update.c

all: automata

automata: $(SRC)
	$(CC) -Isrc -o $@ $^
# gcc [-I<dir>] [-o outfile] infiles 
# -I includes <dir> in search (in this case src/)
# $@ specifies target (automata) $^ specifies prerequisites (main.c ... update.c)

clean:
	rm -f automata