#include "othello.h"

void	free_board(char **board, t_coordinate coor)
{
	int i;

	for (i = 0 ; i < coor.m ; i++)				// 2���� �迭 �����Ҵ� ����
		free(board[i]);							// 2���� �迭�� ù ����� ����
	free(board);								// 2���� �迭 ��ü�� ����
}

void	end_game(char **board, t_coordinate coor)
{
	int i;
	int j;
	int num_o;
	int num_x;

	num_o = 0;									// O ������ �Է¹޴� ���� �ʱ�ȭ
	num_x = 0;									// X ������ �Է¹޴� ���� �ʱ�ȭ

	i = 0;
	while (i < coor.m)							// ��
	{
		j = 0;
		while (j < coor.n)						// ��
		{										// 2���� �迭�� �� ��Ŀ� ����Ǿ� �ִ� ���� O �̸� num_o ���� 1 ����
			if (board[i][j] == 'O')
				num_o++;
			if (board[i][j] == 'X')				// X�� num_x ���� 1 ����
				num_x++;
			j++;
		}
		i++;
	}

	printf("\nO : %d\nX : %d\n", num_o, num_x);	// ���� ������ �� ���
	if (num_o > num_x)							// O�� �� ������
		printf("\n%c �¸�!\n", 'O');			// O �¸� ���
	else if (num_o < num_x)						// X�� �� ������
		printf("\n%c �¸�!\n", 'X');			// X �¸� ���
	else										// ������ ���º� ���
		printf("\n���º�\n");
	free_board(board, coor);					// �����Ҵ� ����
	exit(1);									// ���μ��� ����
}
