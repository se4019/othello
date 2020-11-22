#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void	input_coordinate(int *x, int *y, int mode)
{
	if (mode == 0)
	{
		printf ("N, M : ");
		scanf ("%d %d", x, y);
	}
	if (mode == 1)
	{
		printf ("x, y : ");
		scanf ("%d %d", x, y);
	}
}

void	print_board(char **board, int n, int m)
{
	int i;
	int j;

	printf("\n  ");
	for (i = 0 ; i < n ; i++)
		printf("%d", i);
	printf("\n");
	for (i = 0 ; i < m ; i++)
	{
		printf("%d ", i);
		printf("%s\n", board[i]);
	}
}

void	set_board(char **board, int n, int m)
{
	board[m / 2][n / 2] = 'O';
	board[m / 2 - 1][n / 2] = 'X';
	board[m / 2][n / 2 - 1] = 'X';
	board[m / 2 - 1][n / 2 - 1] = 'O';
}

void	free_board(char **board, int m)
{
	int i;

	for (i = 0 ; i < m ; i++)
		free(board[i]);
	free(board);
}

int main(void)
{
	int n;
	int m;
	int i;
	int j;
	int x;
	int y;
	int game_end;
	int tic_tok;
	int turn_flag;
	char **board;

	input_coordinate(&n, &m, 0);
	if (n <= 2 || m <= 2 || n % 2 == 1 || m % 2 == 1)
	{
		printf("2보다 큰 짝수를 입력해주세요.\n");
		input_coordinate(&n, &m, 0);
	}
	board = malloc(sizeof(char *) * (m + 1));

	for (i = 0 ; i < m ; i++)
	{
		board[i] = malloc(sizeof(char) * (n + 1));
		for (j = 0 ; j < n ; j++)
		{
			board[i][j] = '.';
		}
	}

	set_board(board, n, m);
	print_board(board, n, m);

	game_end = 0;
	tic_tok = 0;
	turn_flag = 0;

	while (game_end == 0)
	{
		if (turn_flag == 1)
			tic_tok = tic_tok == 0 ? 1 : 0;
		printf("turn : %c\n", tic_tok == 0 ? 'O' : 'X');
		while (1)
		{
			input_coordinate(&x, &y, 1);
			if (board[y][x] == '.')
			{
				board[y][x] = tic_tok == 0 ? 'O' : 'X';
				tic_tok = tic_tok == 0 ? 1 : 0;
				break;
			}
			else
				printf("여기에는 둘 수 없습니다.\n");
		}
		print_board(board, n, m);
	}

	free_board(board, m);
	return (0);
}
