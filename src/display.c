#include <stdio.h>

/*
Takes board state as a parameter, then displays the state on the commandline.
*/ 
void display(char state[10][10], int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", state[y][x]);
        }
        printf("\n");
    }
}