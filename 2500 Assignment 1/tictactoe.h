/* tictactoe.h
    Header file.
    By: Numan Mir (nmir@uoguelph.ca)
    Student ID: 1005381
*/
#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <stdio.h>
typedef struct strategy_struct /*creates struct for strategy file*/
{
    char best_move;
    char winner;
}strat;
/*function prototypes*/
unsigned short b3tous(char b3[10]);
void b3fromus(char b3[10], unsigned short us);
void debug(unsigned short us);
void debug2(unsigned short us);
void boardfromb3(char board[60], char b3[10]);
void boardtob3(char b3[10], char board[60]);
char get_move(char b3[10]);
char get_turn(char b3[10]);
char winner(unsigned short us);
unsigned short next(unsigned short us, char pos);
void get_record(FILE*, unsigned short us, struct strategy_struct *record);
void set_record(FILE*, unsigned short us, struct strategy_struct record);


#endif

