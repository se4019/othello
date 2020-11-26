#include "othello.h"								// othello.h ��� �Է�

int main(void)
{
	int i;
	int j;
	t_coordinate coor;								// ����ü ����
	int tic_tok;									// ���� ��
	char **board;									// ���� ����������

	input_coordinate(&coor, 0);						// N x M �Է¹޾� ����ü�� �����ϴ� �Լ�

	board = malloc(sizeof(char *) * (coor.m));		// N M������ ���带 �����Ҵ����� �ʿ��� ��ŭ�� 2���� �迭�� �޸� ����
	for (i = 0 ; i < coor.m ; i++)					// M ����ŭ �ݺ�
	{
		board[i] = malloc(sizeof(char) * (coor.n)); // M���� ���� N���� �ุŭ �����Ҵ�
		for (j = 0 ; j < coor.n ; j++)				// N�� �ݺ��ϸ� �� �࿭�� '.' �Է� '.'�� ��ĭ���� �����
		{
			board[i][j] = '.';
		}
	}

	set_board(board, coor);							// �ʱ� ���� ����
	print_board(board, coor);						// ���带 ����ϸ鼭 ���� ����

	tic_tok = 0;									// 0 = O, 1 = X�� �����Ͽ� O���� ���ӽ���

	while (1)
	{
		if (turn_check(board, &coor, tic_tok) == FALSE)		// ���ӿ� �� �ϸ��� ���� �� �ִ� �ڸ��� �ִ��� Ȯ��
			tic_tok = tic_tok == 0 ? 1 : 0;					// ������ �� �ٲ�
		blank_OX_check(board, &coor);
		printf("turn : %c\n", tic_tok == 0 ? 'O' : 'X');	// � ���� �������� ���
		while (1)											// ������ ���� ������ ��� �ݺ�
		{
			input_coordinate(&coor, 1);						// x, y�Է��� ����
															// �Է¹��� x,y�� ��ĭ���� üũ�ϰ� 8������ �˻��� ���� ������
			if (board[coor.y][coor.x] == '.' && eight_check(board, &coor, tic_tok, 1) == TRUE)
			{
				board[coor.y][coor.x] = tic_tok == 0 ? 'O' : 'X';		// ������ X, Y�� ��ĭ���� ���� �ٲپ� ��
				tic_tok = tic_tok == 0 ? 1 : 0;							// �� ����
				break;													// �ݺ��� ����
			}
			else
				printf("���⿡�� �� �� �����ϴ�.\n");						// ���� �� �� ���� ���̸� ����ϰ� �ٽ� �ݺ����� ���� �Է� ����
		}
		print_board(board, coor);										// �ٲ� ���带 �����
	}
	end_game(board, coor);												// ������ ������ ���踦 �Ѵ�.
	return (0);															// 0 ��ȯ
}


