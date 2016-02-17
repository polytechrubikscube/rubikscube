#include "rubikscube.h"

void	ft_swap2(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_swap3(int *a, int *b, int *c)
{
	int tmp;

	tmp = *a;
	*a = *c;
	*c = *b;
	*b = tmp;
}

void	ft_swap4(int *a, int *b, int *c, int *d)
{
	int tmp;

	tmp = *a;
	*a = *d;
	*d = *c;
	*c = *b;
	*b = tmp;
}

void ft_rot_face(t_face face)
{
	/** Rotation horaire de la face pointée **/
	/** 0 1 2	6 7 0
	    7 8 3   ==> 5 8 1
	    6 5 4	4 3 2
	**/
	
}

void ft_rot_f(t_cube *cube);
void ft_rot_frev(t_cube *cube);
void ft_rot_f2(t_cube *cube);
void ft_rot_b(t_cube *cube);
void ft_rot_brev(t_cube *cube);
void ft_rot_b2(t_cube *cube);
void ft_rot_u(t_cube *cube);
void ft_rot_urev(t_cube *cube);
void ft_rot_u2(t_cube *cube);
void ft_rot_d(t_cube *cube);
void ft_rot_drev(t_cube *cube);
void ft_rot_d2(t_cube *cube);
void ft_rot_l(t_cube *cube);
void ft_rot_lrev(t_cube *cube);
void ft_rot_l2(t_cube *cube);
void ft_rot_r(t_cube *cube);
void ft_rot_rrev(t_cube *cube);
void ft_rot_r2(t_cube *cube);
