#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
int main()
{
	int  g = 0;
	int m, n,x,y,boom;
	unsigned int t = time(NULL);
	srand(t);
	printf("�������ɵ��׵������ǣ�%u\n", t);
	printf("*******��������룺   ������1��ʼ��Ϸ������0������Ϸ��\n");
	scanf("%d", &g);
	switch (g)
	{
	case 1:
		printf("��Ϸ��ʼ����������������Ĵ�С:\n");
		scanf("%d %d", &m, &n);
		printf("��������׵�����:\n");
		scanf("%d", &boom);
		x= m + 2;
		y = n + 2;
		int** board = (int**)malloc(sizeof(int*) * x );
		for (int i = 0; i < x; i++)
		{
			board[i] = (int*)malloc(sizeof(int) * y);
			memset(board[i], 0, sizeof(int) * y);
		}
		char** com = (char**)malloc(sizeof(char*) * x);
		for (int i = 0; i < x; i++)
		{
			com[i] = (char*)malloc(sizeof(int) * y);
			memset(com[i], '*', sizeof(char) * y);
		}
		game(board,com, m, n,boom);
		for (int i = 0; i < x; i++) {
			free(com[i]);
		};
		free(com);
		for (int i = 0; i < x; i++) {
			free(board[i]);
		};
		free(board);
		break;
	case 0:
		printf("��Ϸ��������л����\n");
		break;
	default:
		printf("�����������������\n");
		main();

	}





	return 0;
}