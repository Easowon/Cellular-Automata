#include <stdio.h>
#define true 1
#define false 0

unsigned str_length(char *str);
unsigned get_flag_value(char *str, unsigned n);

unsigned args_parser(char *argument) {
    if (argument[0] == '-' && argument[1] != '-') { // if the argument is a short flag
        unsigned arg_len = str_length(argument);
        if (argument[1] == 'w') {
            //printf("returned true\n");
            return true;
        }
        unsigned val = get_flag_value(argument, str_length(argument) - 3);
        //printf("returned %d\n", val);
        return val;
    }
}