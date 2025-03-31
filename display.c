#include <stdio.h>
#define true 1
#define false 0

/*
Takes screen state as a parameter, then displays the state on the commandline.
*/ 
void display(int state[], unsigned width) {
    for (int i = 0; i < sizeof(state) / sizeof(state[0])-1; i++) {
        if (i % width == 0) {printf("\n");}
        printf("%d",state[i]);
    }
}