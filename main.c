// current compilation code
// gcc -o automata main.c

#include <stdio.h>
#include "string_handling.c"
#include "input_handling.c"
#include "display.c"
#include "update.c"
#define true 1
#define false 0

int main(int argc, char *argv[]) {
    // flags
    unsigned total;
    unsigned step;
    unsigned lower;
    unsigned upper;
    int wrap = false;
    int width = 11;
    int height;

    char board[10][10] = {{'\0'}};

    // input


    printf("number of args: %d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
        char *arg = argv[i];

        if (cmp_string(arg, "--wrap", 5) || cmp_string(arg, "-w", 2)) { // if argument is wrap
            wrap = true;
        }
        else if (cmp_string(arg, "--total=", 8) || cmp_string(arg, "-t=", 3)) { // if argument is total
            total = args_parser(arg);
        }
        else if (cmp_string(arg, "--step=", 7) || cmp_string(arg, "-s=", 3)) {
            step = args_parser(arg);
        }
        else if (cmp_string(arg, "--lower=", 8) || cmp_string(arg, "-l=", 3)) {
            lower = args_parser(arg);
        }
        else if (cmp_string(arg, "--upper=", 8) || cmp_string(arg, "-u=", 3)) {
            upper = args_parser(arg);
        }
        else if (cmp_string(arg,"0",1) || cmp_string(arg,"1",1)) {
            int x = 0;
            int y = 0;
            while (arg[x] != '\0') {
                if (arg[x] == '/') {
                    if (width == 11) {width = x;}
                    //printf("width %d\n", width);
                    y++;
                }
                else {
                    //printf("at (%d,%d), %c\n", x % width, y, arg[x]);
                    board[y][(x-y) % width] = arg[x];
                }
                x++;
            }
            height = y+1;
            //printf("%dx%d board\n", height,width);
        }
    }
    printf("wrap=%d, upper=%d, lower=%d\n", wrap, upper, lower);
    display(board, width, height);

    // simulation

    for (int i = 0; i < total; i++) {
        update(board, width, height, wrap, upper, lower);
        if (i % step == 0) {
            display(board, width, height);
            printf("\n");
        }
    }
    return 0;
}
