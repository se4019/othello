#include <stdio.h>				//stdio.h 삽입
#include <stdlib.h>				//stdlib.h 삽입

#define TRUE 1					//TRUE = 1 설정
#define FALSE 0					//FALSE = 0 설정

typedef struct	s_coordinate	//구조체 선언
{
	unsigned int n;				//N크기 저장
	unsigned int m;				//M크기 저장
	unsigned int x;				//매 턴마다 입력받는 X
	unsigned int y;				//매 턴마다 입력받는 Y
}				t_coordinate;	//구조체 별명 설정

// input.c
void	input_coordinate(t_coordinate *coor, int mode);
void	set_board(char **board, t_coordinate coor);

//eight_check.c
int		right_check(char **board, t_coordinate *coor, int tic_tok, int mode);
int		right_upper_check(char **board, t_coordinate *coor, int tic_tok, int mode);
int		right_lower_check(char **board, t_coordinate *coor, int tic_tok, int mode);
int		lower_check(char **board, t_coordinate *coor, int tic_tok, int mode);
int		upper_check(char **board, t_coordinate *coor, int tic_tok, int mode);
int		left_check(char **board, t_coordinate *coor, int tic_tok, int mode);
int		left_upper_check(char **board, t_coordinate *coor, int tic_tok, int mode);
int		left_lower_check(char **board, t_coordinate *coor, int tic_tok, int mode);
int		eight_check(char **board, t_coordinate *coor, int tic_tok, int mode);

//board_check.c
int		turn_check(char **board, t_coordinate *coor, int tic_tok);
int		blank_OX_check(char **board, t_coordinate *coor);

//print.c
void	print_board(char **board, t_coordinate coor);

//end.c
void	free_board(char **board, t_coordinate coor);
void	end_game(char **board, t_coordinate coor);
