#include "othello.h"

// mode 0�� ���� ������ �ʰ� �˻縸 �� mode 1 �� �˻� �� ������
int		right_check(char **board, t_coordinate *coor, int tic_tok, int mode) // ������ �ٲ� �� �˻�
{
	int i;
	int j;
	char stone;														// ���� ��

	stone = tic_tok == 0 ? 'O' : 'X';								// ���� �Ͽ� �´� �� ����
	if (coor->x == coor->n - 1 || coor->x == coor->n - 2)			// �� ���� �� �����ʰ� �� �� �ٿ� ������ �˻� �� ��
		return (0);
	if (board[coor->y][coor->x + 1] == stone)						// �ٷ� ������ ���̶� ���� ���̸� �˻� �� ��
		return (0);
	i = coor->x + 1;												// ���� �� �� �������� ������ ��ĭ ������ �˻����
	while (i < coor->n)
	{
		if (board[coor->y][i] == '.')								// ��ĭ�̸� �˻� ����
			return (0);
		if (board[coor->y][i] == stone)								// �˻� �� ���� �� ���� ���� ���� ������
		{															// OXXXXXO ���� �ι�° O�� ���� ��Ȳ
			j = coor->x + 1;
			while (j < i && mode == 1)								// mode�� 1�� ��
			{
				board[coor->y][j] = tic_tok == 0 ? 'O' : 'X';		// ���忡 �ִ� ������ ������ mode 0�� �˻縸 ��
				j++;
			}
			return(1);
		}
		i++;
	}
	return (0);
}

int		right_upper_check(char **board, t_coordinate *coor, int tic_tok, int mode) // ������ �� �˻�
{
	int i;
	int j;
	int k;
	int l;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';											// ���� ���� ���� ����
	if (coor->x == coor->n - 1 || coor->x == coor->n - 2 || coor->y == 0 || coor->y == 1) // �� ���� �� �ڴ� �˻� ����
		return (0);
	if (board[coor->y - 1][coor->x + 1] == stone)											// ������ ���� ���� �� ���� ������ �˻� �� ��
		return (0);
	i = coor->x + 1;																		// ������ �� ���� �˻� ����
	j = coor->y - 1;

	while (i < coor->n && j >= 0)
	{
		if (board[j][i] == '.')																// �߰��� ��ĭ ������ �˻� ����
			return (0);
		if (board[j][i] == stone)															// �˻� �� ���� �ϰ� ���� ���� ������
		{
			k = coor->x + 1;																// ���� �� x y�� ������ ������
			l = coor->y - 1;
			while (k < i && l > j && mode == 1)												// ��尡 1�϶�
			{
				board[l][k] = tic_tok == 0 ? 'O' : 'X';										// ���� �ϰ� ���� ���� ���� �������� �� ���� ������
				k++;
				l--;
			}
			return(1);
		}
		i++;
		j--;
	}
	return (0);
}

int		right_lower_check(char **board, t_coordinate *coor, int tic_tok, int mode)				// ������ �Ʒ� �˻�
{
	int i;
	int j;
	int k;
	int l;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';															// ���� �� �� ����
	if (coor->x == coor->n - 1 || coor->x == coor->n - 2 || coor->y == coor->m - 1 || coor->y == coor->m - 2)
		return (0);																				//���� ���̶� �� �ٷ� �ڸ� �˻� �� ��
	if (board[coor->y + 1][coor->x + 1] == stone)												//������ �Ʒ��� ���� ���̶� ���� ���̸� �˻� �� ��
		return (0);
	i = coor->x + 1;																			// ������ �Ʒ����� �˻� ����
	j = coor->y + 1;
	while (i < coor->n && j < coor->m)															// �˻� ����
	{
		if (board[j][i] == '.')																	// �߰��� ��ĭ�̸� �˻� ����
			return (0);
		if (board[j][i] == stone)																// ��� �ٸ� �� �̴ٰ� ���� ���̶� ���� ���� ������
		{
			k = coor->x + 1;																	// �˻� ���� ��������
			l = coor->y + 1;
			while (k < i && l < j && mode == 1)													// ���� ��������
			{
				board[l][k] = tic_tok == 0 ? 'O' : 'X';											// mode�� 1�϶� ������
				k++;
				l++;
			}
			return(1);
		}
		i++;
		j++;
	}
	return (0);
}

int		lower_check(char **board, t_coordinate *coor, int tic_tok, int mode)		// �Ʒ��� �˻�
{
	int i;
	int j;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';												// ���� ���� ���� ����
	if (coor->y == coor->m - 1 || coor->y == coor->m - 2)							// �� �Ʒ��ʰ� �� �ٷ� ���� ������ �˻� �� ��
		return (0);
	if (board[coor->y + 1][coor->x] == stone)										// �ٷ� �Ʒ��� ���� ���� �� ���� ������ �˻� �� ��
		return (0);
	i = coor->y + 1;																// �˻� ��������
	while (i < coor->m)
	{
		if (board[i][coor->x] == '.')												// �߰��� ��ĭ ������ �˻� �� ��
			return (0);
		if (board[i][coor->x] == stone)												// ��� �ٸ� ���̴ٰ� ���� �� ������
		{
			j = coor->y + 1;														// �˻� ���� ��������
			while (j < i && mode == 1)												// mode�� 1�϶�
			{
				board[j][coor->x] = tic_tok == 0 ? 'O' : 'X';						// ���� ������
				j++;
			}
			return(1);
		}
		i++;
	}
	return (0);
}

