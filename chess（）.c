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
	printf("3x3���������̣��뿼�Ǻú�ʼ���塪����������������������>>\n");
	char ret;
	//�������̴�ŵ���Ϣ
	//ȫ���ո�
	char board[ROW][COL] = {0};//��ʼ���󲻹ܴ˴����ֵ����
	//����ȫ����ʼ��
	intboard(board,ROW,COL);
	//��ӡ����
	displayboard(board, ROW, COL);
	//���壬��Ҫ���ϵ�ѭ��
	while (1)
	{
		
		//�������
		playermove(board, ROW, COL);
		//��ϲ鿴�ı�������״̬����ʱ����һ�������룬�������ݸı䣬displayboard��ӡ���Ѿ��޸ĵĵ���״̬
		displayboard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = Iswin(board, ROW, COL);
		//���ret��Ϊ���������ӳ�ȥ���ж���˭Ӯ����ƽ��
		if (ret != 'C')
		{
			break;
		}

		//��������
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if(ret=='#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}//��������Щ�����ֱ𷵻ز�ͬ��ֵ�أ�
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));  //srand�����������������ʱ����ʱ��������ã���ʱ�����ô�����أ���time()������time()��������ָ��null����ǿת��unsigned int ����(time�����ķ���������time_t)��time������������ʱ�����Ϊsrand�����������,
	do
	{
		menu();
		printf("��ѡ��>:");
		scanf("%d",&input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ");
				break;
			default:
				printf("ѡ��������������룺\n");
				break;
		}
		
	} while (input);

}
int main()
{
	test();
	return 0;
}//�ȹ��ܺ�������Ϸ�Ŀ��