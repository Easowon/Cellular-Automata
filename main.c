// current compilation code
// gcc -Wall -o automata main.c update.c

#include <stdio.h>
#define true 1
#define false 0

/*
Takes screen state as a parameter, then displays the state on the commandline.
*/ 
void display(int state[]);

/*
Takes the position of a cell and returns the next iteration.
NOTE: DO NOT UPDATE IN PLACE, STORE IN AN INTERMEDIATE VARIABLE
*/
int update_cell(int x, int y);

/*
Takes the current state of the game and updates it to the next iteration  
*/
int update();

int main(int argc, char *argv[]) {

}