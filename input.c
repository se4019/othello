#include "othello.h"

void	input_coordinate(t_coordinate *coor, int mode)
{
	while (1)											// �Է����� �˸��� ���� ���� ������ ��� �ݺ���Ŵ
	{
		if (mode == 0)									// �Է� ��尡 0 �̸� N, M �Է�
		{
			printf ("N, M : ");							// N, M �Է� ���
			scanf ("%d %d", &coor->n, &coor->m);		// �Է¹��� ���� ����ü n, m ������ ����
			if (coor->n < 0 && coor->m <0)				// ������ �Է��ϸ�
			{
				printf("����� �Է����ּ���.");					// ��� ��
				continue;								// �ؿ� ���� ���� �� �ٽ� �ݺ��� ó������ ��
			}
			if (coor->n <= 2 || coor->m <= 2 || coor->n % 2 == 1 || coor->m % 2 == 1) // 2 ���� �۰ų� Ȧ���̸�
			{
				printf("2���� ū ¦���� �Է����ּ���.\n");									// ��� ��
				continue;															// �ؿ� ���� ���� �ϰ� �ٽ� �Է� ����
			}
			else																	// �˸��� �Է��̸� �ݺ��� ����
				break;
		}
		if (mode == 1)									//mode�� 1�̸� x, y �Է¹���
		{
			printf ("x, y : ");							// x, y �Է� ���
			scanf ("%d %d", &coor->x, &coor->y);		// ����ü x, y ������ ����
			if (coor->x < 0 && coor->y < 0)				// ������ �Է¹�����
			{
				printf("0�̻��� ���� �Է��ϼ���.");			//���
				continue;								// �ٽ� �Է¹���
			}
			if (coor->x < coor->n && coor->y < coor->m) // �˸��� ���� �Է� ������ �ݺ��� ����
				break;
			else										// n, m���� ū ���� �Է¹����� �ؿ� ���� ���� �� �ٽ� �ݺ����� ����.
			{
				printf("x = %d, y = %d ���� ���� ���� �Է��ϼ���.\n", coor->n, coor->m);
				continue;
			}
		}
	}
}

void	set_board(char **board, t_coordinate coor)		// ���� ���� �� ���� �� ��ġ
{
	board[coor.m / 2][coor.n / 2] = 'O';				// n, m���� �࿭ �߿� ��� ������ 'O'
	board[coor.m / 2 - 1][coor.n / 2] = 'X';			// ��� ���� ��ĭ �ؿ� 'X'
	board[coor.m / 2][coor.n / 2 - 1] = 'X';			// ��� ���� ��ĭ �տ� 'X'
	board[coor.m / 2 - 1][coor.n / 2 - 1] = 'O';		// ��� ���� �밢���� 'O'
}
