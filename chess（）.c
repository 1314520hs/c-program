#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"
void menu()
{
	printf("***********************************\n");
	printf("**********1.play   0.exit**********\n");
	printf("***********************************\n");
}
void game()
{
	printf("3x3的坐标棋盘，请考虑好后开始下棋————————————>>\n");
	char ret;
	//数组棋盘存放的信息
	//全部空格
	char board[ROW][COL] = {0};//初始化后不管此处填何值都可
	//棋盘全部初始化
	intboard(board,ROW,COL);
	//打印棋盘
	displayboard(board, ROW, COL);
	//下棋，需要不断的循环
	while (1)
	{
		
		//玩家下棋
		playermove(board, ROW, COL);
		//配合查看改变后的棋盘状态，此时由上一步的输入，棋盘内容改变，displayboard打印出已经修改的当下状态
		displayboard(board, ROW, COL);
		//判断玩家是否赢
		ret = Iswin(board, ROW, COL);
		//如果ret不为继续，就逃出去，判断是谁赢还是平局
		if (ret != 'C')
		{
			break;
		}

		//电脑下棋
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		//判断电脑是否赢
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if(ret=='#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}//接下来哪些情况会分别返回不同的值呢？
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));  //srand设置随机数生成器的时候拿时间戳来设置，而时间戳怎么来的呢？用time()函数，time()参数给空指针null，再强转成unsigned int 类型(time函数的返回类型是time_t)。time函数返回来的时间戳作为srand的随机生成器,
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d",&input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏");
				break;
			default:
				printf("选择错误，请重新输入：\n");
				break;
		}
		
	} while (input);

}
int main()
{
	test();
	return 0;
}//先构架好整个游戏的框架