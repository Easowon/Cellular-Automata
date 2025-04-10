#include <stdio.h>
#define true 1
#define false 0

/*
Takes the position of a cell and returns the next iteration.
*/
char update_cell(char state[10][10], int x, int y, int width, int height, int wrap, int upper, int lower) {
    int alive = 0;
    int seen[10][10] = {{0}};
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dy == 0 && dx == 0) {continue;}
            int new_y = (y+dy+height) % height;
            int new_x = (x+dx+width) % width;
            if (state[new_y][new_x] == '1') {
                //printf(" - (%d,%d) is alive\n", x+dx, y+dy);
                if (!wrap && ((y + dy < 0 || y + dy >= height) || (x + dx < 0 || x + dx >= width))) {
                    //printf(" -- out of bounds(%d,%d)? %d, %d\n", x+dx, y+dy, (x + dx < 0 || x + dx >= width), (y + dy < 0 || y + dy >= height));
                    continue;
                }
                if (seen[new_y][new_x] != 1) {
                    seen[new_y][new_x] = 0;
                    alive++;
                }
            }
        }
    }
    //printf("alive around (%d,%d) = %d\n", x, y, alive);
    if (alive <= upper && alive >= lower) {
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