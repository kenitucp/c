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
	InitBoard(board,ROW,COL);//初始化棋盘
	DisplayBoard(board,ROW,COL);//打印棋盘
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
		printf("玩家赢\n");
	}
	else if(ret=='#')
	    {
	     printf("电脑赢\n"); 
	     }
    else if(ret=='Q')
	    {
	     printf("平局哦\n"); 
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
		printf("请选择：->");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
		     game();
		     break;
		 case 0:
		     printf("退出游戏");
		     break;
		 default:
			 printf("输入有误");
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