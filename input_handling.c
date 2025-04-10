#include <stdio.h>
#define true 1
#define false 0

unsigned str_length(char *str);
int get_flag_value(char *str, unsigned n);

int args_parser(char *argument) {
    if (argument[0] == '-' && argument[1] != '-') { // if the argument is a short flag
        unsigned arg_len = str_length(argument);
        if (argument[1] == 'w') {
            //printf("returned true\n");
            return true;
        }
        unsigned val = get_flag_value(argument, str_length(argument) - 3);
        printf("returned %d\n", val);
        return val;
    }

    if (argument[0] == '-' && argument[1] == '-') { // if the argument is a long flag
        //printf("is a long flag\n");
        if (argument[2] == 'w') {
            return true;
        }
        else if (argument[2] == 't') {
            unsigned val = get_flag_value(argument, str_length(argument) - 8);
            //printf("returned %d\n", val);
            return val;
        }
        else if (argument[2] == 's') {
            unsigned val = get_flag_value(argument, str_length(argument) - 7);
            //printf("returned %d\n", val);
            return val;
        }
        else if (argument[2] == 'l') {
            unsigned val = get_flag_value(argument, str_length(argument) - 8);
            //printf("returned %d\n", val);
            return val;
        }
        else if (argument[2] == 'u') {
            unsigned val = get_flag_value(argument, str_length(argument) - 8);
            //printf("returned %d\n", val);
            return val;
        }
    }
}