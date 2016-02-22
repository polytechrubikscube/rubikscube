#include "rubikscube.h"

int	ft_cube_lists_rot(t_cube_lists *cube, int rot)
{
	t_list_mini_cube *cur, *start;
	char *tmp, tmp2;
	int i, ind, tmp_c, index;

	if (rot / 6 == 0)
	{
		if (rot == rot_f || rot == rot_b)
			ind = 0;
		else if(rot == rot_u || rot == rot_d)
			ind = 1;
		else
			ind = 2;

		/** rot dans le sens horaire **/
		i = 2;
		while (i < 4)
		{
			index = 0;
			cur = cube->starts[i][rot];
			start = cur;
			tmp = start->mini_cube;
			while (index < 3)
			{
				cur->mini_cube = cur->previous[rot]->mini_cube;
				if (i == 3)
				{
					tmp_c = cur->mini_cube[(ind+1)%3];
					cur->mini_cube[(ind + 1)%3] = cur->mini_cube[(ind+2) %3];
					cur->mini_cube[(ind+2)%3] = tmp_c;
				}
				else if (i == 2 && rot != rot_f && rot != rot_b)
				{
					tmp_c = cur->mini_cube[0];
					cur->mini_cube[0] = cur->mini_cube[1];
					cur->mini_cube[1] = tmp_c;
				}
				cur = cur->previous[rot];
				index++;
			}
			cur->mini_cube = tmp;
			if (i == 3)
				{
					tmp_c = cur->mini_cube[(ind+1)%3];
					cur->mini_cube[(ind + 1)%3] = cur->mini_cube[(ind+2) %3];
					cur->mini_cube[(ind+2)%3] = tmp_c;
				}
				else if (i == 2 && rot != rot_f && rot != rot_b)
				{
					tmp_c = cur->mini_cube[0];
					cur->mini_cube[0] = cur->mini_cube[1];
					cur->mini_cube[1] = tmp_c;
				}
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

