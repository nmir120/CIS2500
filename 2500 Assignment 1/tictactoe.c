
/* tictactoe.c
    Tictactoe file.
    By: Numan Mir (nmir@uoguelph.ca)
    Student ID: 1005381
*/
#include "tictactoe.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


unsigned short b3tous(char b3[10]) /*takes in base3 format of board, converts and sends back unsigned short format*/
{
	unsigned short us = 0;
	int i;
	int value = 1;
	for(i = 8; i >=0; --i){
		us += (b3[i] - '0') * value; /*multiplied by b3 column*/
		value = value * 3; /*column multiplied by 3 each loop to move on to next column*/
	}
    return us;
}

void b3fromus(char b3[10], unsigned short us) /*takes in unsigned short and base3 variable, converts us to b3*/
{
	int i;
	for(i = 8; i >= 0; --i){
		b3[i] = '0' + (us%3);
		us = us/3;
	}
}

void debug(unsigned short us){ /*testing function*/
	char b3[10];
	char board[60];
	char pos = '0';
	printf("Board number: %d\n",  us);
	b3fromus(b3, us);
	printf("Board b3: %9s\n", b3);
	printf("Board pic:\n");
	us = b3tous(b3);
	boardfromb3(board, b3);
	printf("%s\n", board); 
	boardtob3(b3, board);
	printf("Move: %c\n", get_move(b3));
	printf("Turn: %c\n", get_turn(b3));
	printf("Winner: %c\n", winner(us));
	for(pos = '0'; pos < '9'; ++pos){
		printf("%d -> %d\n", pos - '0', next(us, pos));
	}

}
void debug2(unsigned short us){ /*second testing function for a1p4, so it doesn't interfere with a1p1*/
	char b3[10];
	char board[60];
	char pos = '0';
	strat record;
	FILE *fp;
	printf("Board number: %d\n",  us);
	b3fromus(b3, us);
	printf("Board b3: %9s\n", b3);
	printf("Board pic:\n");
	us = b3tous(b3);
	boardfromb3(board, b3);
	printf("%s\n", board); /* print board here or in boardfromb3? */
	boardtob3(b3, board);
	printf("Move: %c\n", get_move(b3));
	printf("Turn: %c\n", get_turn(b3));
	printf("Winner: %c\n", winner(us));
	fp = fopen("strategyfile", "rb");
	get_record(fp, us, &record);
	printf("best_move = %d, winner = %c\n", record.best_move, record.winner);
	for(pos = '0'; pos < '9'; ++pos){ /*prints all next boards using all positions*/
		printf("%d -> %d\n", pos - '0', next(us, pos)); 
	}

	
}

void get_record(FILE *fp, unsigned short us, struct strategy_struct *record){ /*reads us into a struct variable of fp*/
	fseek(fp, us*sizeof(struct strategy_struct), SEEK_SET);
	fread(record, sizeof(struct strategy_struct), 1, fp);
}
void set_record(FILE* fp, unsigned short us, struct strategy_struct record){ /*writes us into a struct variable of fp*/
	fseek(fp, us*sizeof(struct strategy_struct), SEEK_SET);
	fwrite(&record, sizeof(struct strategy_struct), 1, fp);
}

void boardfromb3(char board[60], char b3[10]){ /*takes in a b3 value of a board, and a board string, places Xs and Os on board accordingly*/
	int piece = 0;
	strcpy(board, "   |   |   \n---+---+---\n   |   |   \n---+---+---\n   |   |   \0");
	for(piece = 0; piece < 9; ++piece){
		switch(b3[piece]){
			case '2':
			board[((piece*4)+1) + ((piece/3)*12)] = 'X';
			break;
			case '1':
			board[((piece*4)+1) + ((piece/3)*12)] = 'O';
			break;
			case '0':
			board[((piece*4)+1) + ((piece/3)*12)] = ' ';
			break;
			default:
			fprintf(stderr, "Error: bad value in b3\n");
			exit(-1);
			break;
		}
	}
}

