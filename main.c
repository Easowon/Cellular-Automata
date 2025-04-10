// current compilation code
// gcc -o automata main.c

#include <stdio.h>
#include "string_handling.c"
#include "display.c"
#include "update.c"
#define true 1
#define false 0

int main(int argc, char *argv[]) {

    // flags
    int total = -1;
    int step = -1;
    int lower = -1;
    int upper = 9;
    int wrap = false;
    int width = 11;
    int height;

    char board[10][10] = {{'\0'}};

    // input

    for (int i = 0; i < argc; i++) {
        char *arg = argv[i];

        if (cmp_string(arg, "--wrap", 5) || cmp_string(arg, "-w", 2)) {
            wrap = true;
        }
        else if (cmp_string(arg, "--total=", 8) || cmp_string(arg, "-t=", 3)) {
            total = get_flag_value(arg);
        }
        else if (cmp_string(arg, "--step=", 7) || cmp_string(arg, "-s=", 3)) {
            step = get_flag_value(arg);
        }
        else if (cmp_string(arg, "--lower=", 8) || cmp_string(arg, "-l=", 3)) {
            lower = get_flag_value(arg);
        }
        else if (cmp_string(arg, "--upper=", 8) || cmp_string(arg, "-u=", 3)) {
            upper = get_flag_value(arg);
        }
        else if (cmp_string(arg,"0",1) || cmp_string(arg,"1",1)) {
            int x = 0;
            int y = 0;
            while (arg[x] != '\0') {
                if (arg[x] == '/') {
                    if (width == 11) {width = x;}
                    y++;
                }
                else {
                    board[y][(x-y) % width] = arg[x];
                }
                x++;
            }
            height = y+1;
        }
    }

    if (total < 0) {
        printf("Must provide a non-negative integer for total.");
        return 0;
    }
    if (step <= 0) {
        printf("Must provide a positive integer for step.\n");
        return 0;
    }
    if (lower < 0) {
        printf("Must provide a non-negative integer for lower.\n");
        return 0;
    }
    if (upper > 8) {
        printf("Must provide an integer no larger than 8 for upper.\n");
        return 0;
    }
    if (lower > upper) {
        printf("lower must be no larger than upper.\n");
        return 0;
    }

    display(board, width, height);

    // simulation

    for (int i = 1; i <= total; i++) {
        update(board, width, height, wrap, upper, lower);
        if (i % step == 0) {
            printf("\n");
            display(board, width, height);
        }
    }

    return 1;
}
