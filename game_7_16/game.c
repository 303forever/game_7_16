#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
int main()
{
	int  g = 0;
	int m, n,x,y,boom;
	srand((unsigned int)time(NULL));
	printf("*******玩家请输入：   （输入1开始游戏，输入0结束游戏）\n");
	scanf("%d", &g);
	switch (g)
	{
	case 1:
		printf("游戏开始，请玩家输入雷区的大小:\n");
		scanf("%d %d", &m, &n);
		printf("请输入地雷的数量:\n");
		scanf("%d", &boom);
		x= m + 2;
		y = n + 2;
		int** board = malloc(sizeof(int) * x );
		for (int i = 0; i < y; i++)
		{
			board[i] = (int*)malloc(sizeof(int) * y);
			memset(board[i], 0, sizeof(int) * y);
		}
		char** com = (char*)malloc(sizeof(char) * x);
		for (int i = 0; i < y; i++)
		{
			com[i] = (char*)malloc(sizeof(int) * y);
			memset(com[i], '*', sizeof(char) * y);
		}
		game(board,com, m, n,boom);
		break;
	case 0:
		printf("游戏结束，感谢游玩\n");
		break;
	default:
		printf("输入错误，请重新输入\n");
		main();

	}





	return 0;
}