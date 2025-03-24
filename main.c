// current compilation code
// gcc -o automata main.c update.c display.c string_handling.c

#include <stdio.h>
#define true 1
#define false 0

void display(int *state[]);
int update_cell(int x, int y);
int update();
int str_length(char *str);
int get_flag_value(char *str, unsigned n);


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

        if (argv[i][0] == '-') { // if the argument is a short flag
            unsigned arg_len = str_length(argv[i]);
            switch (argv[i][1]) {
                case 'w':
                    wrap = true;
                    printf("wrap set to true\n");
                    break;
                case 't':
                    iterations = get_flag_value(argv[i], str_length(argv[i]) - 3);
                    printf("total set to %d\n", iterations);
                    break;
                case 's':
                    step = get_flag_value(argv[i], str_length(argv[i]) - 3);
                    printf("step set to %d\n", step);
                    break;
            }
        }
    }

    return 0;
}