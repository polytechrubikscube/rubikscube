#include "rubikscube.h"

int	ft_cube_lists_rot(t_cube_lists *cube, int rot)
{
	t_list_mini_cube *cur, start;
	char *tmp, tmp2;
	int i;

	if (rot / 6 == 0)
	{
		/** rot dans le sens horaire **/
		i = 2;
		while (i < 4)
		{
			cur = cube->starts[i][rot];
			start = cur;
			tmp = start->mini_cube;
			while (cur->previous[rot] != start)
			{
				cur->mini_cube = cur->previous[rot]->mini_cube;
				cur = cur->previous[rot];
			}
			cur->mini_cube = tmp;
			i++;
		}
		cube->rotations = ft_list_add_head(cube->rotations, (char)rot);
		return (rot);
	}
	else if (rot / 6 == 1)
	{
		/** rot demi tour **/
		cube->rotations = ft_list_add_head(cube->rotations, (char)rot);
		rot = rot % 6;	
		i = 2;
		while (i < 4)
		{
			cur = cube->starts[i][rot];
			tmp = cur->mini_cube;

			cur->mini_cube = cur->previous[rot]->previous[rot]->mini_cube;
			cur->previous[rot]->previous[rot]->mini_cube = tmp;
			cur = cur->previous[rot];
			tmp = cur->mini_cube;
			cur->mini_cube = cur->previous[rot]->previous[rot]->mini_cube;
			cur->previous[rot]->previous[rot]->mini_cube = tmp;
			i++;
		}
		return ((int) ft_list_head(cube->rotations));
	}
	else if (rot / 6 == 2)
	{
		/** rot_rev **/
		cube->rotations = ft_list_add_head(cube->rotations, (char)rot);
		rot = rot % 6;
		i = 2;
		while (i < 4)
		{
			cur = cube->starts[i][rot];
			start = cur;
			tmp = start->mini_cube;
			while (cur->next[rot] != start)
			{
				cur->mini_cube = cur->next[rot]->mini_cube;
				cur = cur->next[rot];
			}
			cur->mini_cube = tmp;
			i++;
		}
		return ((int) ft_list_head(cube->rotations));
	}
	return (EXIT_FAILURE);
}

/** Var, return, petite rotations
remplissage et saisie puis affichage
finir le backtrack et les differents reperages
finir le mecanique
 **/
