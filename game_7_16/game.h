#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include<string.h>
void display(char** tips, int m, int n)
{
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n ; j++)
		{
			printf(" %c ",tips[i][j]);
			if (j < n )
				printf("|");
			else printf("\n");
		}
		if(i<m)
		{
			for (int j = 1; j < n ; j++)
			{
				printf("---|");
			}
			printf("---\n");
		}
		
	}
}
void bom(int** board, int m, int n,int boom)
{
	int i = 0,c=0,d=0;
	while(i<boom)
	{
		c = rand() % (m + 1);
		d = rand() % (n + 1);
		if (board[c][d] == 0 && c != 0 && d != 0)
		{
			board[c][d] = 1;
			i++;
		}
	}
	return;
}
int cal(int** board, char** com, int m, int n, int a, int b)
{
	if (a > 0 && a <= m && b > 0 && b <= n)
	{	
		if (board[a][b] == 1)
		{
			com[a][b] = '#';
			return 1;
		}
		else if (com[a][b] != ' ')
		{
			com[a][b] = '0';
			for (int hen = -1; hen <= 1; hen++)
			{
				for (int zong = -1; zong <= 1; zong++)
				{
					if (board[a + hen][b + zong] == 1)
						com[a][b]++;
				}
			}
			if (com[a][b] == '0')
				com[a][b] = ' ';
			if (com[a][b] == ' ')
			{
				cal(board, com, m, n, a + 1, b);
				cal(board, com, m, n, a - 1, b);
				cal(board, com, m, n, a, b + 1);
				cal(board, com, m, n, a, b - 1);
			}
			return 0;
		}
	}
	else return 0;
}
int win(char** com, int m,int n)
{
	int x = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (com[i][j] == '*')
				x++;
		}
	}
	return x;
}

int player(int** board, char** com, int m, int n)
{
	int a = 0, b = 0, f = 0;
	while (1)
	{
		printf("输入您想排雷的坐标:\n");
		scanf("%d%d", &a, &b);
		if (a > 0 && a <= m && b > 0 && b <= n  && com[a][b] == '*')
		{
			f=cal(board, com, m, n, a, b);
			//digui(board, com, m, n, a, b);
			return f;
		}
		else
		{
			printf("输入错误，请重新输入。\n");
		}
	}
}
void game(int** board,char** com, int m, int n,int boom)
{
	int con, winer;
	bom(board, m, n, boom);
	display(com, m, n);
	while (1)
	{
		con=player(board,com,m,n);
		display(com, m, n);
		winer = win(com, m, n);
		if (con == 1)
		{
			printf("踩中地雷了，游戏失败。\n");
			break;
		}
		else if (winer == boom)
		{
			printf("已清除全部地雷，玩家获胜。\n");
			break;
		}
	}
	return;
}
