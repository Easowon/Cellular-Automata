/*
Takes the position of a cell and returns the next iteration.
*/
char update_cell(char state[10][10], int x, int y, int width, int height, int wrap, int upper, int lower) {
    int alive = 0;

    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dy == 0 && dx == 0) {continue;}

            // adjust coordinates such that they are always positive
            int new_y = (y+dy+height) % height; 
            int new_x = (x+dx+width) % width;

            if (state[new_y][new_x] == '1') {
                // if wrap is disabled, and the coordinates are out of bounds then skip it
                if (!wrap && ((y + dy < 0 || y + dy >= height) || (x + dx < 0 || x + dx >= width))) {
                    continue;
                }

                alive++;
            }
        }
    }

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

    // assign buffer to board
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            state[y][x] = buffer[y][x];
        }
    }
}