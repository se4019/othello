#include "othello.h"

int		turn_check(char **board, t_coordinate *coor, int tic_tok)
{
	int i;
	int j;
	int x_max;
	int y_max;

	x_max = coor->n;						//n 을 x_max에 저장
	y_max = coor->m;						//m 을 y_max에 저장

	for (i = 0 ; i < y_max ; i++)			// 보드의 모든 자리에서 8방향을 모두 검사함 y좌표 이동
	{
		coor->y = i;
		for (j = 0 ; j < x_max ; j++)		// x 좌표 이동
		{
			coor->x = j;
			if (eight_check(board, coor, tic_tok, 0) == TRUE)		//8방향을 검사하는 함수
			{
				return (TRUE);										// 발견하면 1 리턴 후 함수 종료
			}
		}
	}
	tic_tok = tic_tok == 0 ? 1 : 0;									// 없으면 턴 바꿔서 다시 검사함
	for (i = 0 ; i < y_max ; i++)									// y좌표 이동
	{
		coor->y = i;
		for (j = 0 ; j < x_max ; j++)								// x좌표 이동
		{
			coor->x = j;
			if (eight_check(board, coor, tic_tok, 0) == TRUE)		// 8방향 검사 후 한개라도 있으면
			{
				tic_tok = tic_tok == 0 ? 1 : 0;						// 턴을 원래대로 돌려놓고
				printf("턴이 넘어갑니다.\n");							// 턴을 넘어갑니다. 출력
				return (FALSE);										// 0 리턴 후 함수 종료
			}
		}
	}
	printf("\n더 이상 둘 곳이 없습니다.\n");							// 만약에 턴을 바꿔서도 검사해도 둘 곳이 없으면 출력
	end_game(board, *coor);											// 게임 종료
	return (2);
}

int		blank_OX_check(char **board, t_coordinate *coor)		// 빈칸과 O, X가 있는지 없는지 체크함
{
	int i;
	int j;
	int x_max;
	int y_max;
	int blank_flag;												//blank 있는지 없는지 저장
	int o_flag;													// 'O'가 있는지 없는지 저장
	int x_flag;													// 'X'가 있는지 없는지 저장

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
			if (board[i][j] == '.')								// 빈칸이 1개라도 있으면
				blank_flag = 1;									// 1 저장 없으면 0
			if (board[i][j] == 'O')								// 보드에 O가 있으면 1 없으면 0
				o_flag = 1;
			if (board[i][j] == 'X')								// 보드에 X가 있으면 1 없으면 0
				x_flag = 1;
		}
	}
	if (blank_flag == 1 && o_flag == 1 && x_flag == 1)			// 빈칸이 한개라도 있고, O,X도 각각 한개 이상 있어야 게임 진행
		return (TRUE);
	else
		end_game(board, *coor);									// 셋 중에 하나라도 없으면 게임 종료
	return (FALSE);												// 함수 종료
}
