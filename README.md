# Cellular Automata

A commandline simulator for Conways Game of Life with optional modifications.

Made for Assignment 1 of INFO1910.

Run `make` to compile program

## Usage

    ./automata required [wrap]

Example

    ./automata 011/100 -t=10 --step=1 -u=7 -l=2 

## Arguments

    REQUIRED (any order)
    -t=TOTAL, --total=TOTAL      Specifies total number of iterations to be performed
    -s=STEP, --step=STEP         Specifies when to output board state (iteration 0 is always output)
    -l=LOWER, --lower=LOWER      Specifies the minimum number of neighbors a cell must have to be alive next iteration 
    -u=UPPER, --upper=UPPER      Specifies the maximum number of neighbords a cell must have to be alive next iteration
                                 Cannot be less than LOWER.

    board                        A string which represents a valid board state, with rows being seperated by /'s
                                 Examples
                                 001/100/010
                                 000001/100000
                                 1/0/1/0
    
    OPTIONAL
    -w, --wrap                   If present, the program will execute in wrapping mode.
