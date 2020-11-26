#include "othello.h"

void	print_board(char **board, t_coordinate coor)
{
	int i;
	int j;

	printf(" \e[1;1H\e[2J");						// ���� ����â�� �ʱ�ȭ �Ͽ� ��â���� ��� �ǵ��� ��
	printf("\n ");									// �����ٺ��� ���
	for (i = 0 ; i < coor.n ; i++)					// X ��ǥ ���� ǥ��
		printf("% d", i);
	printf("\n");
	for (i = 0 ; i < coor.m ; i++)					// ������ ��
	{
		printf("%d ", i);							// Y ��ǥ ���
		for (j = 0 ; j < coor.n ; j++)				// ������ ��
		{
			printf("%c ", board[i][j]);				// 2���� �迭�� ��Ҹ� �ϳ��� �����
		}
		printf("\n");								// �������� ���� ���� �ؿ� ����ϵ��� ��
	}
}
