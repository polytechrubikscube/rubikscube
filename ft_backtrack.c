#include "rubikscube.h"
#define CRD cube->rotations->data
#define CR cube->rotations

int	ft_is_equal_to_one_of_3(char i, char a, char b, char c)
{
	return ((a == i) || (b == i) || (c == i));
}

int	ft_is_equal_to_one_of_6(char i, char a, char b, char c, char d, char e, char f)
{
	return ((a == i) || (b == i) || (c == i) || (d == i) || (e == i) || (f == i));
}


t_list	*ft_determine_movs(t_cube_lists *cube)
{
	t_list *movs;
	char last_mov;

	movs = ft_list_create_empty();
	if (CR != ft_list_create_empty())
		last_mov = CRD;
	if (!ft_is_equal_to_one_of_6(last_mov, rot_b, rot_brev, rot_b2, rot_f, rot_frev, rot_f2))
	{
		movs = ft_list_add_head(movs, rot_b); 
		movs = ft_list_add_head(movs, rot_b2); 
		movs = ft_list_add_head(movs, rot_brev); 
	}
	if (!ft_is_equal_to_one_of_3(last_mov, rot_f, rot_frev, rot_f2))
	{
		movs = ft_list_add_head(movs, rot_f); 
		movs = ft_list_add_head(movs, rot_f2); 
		movs = ft_list_add_head(movs, rot_frev); 
	}
	if (!ft_is_equal_to_one_of_6(last_mov, rot_r, rot_rrev, rot_r2, rot_l, rot_lrev, rot_l2))
	{
		movs = ft_list_add_head(movs, rot_l); 
		movs = ft_list_add_head(movs, rot_l2); 
		movs = ft_list_add_head(movs, rot_lrev); 
	} 
	if (!ft_is_equal_to_one_of_3(last_mov, rot_r, rot_rrev, rot_r2))
	{
		movs = ft_list_add_head(movs, rot_r); 
		movs = ft_list_add_head(movs, rot_r2); 
		movs = ft_list_add_head(movs, rot_rrev); 
	}
	if (!ft_is_equal_to_one_of_6(last_mov, rot_u, rot_urev, rot_u2, rot_d, rot_drev, rot_d2))
{
		movs = ft_list_add_head(movs, rot_d); 
		movs = ft_list_add_head(movs, rot_d2); 
		movs = ft_list_add_head(movs, rot_drev); 
	}
	if (!ft_is_equal_to_one_of_3(last_mov, rot_u, rot_urev, rot_u2))
{
		movs = ft_list_add_head(movs, rot_u); 
		movs = ft_list_add_head(movs, rot_u2); 
		movs = ft_list_add_head(movs, rot_urev); 
	}
	return (movs);
}

int	ft_backtrack(t_cube_lists *cube)
{
	t_list *movs;
	int stop;

	if (ft_forbidden_set(cube))
		return (-1);
	if (ft_lists_cube_is_solved(cube))
		/** Le backtrack est terminée la solution est contenue dans le cube passé en param **/
		return (1);
	if (cube->node_level > 29)
		return (0);
	movs = ft_determine_movs(cube);

	while (movs && !stop)
	{
		ft_lists_rot(cube, ft_list_head(movs)); 
		/** On fait la rot, on ajoute la rot a la liste, on incremente la profondeur du noeud **/
		
		if (!stop = ft_backtrack(cube));
		{
			ft_lists_rot_del_last(cube);
			/** On annule le dernier ft_lists_rot **/
			movs = ft_list_del_head(movs);
			/** On supprime la tete de la liste movs **/
		}
	}
	/** Le backtrack termine sans solution **/
	return (stop); 
}

int	ft_cube_is_solved(t_cube_lists *cube)
{
	while (cube->
}

int	ft_forbidden_set(t_cube_lists *cube)
{
	int forbidden;

	forbidden = 0;
	return (forbidden)
}
