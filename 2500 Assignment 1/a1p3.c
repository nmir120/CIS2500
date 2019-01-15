/* a1p3.c
    program 3
    By: Numan Mir (nmir@uoguelph.ca)
    Student ID: 1005381
*/
#include "tictactoe.h"
#include <stdlib.h>

int main(int argc, char *argv[]){ /*takes an integer command-line argument reperesenting the move number*/
	unsigned short us;
	unsigned short nxt;
	FILE *fp;
	strat strat1;
	strat strat2;
	char wnr;
	char b3[10];

	int i = 0;
	char j = '0';
	fp = fopen("strategyfile", "rb+");

	us = atoi(argv[1]); 
	for(i = 0; i < 19683; ++i){ /*loops over all possible boards*/
		strat1.winner = ' ';
		b3fromus(b3, i);
		if((get_move(b3)-'0') == us){ /*finds boards that matches move number*/
			wnr = winner(i);
			if(wnr != ' '){ /*if there is a winner, sets approprate winner in struct variable*/
				strat1.winner = wnr;
				strat1.best_move = -1;
				set_record(fp, i, strat1); 
			}
			else{
				for(j = '0'; j < '9'; ++j){ /*if no winner, looks at all possible moves*/
					nxt = next(i, j);
					if(nxt != 0){
						get_record(fp, nxt, &strat2);
						if(strat2.winner == get_turn(b3)){ /*if move leads to board whos winner value matches current players turn*/
							strat1.winner = strat2.winner; /*set winner to current player*/
							strat1.best_move = j - '0'; /*set best move to move that lead to board*/
							break;
						}
						else if((strat2.winner == '0') && (strat1.winner != get_turn(b3))){ /*if no winning move*/
							strat1.winner = '0'; /*set winner to tie*/
							strat1.best_move = j - '0';
						}

					}	
				}
				if(strat1.winner == ' '){ /*if no winning or tying moves*/
					strat1.winner = '3' - (get_turn(b3) - '0'); /*sets winner value to opponent */
					for(j = '9'; j > '0'; --j){
						nxt = next(i, j);
						if(nxt != 0){
							strat1.best_move = j - '0'; /*set best move to last legal move*/
							break;
						}
					}
				}

			}

			set_record(fp, i, strat1); 
		}
		
	}

	fclose(fp);
	return 0;
}
