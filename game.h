#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//先声明
void intboard(char board[ROW][COL], int row, int col);
void displayboard(char board[ROW][COL],int row,int col);
void playermove(char board[ROW][COL], int row, int col);
void computermove(char board[ROW][COL], int row, int col);
//四种状态：
//玩家赢-'*'
//电脑赢-'#'
//平局-'Q'
//继续-'C'

char Iswin();