/* a1p2.c
    program 2
    By: Numan Mir (nmir@uoguelph.ca)
    Student ID: 1005381
*/
#include "tictactoe.h"
#include <stdio.h>

int main(){
	FILE *fp;
	int i = 0;
	strat strat1;
	strat buffer[1];
	strat1.best_move = -1;
	strat1.winner = ' ';
	buffer[0] = strat1;

	fp = fopen("strategyfile", "wb");

	for(i = 0; i < 19683; ++i){
		fwrite(buffer, sizeof(strat), 1, fp); /*writes blank strategyfile*/
	}
	fclose(fp);
}
