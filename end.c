#include "othello.h"

void	free_board(char **board, t_coordinate coor)
{
	int i;

	for (i = 0 ; i < coor.m ; i++)				// 2차원 배열 동적할당 해제
		free(board[i]);							// 2차원 배열의 첫 행들을 해제
	free(board);								// 2차원 배열 자체를 해제
}

void	end_game(char **board, t_coordinate coor)
{
	int i;
	int j;
	int num_o;
	int num_x;

	num_o = 0;									// O 갯수를 입력받는 변수 초기화
	num_x = 0;									// X 갯수를 입력받는 변수 초기화

	i = 0;
	while (i < coor.m)							// 열
	{
		j = 0;
		while (j < coor.n)						// 행
		{										// 2차원 배열의 각 행렬에 저장되어 있는 것이 O 이면 num_o 변수 1 증가
			if (board[i][j] == 'O')
				num_o++;
			if (board[i][j] == 'X')				// X면 num_x 변수 1 증가
				num_x++;
			j++;
		}
		i++;
	}

	printf("\nO : %d\nX : %d\n", num_o, num_x);	// 점수 집계한 것 출력
	if (num_o > num_x)							// O가 더 많으면
		printf("\n%c 승리!\n", 'O');			// O 승리 출력
	else if (num_o < num_x)						// X가 더 많으면
		printf("\n%c 승리!\n", 'X');			// X 승리 출력
	else										// 같으면 무승부 출력
		printf("\n무승부\n");
	free_board(board, coor);					// 동적할당 해제
	exit(1);									// 프로세스 종료
}
