/* a1p4.c
    program 4
    By: Numan Mir (nmir@uoguelph.ca)
    Student ID: 1005381
*/
#include "tictactoe.h"
#include <stdlib.h>

int main(int argc, char *argv[]){ /*takes in command line argument representing an integer board number, calls debug to print out move, turn, winner, next possible moves, best_move and winner of the struct*/
	unsigned short us;

	us = atoi(argv[1]);

	debug2(us); /*second debug function used, so it does not interfere with a1p1*/

	return 0;
}
