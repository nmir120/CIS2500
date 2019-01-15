
/* a1p1.c
    program 1
    By: Numan Mir (nmir@uoguelph.ca)
    Student ID: 1005381
*/
#include "tictactoe.h"
#include <stdlib.h>

int main(int argc, char *argv[]){ /*takes in command line argument representing an integer board number, calls debug to print out move, turn, winner, and next possible moves*/
	unsigned short us;

	us = atoi(argv[1]);  

	debug(us);

	return 0;
}
