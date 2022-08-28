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
	//printf("---|---|---\n");������ʽ̫�̶��ˣ���Ҫ�ı�ɿɿ��Ƶ�
	for (i = 0; i < row; i++)
	{
		int j = 0;
		//���к��У����ݾŹ�������ȷ��ѭ������ȷ���ڼ��е������£��ٴ�ӡ������Ӧ�ķ���
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
	printf("�����>\n");
	while (1)
	{
		printf("������x��y�����꣺>");
		scanf("%d,%d", &x, &y);
		//�жϺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*'; //��С�İ�=д��==����ô��û�п���������
				break;
			}
			
			else
			{
				printf("�����ѱ�ռ�ã����������룺>\n");
			}
		}
		else
		{
			printf("����Ƿ������������룡\n");
		}
	}
}
void computermove(char board[ROW][COL], int row, int col)
{
	int x;
	int y;
	printf("�������壺>\n");
	x = rand() % row;   //��rand()%()�� ʵ�ֽ�x,y�ķ�Χ�޶���[0,2]����������λ�õ�����ķ���
	y = rand() % col;  //��ʹ��rand()֮ǰ�����ȵ���srand(),time������������ʱ�����Ϊsrand�����������,
	while(1)
	{
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
//����1����������0������
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
	//������
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]  && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//������
	for (i = 0; i < col; i++)
	{
		
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]  && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]  && board[0][0] != ' ')
		{
			return board[1][1];
		}
	if ( board[0][2] == board[1][1] && board[1][1] == board[2][0]  && board[2][0] != ' ')
		{
			return board[1][1];
		}
	//�ж��Ƿ�ƽ�֣��������Ƿ����ĽǶȣ�
	/*else
	{
		return 'Q';
	}*/
	if (1 == Isfull(board,ROW,COL))
	{
		return 'Q';
	}
	return 'C';//����ļ�����ʲô�����أ����Ӯ������Ӯ��ƽ�ֳ����������û���ˣ���������Ϊ����ѭ����һ�������ڣ�������������
}



