#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

/*
compares two strings and checks if they are equivalent up to character l
*/
int cmp_string(char *str, char *cmp, int length) {
    for (int i = 0; i < length; i++) {
        if (str[i] != cmp[i]) {
            return false;
        }
    }
    return true;
}


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
int get_flag_value(char *str, unsigned n) {
    unsigned str_l = str_length(str);
    //printf("len = %u\n", str_l);
    char new_str[n];

    for (int i = str_l-n; i < str_l; i++) {
        new_str[i - (str_l - n)] = str[i];
    }

    //printf("atoi(new_str) = %d\n", atoi(new_str));
    //printf("new_str = %s\n", new_str);
    return atoi(new_str);
}