int		upper_check(char **board, t_coordinate *coor, int tic_tok, int mode)	// ���� �˻�
{
	int i;
	int j;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';											// ���� �� ����
	if (coor->y == 0 || coor->y == 1)
		return (0);
	if (board[coor->y - 1][coor->x] == stone)									// �� ���� ���̸� �˻� ����
		return (0);
	i = coor->y - 1;															// �˻� ��������
	while (i >= 0)
	{
		if (board[i][coor->x] == '.')											// ��ĭ�̸� �˻� ����
			return (0);
		if (board[i][coor->x] == stone)											// �ٸ� ���̴ٰ� ���� ���� ������
		{
			j = coor->y - 1;
			while (j > i && mode == 1)											// ��尡 1�϶� ���� ������
			{
				board[j][coor->x] = tic_tok == 0 ? 'O' : 'X';
				j--;
			}
			return(1);
		}
		i--;
	}
	return (0);
}

int		left_check(char **board, t_coordinate *coor, int tic_tok, int mode)	// ���� �˻�
{
	int i;
	int j;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';										// ���� �� ���� ����
	if (coor->x == 0 || coor->x == 1)										// �� �����̸� �˻� ����
		return (0);
	if (board[coor->y][coor->x - 1] == stone)								// �� �ٷ� �յ� �˻� ����
		return (0);
	i = coor->x - 1;														// �˻� �������� ���� �� ������ �� ĭ ����
	while (i >= 0)
	{
		if (board[coor->y][i] == '.')										// ��ĭ�̸� �˻� ����
			return (0);
		if (board[coor->y][i] == stone)										// ���� ���� ������
		{
			j = coor->x - 1;												// �˻� ������������
			while (j > i && mode == 1)										// ��尡 1�϶�
			{
				board[coor->y][j] = tic_tok == 0 ? 'O' : 'X';				// ���� ������
				j--;
			}
			return(1);
		}
		i--;
	}
	return (0);
}

int		left_upper_check(char **board, t_coordinate *coor, int tic_tok, int mode)	// ���� �� �˻�
{
	int i;
	int j;
	int k;
	int l;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';												// ���� �� ����
	if (coor->x == 0 || coor->x == 1 || coor->y == 0 || coor->y == 1)				// �� ���ʰ� �� �����̸� �˻� ����
		return (0);
	if (board[coor->y - 1][coor->x - 1] == stone)									// �� ���� �ٷ� �� ĭ�� �˻� ����
		return (0);
	i = coor->x - 1;																// �˻� ��������
	j = coor->y - 1;
	while (i >= 0 && j >= 0)														// �� ���ʱ��� �˻�
	{
		if (board[j][i] == '.')														// ��ĭ�̸� �˻� ����
			return (0);
		if (board[j][i] == stone)													// ���� ���� ������
		{
			k = coor->x - 1;														// �˻� ������������
			l = coor->y - 1;
			while (k > i && l > j && mode == 1)										// mode�� 1 �϶�
			{
				board[l][k] = tic_tok == 0 ? 'O' : 'X';								// ���� ������
				k--;
				l--;
			}
			return(1);
		}
		i--;
		j--;
	}
	return (0);
}

int		left_lower_check(char **board, t_coordinate *coor, int tic_tok, int mode)	// ���� �Ʒ� �˻�
{
	int i;
	int j;
	int k;
	int l;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';												// ���� �� ����
	if (coor->x == 0 || coor->x == 1 || coor->y == coor->m - 1 || coor->y == coor->m - 2) // �� ���ʰ� �� �Ʒ���, �� �ٷ� �յ� �˻� ����
		return (0);
	if (board[coor->y + 1][coor->x - 1] == stone)										// ���� �� ���� �Ʒ� ������ ���� ���̸� �˻� ����
		return (0);
	i = coor->x - 1;																	// �˻� ��������
	j = coor->y + 1;
	while (i >= 0 && j < coor->m)
	{
		if (board[j][i] == '.')															// ��ĭ ������ �˻� ����
			return (0);
		if (board[j][i] == stone)														// ���� ���� ���� ���� ������
		{
			k = coor->x - 1;															// �˻� ���� ��������
			l = coor->y + 1;
			while (k > i && l < j && mode == 1)											// ��尡 1�̸�
			{
				board[l][k] = tic_tok == 0 ? 'O' : 'X';									// ���� ������
				k--;
				l++;
			}
			return(1);
		}
		i--;
		j++;
	}
	return (0);
}

int		eight_check(char **board, t_coordinate *coor, int tic_tok, int mode)	// ���� 8�� ���� �˻縦 ��� �����ϴ� �Լ�
{
	int eight_flag[8];															// �˻� ����� �����ϴ� �迭 �˻� ��� ������ ���� ������ 1 ������ 0
	int i;

	i = 0;
	eight_flag[0] = right_check(board, coor, tic_tok, mode);					// ������ �˻�
	eight_flag[1] = right_upper_check(board, coor, tic_tok, mode);				// ������ �� �˻�
	eight_flag[2] = right_lower_check(board, coor, tic_tok, mode);				// ������ �Ʒ� �˻�
	eight_flag[3] = lower_check(board, coor, tic_tok, mode);					// �ؿ��� �˻�
	eight_flag[4] = upper_check(board, coor, tic_tok, mode);					// ���� �˻�
	eight_flag[5] = left_check(board, coor, tic_tok, mode);						// ���� �˻�
	eight_flag[6] = left_upper_check(board, coor, tic_tok, mode);				// ���� �� �˻�
	eight_flag[7] = left_lower_check(board, coor, tic_tok, mode);				// ���� �Ʒ� �˻�

	while (i < 8)
	{
		if (eight_flag[i] == 1)													// ���࿡ 1���� ������ ���� ������ TRUE(1) ��ȯ
			return (TRUE);
		i++;
	}
	return (FALSE);																// 1���� ������ ���� ������ FALSE(0) ��ȯ
}
