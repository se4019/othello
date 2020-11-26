#include "othello.h"

void	input_coordinate(t_coordinate *coor, int mode)
{
	while (1)											// 입력으로 알맞은 수가 들어올 때까지 계속 반복시킴
	{
		if (mode == 0)									// 입력 모드가 0 이면 N, M 입력
		{
			printf ("N, M : ");							// N, M 입력 출력
			scanf ("%d %d", &coor->n, &coor->m);		// 입력받은 수를 구조체 n, m 변수에 저장
			if (coor->n < 0 && coor->m <0)				// 음수를 입력하면
			{
				printf("양수를 입력해주세요.");					// 출력 후
				continue;								// 밑에 내용 무시 후 다시 반복문 처음으로 감
			}
			if (coor->n <= 2 || coor->m <= 2 || coor->n % 2 == 1 || coor->m % 2 == 1) // 2 보다 작거나 홀수이면
			{
				printf("2보다 큰 짝수를 입력해주세요.\n");									// 출력 후
				continue;															// 밑에 내용 무시 하고 다시 입력 받음
			}
			else																	// 알맞은 입력이면 반복문 종료
				break;
		}
		if (mode == 1)									//mode가 1이면 x, y 입력받음
		{
			printf ("x, y : ");							// x, y 입력 출력
			scanf ("%d %d", &coor->x, &coor->y);		// 구조체 x, y 변수에 저장
			if (coor->x < 0 && coor->y < 0)				// 음수를 입력받으면
			{
				printf("0이상의 수를 입력하세요.");			//출력
				continue;								// 다시 입력받음
			}
			if (coor->x < coor->n && coor->y < coor->m) // 알맞은 수를 입력 받으면 반복문 종료
				break;
			else										// n, m보다 큰 수를 입력받으면 밑에 내용 무시 후 다시 반복문을 돈다.
			{
				printf("x = %d, y = %d 보다 작은 수를 입력하세요.\n", coor->n, coor->m);
				continue;
			}
		}
	}
}

void	set_board(char **board, t_coordinate coor)		// 게임 시작 시 보드 돌 배치
{
	board[coor.m / 2][coor.n / 2] = 'O';				// n, m개의 행열 중에 가운데 지점에 'O'
	board[coor.m / 2 - 1][coor.n / 2] = 'X';			// 가운데 지점 한칸 밑에 'X'
	board[coor.m / 2][coor.n / 2 - 1] = 'X';			// 가운데 지점 한칸 앞에 'X'
	board[coor.m / 2 - 1][coor.n / 2 - 1] = 'O';		// 가운데 지점 대각선에 'O'
}
