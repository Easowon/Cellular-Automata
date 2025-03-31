// current compilation code
// gcc -o automata main.c update.c display.c string_handling.c input_handling.c

#include <stdio.h>
#include "string_handling.c"
#include "input_handling.c"
#include "error_handling.c"
#define true 1
#define false 0

int main(int argc, char *argv[]) {
    // flags
    unsigned total;
    unsigned step;
    unsigned lower;
    unsigned upper;
    int wrap = false;

    //int foo[] = {1,0,1,0,1,0,1,0,1};
    //display(foo, 3);

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
    }
    return 0;
}
