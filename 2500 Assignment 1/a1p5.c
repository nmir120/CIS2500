/* a1p5.c
    program 5
    By: Numan Mir (nmir@uoguelph.ca)
    Student ID: 1005381
*/
#include "tictactoe.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	char userName[100];
	char userSide;
	char userInput[10];
	struct strategy_struct strat;
	char b3[10] = "0000000000";
	char board[60];
	char wnr = ' '; 
	char usr;
	unsigned short us;
	FILE* fp;
	fp = fopen("strategyfile", "rb");
	printf("SHALL WE PLAY A GAME?\n\nPLEASE ENTER YOUR NAME: ");
	fgets(userName, 100, stdin);
	printf("\nGREETINGS %sWhich side would you like to play (X/0)? ", userName);
	scanf(" %c", &userSide);
	if(userSide == 'O'){
		printf("Ok, you will be O; I will be X.\n");
		usr = '1';
	}
	else if(userSide == 'X'){
		printf("Ok, you will be X; I will be O.\n");
		usr = '2';
	}
	boardfromb3(board, b3);
	printf("%s\n", board);
	us = b3tous(b3);
	while(wnr == ' '){ /*while there is no winner*/
		
		if(userSide == 'X') 
		{
			printf("Your turn; chose a move [0-8]: "); /*SHOULD SAY "CHOOSE" but assignment said to copy output EXACTLY from assignment page*/
			scanf("%s", userInput); 
			b3[userInput[0] - '0'] = get_turn(b3); /*sets board b3 to character of turn*/
			userSide = 'O';
		}
		else
		{
			fseek(fp, sizeof(struct strategy_struct)*b3tous(b3), SEEK_SET);
			fread(&strat, sizeof(struct strategy_struct), 1, fp);
			printf("My turn, my move is %d:\n", strat.best_move);
			b3[strat.best_move + '0' - '0'] = get_turn(b3); /*AI uses best move*/
			userSide = 'X';
		}
		boardfromb3(board, b3);
		printf("%s\n", board);
		us = b3tous(b3);
		wnr = winner(us);
	}
	if(wnr == '0'){ /*if no winner at the end*/
		printf("The game is a tie.\n");
	}
	else{ /*AI wins*/
		printf("I won!\nA STRANGE GAME.\nTHE ONLY WINNING MOVE IS\nNOT TO PLAY.\n");
	}

}
