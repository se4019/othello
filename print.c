#include "othello.h"

void	print_board(char **board, t_coordinate coor)
{
	int i;
	int j;

	printf(" \e[1;1H\e[2J");						// 현재 실행창을 초기화 하여 새창에서 출력 되도록 함
	printf("\n ");									// 다음줄부터 출력
	for (i = 0 ; i < coor.n ; i++)					// X 좌표 숫자 표시
		printf("% d", i);
	printf("\n");
	for (i = 0 ; i < coor.m ; i++)					// 보드의 열
	{
		printf("%d ", i);							// Y 좌표 출력
		for (j = 0 ; j < coor.n ; j++)				// 보드의 행
		{
			printf("%c ", board[i][j]);				// 2차원 배열의 요소를 하나씩 출력함
		}
		printf("\n");								// 개행으로 다음 열은 밑에 출력하도록 함
	}
}
