#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include "game.h"

void menu()
{
	printf("***********************\n");
	printf("*******  1.play *******\n");
	printf("*******  0.exit *******\n");
	printf("***********************\n");
}

void game()
{
	char board[ROW][COL]={0};
	char ret=0;
	InitBoard(board,ROW,COL);//��ʼ������
	DisplayBoard(board,ROW,COL);//��ӡ����
	srand((unsigned int)time(NULL));
	do
	{
		PlayerMove(board,ROW,COL);
		ret=IsWin(board,ROW,COL);
		if((ret!='C'))
			break;
		DisplayBoard(board,ROW,COL);
		ComputerMove(board,ROW,COL);
		ret=IsWin(board,ROW,COL);
		if((ret!='C'))
			break;
		DisplayBoard(board,ROW,COL);
	}while(ret=='C');
	if(ret=='*')
	{
		printf("���Ӯ\n");
	}
	else if(ret=='#')
	    {
	     printf("����Ӯ\n"); 
	     }
    else if(ret=='Q')
	    {
	     printf("ƽ��Ŷ\n"); 
	     }
	DisplayBoard(board,ROW,COL);

}
void test()
{
	
	int input=0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��->");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
		     game();
		     break;
		 case 0:
		     printf("�˳���Ϸ");
		     break;
		 default:
			 printf("��������");
			 break;
		}
	}while(input);
}
		 
		
int main()
{
	test();
	system("pause");
	return 0;
}