#include "othello.h"

// mode 0은 돌을 뒤집이 않고 검사만 함 mode 1 은 검사 후 뒤집음
int		right_check(char **board, t_coordinate *coor, int tic_tok, int mode) // 오른쪽 바꿀 것 검사
{
	int i;
	int j;
	char stone;														// 현재 돌

	stone = tic_tok == 0 ? 'O' : 'X';								// 현재 턴에 맞는 돌 저장
	if (coor->x == coor->n - 1 || coor->x == coor->n - 2)			// 둔 돌이 맨 오른쪽과 그 뒷 줄에 있으면 검사 안 함
		return (0);
	if (board[coor->y][coor->x + 1] == stone)						// 바로 오른쪽 돌이랑 같은 돌이면 검사 안 함
		return (0);
	i = coor->x + 1;												// 지금 둔 돌 기준으로 오른쪽 한칸 옆부터 검사시작
	while (i < coor->n)
	{
		if (board[coor->y][i] == '.')								// 빈칸이면 검사 종료
			return (0);
		if (board[coor->y][i] == stone)								// 검사 중 지금 둔 돌과 같은 돌을 만나면
		{															// OXXXXXO 에서 두번째 O와 같은 상황
			j = coor->x + 1;
			while (j < i && mode == 1)								// mode가 1일 때
			{
				board[coor->y][j] = tic_tok == 0 ? 'O' : 'X';		// 보드에 있는 돌들을 뒤집음 mode 0은 검사만 함
				j++;
			}
			return(1);
		}
		i++;
	}
	return (0);
}

