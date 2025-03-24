#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

/*
returns length of string
*/
unsigned str_length(char *str) {
    unsigned n = 0;
    while (str[n] != '\0') {
        n++;
    }
    return n;
}

/*
get the value for the flag
*/
unsigned get_flag_value(char *str, unsigned n) {
    unsigned str_l = str_length(str);
    //printf("len = %u\n", str_l);
    char new_str[n+1];

    for (unsigned i = str_l-n; i < str_l; i++) {
        new_str[i - (str_l - n)] = str[i];
    }

    //printf("atoi(new_str) = %d\n", atoi(new_str));
    //printf("new_str = %s\n", new_str);
    return atoi(new_str);
}