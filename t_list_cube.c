#include "rubikscube.h"


typedef struct s_list_mini_cube
{
	char		  color;
	s_list_mini_cube *previous;
	s_list_mini_cube *next;
}		t_list_mini_cube;

typedef struct s_list_cube
{
/**	char			type;		// type : 0 -> undef, 1, 2, 3 colors **/
	t_list_mini_cube 	*mini_cube;
	struct s_list_cube 	*previous[6];
	struct s_list_cube 	*next[6];
}		t_list_cube;

typedef struct s_cube_lists
{
	t_list_cube *elements[4];  /** elements [0] -> NULL / [1] -> 1 color by element  / [2] -> ... / [3] -> .. **/
	t_list	    *rotations;
	int	     node_level;
}		t_cube_lists;

t_cube_lists	*ft_init_cube_lists(void)
{
	int i;

	t_cube_lists *cube;

	cube = (t_cube_lists *)NULL;
	cube = (t_cube_lists *)malloc(sizeof(t_cube_lists));
	
	if (!cube)
		return (ft_error(10));

	cube->elements[0] = (t_list *)NULL;
	for (i = 1; i < 4; i++)
		cube->elements[i] = ft_init_list_cube(i);
	cube->node_level = 0;
	cube->rotations = ft_list_create_empty();
	return (cube);
}

t_list_cube	*ft_init_list_cube(int i)
{
	t_list_cube *list_cube;

	list_cube = ft_list_cube_empty();
	while (i)
	{
		list_cube = ft_list_cube_add_head(list_cube, ft_mini_cube_create());
		i--;
	}
	return (list_cube);
}
