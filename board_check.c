#include "othello.h"

int		turn_check(char **board, t_coordinate *coor, int tic_tok)
{
	int i;
	int j;
	int x_max;
	int y_max;

	x_max = coor->n;						//n �� x_max�� ����
	y_max = coor->m;						//m �� y_max�� ����

	for (i = 0 ; i < y_max ; i++)			// ������ ��� �ڸ����� 8������ ��� �˻��� y��ǥ �̵�
	{
		coor->y = i;
		for (j = 0 ; j < x_max ; j++)		// x ��ǥ �̵�
		{
			coor->x = j;
			if (eight_check(board, coor, tic_tok, 0) == TRUE)		//8������ �˻��ϴ� �Լ�
			{
				return (TRUE);										// �߰��ϸ� 1 ���� �� �Լ� ����
			}
		}
	}
	tic_tok = tic_tok == 0 ? 1 : 0;									// ������ �� �ٲ㼭 �ٽ� �˻���
	for (i = 0 ; i < y_max ; i++)									// y��ǥ �̵�
	{
		coor->y = i;
		for (j = 0 ; j < x_max ; j++)								// x��ǥ �̵�
		{
			coor->x = j;
			if (eight_check(board, coor, tic_tok, 0) == TRUE)		// 8���� �˻� �� �Ѱ��� ������
			{
				tic_tok = tic_tok == 0 ? 1 : 0;						// ���� ������� ��������
				printf("���� �Ѿ�ϴ�.\n");							// ���� �Ѿ�ϴ�. ���
				return (FALSE);										// 0 ���� �� �Լ� ����
			}
		}
	}
	printf("\n�� �̻� �� ���� �����ϴ�.\n");							// ���࿡ ���� �ٲ㼭�� �˻��ص� �� ���� ������ ���
	end_game(board, *coor);											// ���� ����
	return (2);
}

int		blank_OX_check(char **board, t_coordinate *coor)		// ��ĭ�� O, X�� �ִ��� ������ üũ��
{
	int i;
	int j;
	int x_max;
	int y_max;
	int blank_flag;												//blank �ִ��� ������ ����
	int o_flag;													// 'O'�� �ִ��� ������ ����
	int x_flag;													// 'X'�� �ִ��� ������ ����

	x_max = coor->n;
	y_max = coor->m;

	blank_flag = 0;
	o_flag = 0;
	x_flag = 0;
	for (i = 0 ; i < y_max ; i++)
	{
		coor->y = i;
		for (j = 0 ; j < x_max ; j++)
		{
			coor->x = j;
			if (board[i][j] == '.')								// ��ĭ�� 1���� ������
				blank_flag = 1;									// 1 ���� ������ 0
			if (board[i][j] == 'O')								// ���忡 O�� ������ 1 ������ 0
				o_flag = 1;
			if (board[i][j] == 'X')								// ���忡 X�� ������ 1 ������ 0
				x_flag = 1;
		}
	}
	if (blank_flag == 1 && o_flag == 1 && x_flag == 1)			// ��ĭ�� �Ѱ��� �ְ�, O,X�� ���� �Ѱ� �̻� �־�� ���� ����
		return (TRUE);
	else
		end_game(board, *coor);									// �� �߿� �ϳ��� ������ ���� ����
	return (FALSE);												// �Լ� ����
}
