#include "rubikscube.h"

int	ft_croix_blanche_remonter_face_b(t_cube_lists *cube)
{
	int f_count, count;
	t_list_mini_cube *begin, *cur;
	/** !! Attention a remonter sur une partie de f libre de blanc
	t_list_mini_cube *cur, *begin;
	int count, f_count;

	begin = cube->starts[2][face_b];
	count = 0;
	/*
	** On chercher la couleur blanche sur la face b. Sens de lecture b = position 0 de la chaine
	*/
	cur = begin;
	while (cur->mini_cube[0] != w && count < 3)
	{
		cur = cur->next[face_b];
		++count;
	}
	if (cur->mini_cube[0] != w)
		return (0);
	switch (cur->mini_cube[1]){
		case b:
			f_count = 2;
			break ;
		case r:
			f_count = 1;
			break ;
		case g:
			f_count = 0;
			break ;
		case o:
			f_count = 3;
			break ;
	}
	while (count % 4 != f_count)
	{
		ft_cube_lists_rot(cube, rot_b);
		++count;
	}
	switch (f_count){
		case 2:
			ft_cube_lists_rot(cube, rot_u2);
			break ;
		case 1:
			ft_cube_lists_rot(cube, rot_r2);
			break ;
		case 0:
			ft_cube_lists_rot(cube, rot_d2);
			break ;
		case 3:
			ft_cube_lists_rot(cube, rot_l2);
			break ;
	}
	return (1);
}

int ft_croix_blanche_ok(t_cube_lists *cube)
{
	t_list_mini_cube *begin, *cur;
	int count, f_count;

	begin = cube->starts[2][face_b];
	cur = begin;
	count = 0;
	f_count = -1;
	/*
	**	Detecte si la croix blanche est terminée.
	**	Retoune 1 si c'est le cas, 0 sinon.
	*/

	/*
	**	Sens de lecture de la face f, mini_cube[0]
	*/

	while (cur->mini_cube[0] == w && cur->next[face_f] != begin && count == f_count + 1)
	{
		switch (cur->mini_cube[1])
		{
			case b:
			f_count = 0;
			break ;
		case r:
			f_count = 1;
			break ;
		case g:
			f_count = 2;
			break ;
		case o:
			f_count = 3;
			break ;
			
		}
		++count;
		cur = cur->next[face_f];
	}
	if (cur->mini_cube[0] != w || cur->next[face_f] != begin || f_count + 1 != count)
		return (0);

	return (1);
}

int ft_croix_blanche_presence_face_b(t_cube_lists *cube)
{
	t_list_mini_cube *begin, *cur;

	begin = cube->starts[2][face_b];
	cur = begin;
	while (cur->mini_cube[0] != w && cur != begin)
		cur = cur->next[face_b];
	if (cur == begin)
		return (0);
	return (1);
}

int ft_croix_blanche_descendre_face_b(t_cube_lists *cube)
{
	t_list_mini_cube * begin, *cur;
	int count, f_count2, f;
	int f_count[6];
/** Si on detecte un cube bien place, alors on reaplique le mvt inverse apres **/

	f_count[b] = 0;
	f_count[r] = 1;
	f_count[g] = 2;
	f_count[o] = 3;

	f = face_f;
	count = 0;
	f_count2 = 0;
	begin = cube->starts[2][f];
	cur = begin;

	while (cur->next[f] != begin && (cur->mini_cube[0] != w || count == f_count[cur->mini_cube[1]]))
	{
		cur = cur->next[f];
		++count;
	}
	if (cur->mini_cube[0] == w && count != f_count[cur->mini_cube[1]])
	{
		f_count2 = f_count[cur->mini_cube[1]];
		while (count % 4 != f_count2)
		{
			ft_cube_lists_rot(cube, rot_f);
			++count;
		}
	}
	/** ! a ne faire que pour la premiere puis faire passer en dessous ! **/


	return (1);
}

int ft_croix_blanche(t_cube_lists *cube)
{
	/*  Cube en entrée quelconque. 
	**	Centre Face_f: W, Centre Face_U: B, Centre Face_R: R
	*/

	while (!ft_croix_blanche_ok(cube))
	{
		while (!ft_croix_blanche_presence_face_b(cube))
		{
			ft_croix_blanche_descendre_face_b(cube);
		}
		ft_croix_blanche_remonter_face_b(cube);
	}

	/*
	**	Cube en sortie: Croix Blanche sur Face_F
	*/
	return (1);
}