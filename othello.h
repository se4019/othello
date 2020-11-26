#include <stdio.h>				//stdio.h ����
#include <stdlib.h>				//stdlib.h ����

#define TRUE 1					//TRUE = 1 ����
#define FALSE 0					//FALSE = 0 ����

typedef struct	s_coordinate	//����ü ����
{
	unsigned int n;				//Nũ�� ����
	unsigned int m;				//Mũ�� ����
	unsigned int x;				//�� �ϸ��� �Է¹޴� X
	unsigned int y;				//�� �ϸ��� �Է¹޴� Y
}				t_coordinate;	//����ü ���� ����

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