int		right_upper_check(char **board, t_coordinate *coor, int tic_tok, int mode) // 오른쪽 위 검사
{
	int i;
	int j;
	int k;
	int l;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';											// 현재 턴의 돌을 저장
	if (coor->x == coor->n - 1 || coor->x == coor->n - 2 || coor->y == 0 || coor->y == 1) // 맨 끝과 그 뒤는 검사 안함
		return (0);
	if (board[coor->y - 1][coor->x + 1] == stone)											// 오른쪽 위가 현재 둔 돌과 같으면 검사 안 함
		return (0);
	i = coor->x + 1;																		// 오른쪽 위 부터 검사 시작
	j = coor->y - 1;

	while (i < coor->n && j >= 0)
	{
		if (board[j][i] == '.')																// 중간에 빈칸 만나면 검사 종료
			return (0);
		if (board[j][i] == stone)															// 검사 중 현재 턴과 같은 돌을 만나면
		{
			k = coor->x + 1;																// 현재 둔 x y의 오른쪽 위부터
			l = coor->y - 1;
			while (k < i && l > j && mode == 1)												// 모드가 1일때
			{
				board[l][k] = tic_tok == 0 ? 'O' : 'X';										// 현재 턴과 같은 돌을 만난 지점까지 돌 들을 뒤집음
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

int		right_lower_check(char **board, t_coordinate *coor, int tic_tok, int mode)				// 오른쪽 아래 검사
{
	int i;
	int j;
	int k;
	int l;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';															// 현재 턴 돌 저장
	if (coor->x == coor->n - 1 || coor->x == coor->n - 2 || coor->y == coor->m - 1 || coor->y == coor->m - 2)
		return (0);																				//끝에 쪽이랑 그 바로 뒤면 검사 안 함
	if (board[coor->y + 1][coor->x + 1] == stone)												//오른쪽 아래가 현재 턴이랑 같은 돌이면 검사 안 함
		return (0);
	i = coor->x + 1;																			// 오른쪽 아래부터 검사 시작
	j = coor->y + 1;
	while (i < coor->n && j < coor->m)															// 검사 시작
	{
		if (board[j][i] == '.')																	// 중간에 빈칸이면 검사 종료
			return (0);
		if (board[j][i] == stone)																// 계속 다른 돌 이다가 현재 턴이랑 같은 돌을 만나면
		{
			k = coor->x + 1;																	// 검사 시작 지점부터
			l = coor->y + 1;
			while (k < i && l < j && mode == 1)													// 현재 지점까지
			{
				board[l][k] = tic_tok == 0 ? 'O' : 'X';											// mode가 1일때 뒤집음
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

int		lower_check(char **board, t_coordinate *coor, int tic_tok, int mode)		// 아래쪽 검사
{
	int i;
	int j;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';												// 현재 턴의 돌을 저장
	if (coor->y == coor->m - 1 || coor->y == coor->m - 2)							// 맨 아래쪽과 그 바로 위에 뒀으면 검사 안 함
		return (0);
	if (board[coor->y + 1][coor->x] == stone)										// 바로 아래쪽 돌과 현재 둔 돌과 같으면 검사 안 함
		return (0);
	i = coor->y + 1;																// 검사 시작지점
	while (i < coor->m)
	{
		if (board[i][coor->x] == '.')												// 중간에 빈칸 만나면 검사 안 함
			return (0);
		if (board[i][coor->x] == stone)												// 계속 다른 돌이다가 같은 돌 만나면
		{
			j = coor->y + 1;														// 검사 시작 지점부터
			while (j < i && mode == 1)												// mode가 1일때
			{
				board[j][coor->x] = tic_tok == 0 ? 'O' : 'X';						// 돌을 뒤집음
				j++;
			}
			return(1);
		}
		i++;
	}
	return (0);
}

int		upper_check(char **board, t_coordinate *coor, int tic_tok, int mode)	// 위쪽 검사
{
	int i;
	int j;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';											// 현재 돌 설정
	if (coor->y == 0 || coor->y == 1)
		return (0);
	if (board[coor->y - 1][coor->x] == stone)									// 맨 위에 돌이면 검사 종료
		return (0);
	i = coor->y - 1;															// 검사 시작지점
	while (i >= 0)
	{
		if (board[i][coor->x] == '.')											// 빈칸이면 검사 종료
			return (0);
		if (board[i][coor->x] == stone)											// 다른 돌이다가 같은 돌을 만나면
		{
			j = coor->y - 1;
			while (j > i && mode == 1)											// 모드가 1일때 돌을 뒤집음
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

int		left_check(char **board, t_coordinate *coor, int tic_tok, int mode)	// 왼쪽 검사
{
	int i;
	int j;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';										// 현재 턴 돌을 저장
	if (coor->x == 0 || coor->x == 1)										// 맨 왼쪽이면 검사 종료
		return (0);
	if (board[coor->y][coor->x - 1] == stone)								// 그 바로 앞도 검사 종료
		return (0);
	i = coor->x - 1;														// 검사 시작지점 현재 둔 돌에서 한 칸 왼쪽
	while (i >= 0)
	{
		if (board[coor->y][i] == '.')										// 빈칸이면 검사 종료
			return (0);
		if (board[coor->y][i] == stone)										// 같은 돌을 만나면
		{
			j = coor->x - 1;												// 검사 시작지점부터
			while (j > i && mode == 1)										// 모드가 1일때
			{
				board[coor->y][j] = tic_tok == 0 ? 'O' : 'X';				// 돌을 뒤집음
				j--;
			}
			return(1);
		}
		i--;
	}
	return (0);
}

int		left_upper_check(char **board, t_coordinate *coor, int tic_tok, int mode)	// 왼쪽 위 검사
{
	int i;
	int j;
	int k;
	int l;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';												// 현재 돌 저장
	if (coor->x == 0 || coor->x == 1 || coor->y == 0 || coor->y == 1)				// 맨 왼쪽과 맨 위쪽이면 검사 종료
		return (0);
	if (board[coor->y - 1][coor->x - 1] == stone)									// 맨 왼쪽 바로 전 칸도 검사 종료
		return (0);
	i = coor->x - 1;																// 검사 시작지점
	j = coor->y - 1;
	while (i >= 0 && j >= 0)														// 맨 왼쪽까지 검사
	{
		if (board[j][i] == '.')														// 빈칸이면 검사 종료
			return (0);
		if (board[j][i] == stone)													// 같은 돌을 만나면
		{
			k = coor->x - 1;														// 검사 시작지점부터
			l = coor->y - 1;
			while (k > i && l > j && mode == 1)										// mode가 1 일때
			{
				board[l][k] = tic_tok == 0 ? 'O' : 'X';								// 돌을 뒤집음
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

int		left_lower_check(char **board, t_coordinate *coor, int tic_tok, int mode)	// 왼쪽 아래 검사
{
	int i;
	int j;
	int k;
	int l;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';												// 현재 돌 저장
	if (coor->x == 0 || coor->x == 1 || coor->y == coor->m - 1 || coor->y == coor->m - 2) // 맨 왼쪽과 맨 아래쪽, 그 바로 앞도 검사 종료
		return (0);
	if (board[coor->y + 1][coor->x - 1] == stone)										// 현재 돌 왼쪽 아래 지점이 같은 돌이면 검사 종료
		return (0);
	i = coor->x - 1;																	// 검사 시작지점
	j = coor->y + 1;
	while (i >= 0 && j < coor->m)
	{
		if (board[j][i] == '.')															// 빈칸 만나면 검사 종료
			return (0);
		if (board[j][i] == stone)														// 현재 돌과 같은 돌을 만나면
		{
			k = coor->x - 1;															// 검사 시작 지점부터
			l = coor->y + 1;
			while (k > i && l < j && mode == 1)											// 모드가 1이면
			{
				board[l][k] = tic_tok == 0 ? 'O' : 'X';									// 돌을 뒤집음
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

int		eight_check(char **board, t_coordinate *coor, int tic_tok, int mode)	// 위에 8개 방향 검사를 모두 실행하는 함수
{
	int eight_flag[8];															// 검사 결과를 저장하는 배열 검사 결과 뒤집을 것이 있으면 1 없으면 0
	int i;

	i = 0;
	eight_flag[0] = right_check(board, coor, tic_tok, mode);					// 오른쪽 검사
	eight_flag[1] = right_upper_check(board, coor, tic_tok, mode);				// 오른쪽 위 검사
	eight_flag[2] = right_lower_check(board, coor, tic_tok, mode);				// 오른쪽 아래 검사
	eight_flag[3] = lower_check(board, coor, tic_tok, mode);					// 밑에쪽 검사
	eight_flag[4] = upper_check(board, coor, tic_tok, mode);					// 위쪽 검사
	eight_flag[5] = left_check(board, coor, tic_tok, mode);						// 왼쪽 검사
	eight_flag[6] = left_upper_check(board, coor, tic_tok, mode);				// 왼쪽 위 검사
	eight_flag[7] = left_lower_check(board, coor, tic_tok, mode);				// 왼쪽 아래 검사

	while (i < 8)
	{
		if (eight_flag[i] == 1)													// 만약에 1개라도 뒤집을 것이 있으면 TRUE(1) 반환
			return (TRUE);
		i++;
	}
	return (FALSE);																// 1개도 뒤집을 것이 없으면 FALSE(0) 반환
}
