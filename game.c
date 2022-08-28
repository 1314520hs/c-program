#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void intboard(char board[ROW][COL], int row, int col)
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j =0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void displayboard(char board[ROW][COL], int row, int col)
{
	int i;
	//printf("---|---|---\n");这种形式太固定了，需要改编成可控制的
	for (i = 0; i < row; i++)
	{
		int j = 0;
		//先行后列，根据九宫格线条确定循环，先确定在几行的条件下，再打印几列相应的符号
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row-1) 
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if(j<col-1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
		
	}
	 


}
void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走>\n");
	while (1)
	{
		printf("请输入x，y的坐标：>");
		scanf("%d,%d", &x, &y);
		//判断合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*'; //不小心把=写成==，怎么都没有看出来错误！
				break;
			}
			
			else
			{
				printf("坐标已被占用，请重新输入：>\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入！\n");
		}
	}
}
void computermove(char board[ROW][COL], int row, int col)
{
	int x;
	int y;
	printf("电脑下棋：>\n");
	x = rand() % row;   //“rand()%()” 实现将x,y的范围限定在[0,2]并生成任意位置的坐标的方法
	y = rand() % col;  //在使用rand()之前必须先调用srand(),time函数返回来的时间戳作为srand的随机生成器,
	while(1)
	{
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
//返回1即满，返回0即非满
int Isfull(char board[ROW][COL], int row, int col)
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char Iswin(char board[ROW][COL], int row, int col)
{
	int i;
	//横三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]  && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//竖三列
	for (i = 0; i < col; i++)
	{
		
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]  && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]  && board[0][0] != ' ')
		{
			return board[1][1];
		}
	if ( board[0][2] == board[1][1] && board[1][1] == board[2][0]  && board[2][0] != ' ')
		{
			return board[1][1];
		}
	//判断是否平局，从棋盘是否满的角度，
	/*else
	{
		return 'Q';
	}*/
	if (1 == Isfull(board,ROW,COL))
	{
		return 'Q';
	}
	return 'C';//这里的继续是什么意义呢？玩家赢、电脑赢、平局除此三种情况没有了，继续是作为跳出循环的一个（窗口）附加条件而已
}



