#include "othello.h"								// othello.h 헤더 입력

int main(void)
{
	int i;
	int j;
	t_coordinate coor;								// 구조체 선언
	int tic_tok;									// 현재 턴
	char **board;									// 보드 이중포인터

	input_coordinate(&coor, 0);						// N x M 입력받아 구조체에 저장하는 함수

	board = malloc(sizeof(char *) * (coor.m));		// N M사이즈 보드를 동적할당으로 필요한 만큼만 2차원 배열로 메모리 지정
	for (i = 0 ; i < coor.m ; i++)					// M 열만큼 반복
	{
		board[i] = malloc(sizeof(char) * (coor.n)); // M개의 열에 N개의 행만큼 동적할당
		for (j = 0 ; j < coor.n ; j++)				// N번 반복하며 각 행열에 '.' 입력 '.'은 빈칸으로 사용함
		{
			board[i][j] = '.';
		}
	}

	set_board(board, coor);							// 초기 게임 설정
	print_board(board, coor);						// 보드를 출력하면서 게임 시작

	tic_tok = 0;									// 0 = O, 1 = X로 설정하여 O부터 게임시작

	while (1)
	{
		if (turn_check(board, &coor, tic_tok) == FALSE)		// 게임에 각 턴마다 놓을 수 있는 자리가 있는지 확인
			tic_tok = tic_tok == 0 ? 1 : 0;					// 없으면 턴 바꿈
		blank_OX_check(board, &coor);
		printf("turn : %c\n", tic_tok == 0 ? 'O' : 'X');	// 어떤 돌의 차례인지 출력
		while (1)											// 게임이 끝날 때까지 계속 반복
		{
			input_coordinate(&coor, 1);						// x, y입력을 받음
															// 입력받은 x,y가 빈칸인지 체크하고 8방향을 검사해 돌을 뒤집음
			if (board[coor.y][coor.x] == '.' && eight_check(board, &coor, tic_tok, 1) == TRUE)
			{
				board[coor.y][coor.x] = tic_tok == 0 ? 'O' : 'X';		// 선택한 X, Y을 빈칸에서 돌로 바꾸어 줌
				tic_tok = tic_tok == 0 ? 1 : 0;							// 턴 변경
				break;													// 반복문 종료
			}
			else
				printf("여기에는 둘 수 없습니다.\n");						// 만약 둘 수 없는 곳이면 출력하고 다시 반복문이 돌아 입력 받음
		}
		print_board(board, coor);										// 바뀐 보드를 출력함
	}
	end_game(board, coor);												// 게임이 끝나면 집계를 한다.
	return (0);															// 0 반환
}