void boardtob3(char b3[10], char board[60]){ /*takes in b3 value of board and a board string, places 2s, 1s, and 0s accordingly to pieces on board*/
	int piece = 0;
	for(piece = 0; piece < 9; ++piece){
		switch(board[((piece*4)+1) + ((piece/3)*12)]){
			case 'X':
			b3[piece] = '2';
			break;
			case 'O':
			b3[piece] = '1';
			break;
			case ' ':
			b3[piece] = '0';
			break;
			default:
			fprintf(stderr, "Error: bad value in b3\n");
			exit(-1);
			break;
		}
	}
}

char get_move(char b3[10]){ /*takes in b3 format of board, counts how many 0s to determine how many moves have been made, returns number*/
	char move = '9';
	int i = 0;
	for(i = 0; i < 9; ++i){
		if(b3[i] == '0'){
			move--;
		}
	}
	return move;
}

char get_turn(char b3[10]){ /*takes in b3 board and returns whos turn it is*/
	int move;
	char turn;
	move = get_move(b3) - '0';
	if(move % 2 == 0){ /*if move number is divisible by 2, must be X's turn*/
		turn = '2';
	}
	else{ /*else, O's turn*/
		turn = '1';
	}
	return turn;
}

char winner(unsigned short us){ /*takes us format of board, returns winner or tie */
	char b3[10];
	char winner = ' ';
	char move = '\0';
	b3fromus(b3, us);
	move = get_move(b3);

	
	/* X is winner */
	if(b3[0] == '2' && b3[3] == '2' && b3[6] == '2'){
		winner = '2';
	}
	if(b3[0] == '2' && b3[1] == '2' && b3[2] == '2'){
		winner = '2';
	}
	if(b3[2] == '2' && b3[5] == '2' && b3[8] == '2'){
		winner = '2';
	}
	if(b3[6] == '2' && b3[7] == '2' && b3[8] == '2'){
		winner = '2';
	}
	if(b3[1] == '2' && b3[4] == '2' && b3[7] == '2'){
		winner = '2';
	}
	if(b3[3] == '2' && b3[4] == '2' && b3[5] == '2'){
		winner = '2';
	}
	if(b3[0] == '2' && b3[4] == '2' && b3[8] == '2'){
		winner = '2';
	}
	if(b3[2] == '2' && b3[4] == '2' && b3[6] == '2'){
		winner = '2';
	}
	/* O is winner */
	if(b3[0] == '1' && b3[3] == '1' && b3[6] == '1'){
		winner = '1';
	}
	if(b3[0] == '1' && b3[1] == '1' && b3[2] == '1'){
		winner = '1';
	}
	if(b3[2] == '1' && b3[5] == '1' && b3[8] == '1'){
		winner = '1';
	}
	if(b3[6] == '1' && b3[7] == '1' && b3[8] == '1'){
		winner = '1';
	}
	if(b3[1] == '1' && b3[4] == '1' && b3[7] == '1'){
		winner = '1';
	}
	if(b3[3] == '1' && b3[4] == '1' && b3[5] == '1'){
		winner = '1';
	}
	if(b3[0] == '1' && b3[4] == '1' && b3[8] == '1'){
		winner = '1';
	}
	if(b3[2] == '1' && b3[4] == '1' && b3[6] == '1'){
		winner = '1';
	}
	/*tie game*/
	if(move == '9' && winner == ' '){ 
		winner = '0';
	}
	return winner;
}

unsigned short next(unsigned short us, char pos){ /* takes in us format of board, and desired position [0-8], returns us format board number after piece is placed on desired position*/
	char b3[10];
	char turn;
	int posnum;
	posnum = pos - '0';

	b3fromus(b3, us);
	turn = get_turn(b3);
	if(b3[posnum] != '0'){ /*returns 0 if desired positon is taken, illegal move*/
		return 0;
	}
	else if(turn == '2'){
		b3[posnum] = '2'; /*if its X's turn, make the desired position X*/
	}
	else{
		b3[posnum] = '1'; /*if its O's turn, make the desired positon O*/
	}
	us = b3tous(b3); 
	return us;
}
