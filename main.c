// current compilation code
// gcc -o automata main.c update.c display.c string_handling.c input_handling.c

#include <stdio.h>
#define true 1
#define false 0

void display(int *state[]);
int update_cell(int x, int y);
int update();
unsigned args_parser(char *argument);

int main(int argc, char *argv[]) {
    // flags
    unsigned iterations;
    unsigned step;
    unsigned lower;
    unsigned upper;
    int wrap = false;

    printf("number of args: %d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
        switch (argv[i][1]) {
            case 'w':
                wrap = args_parser(argv[i]);
                break;
            case 't':
                iterations = args_parser(argv[i]);
                break;
            case 's':
                step = args_parser(argv[i]);
                break;
            case 'l':
                lower = args_parser(argv[i]);
                break;
            case 'u':
                upper = args_parser(argv[i]);
                break;
        }
        


    }

    return 0;
}