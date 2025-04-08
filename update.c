#include <stdio.h>
#define true 1
#define false 0

/*
Takes the position of a cell and returns the next iteration.
NOTE: DO NOT UPDATE IN PLACE, STORE IN AN INTERMEDIATE VARIABLE
*/
char update_cell(char state[10][10], int x, int y, int width, int height, int wrap, int upper, int lower) {
    int alive = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dy + dx == 0) {continue;}
            printf("(%d, %d) is %c\n", y+dy, x+dx, state[(x+dx) % width][(y+dy) % height]);
            if (state[(y+dy) % height][(x+dx) % width] == '1') {
                alive++;
            }
        }
    }
    if (alive <= upper || alive >= lower) {
        return '1';
    }
    return '0';
}

/*
Takes the current state of the game and updates it to the next iteration  
*/
void update(char state[10][10], int width, int height, int wrap, int upper, int lower) {
    char buffer[10][10];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            buffer[y][x] = update_cell(state, x, y, width, height, wrap, upper, lower);
        }
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            state[y][x] = buffer[y][x];
        }
    }
}