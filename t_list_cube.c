#include "rubikscube.h"

t_cube_lists	*ft_init_cube_lists(void)
{
	int i;

	t_cube_lists *cube;

	cube = (t_cube_lists *)NULL;
	cube = (t_cube_lists *)malloc(sizeof(t_cube_lists));

	if (!cube)
		return (ft_error(10));

	cube->elements[0] = (t_list_mini_cube *)NULL;
	for (i = 1; i < 4; i++)
		cube->elements[i] = ft_init_list_mini_cube(i);
	cube->node_level = 0;
	cube->rotations = ft_list_create_empty();
	return (cube);
}

char	*ft_list_mini_cube_create(i)
{
	char *mini_cube;

	mini_cube = (char *)malloc(sizeof(char) * i);
	if (!mini_cube)
		return (ft_error(10));
	while (i)
		mini_cube[--i] = '\0';
	return (mini_cube);
}

/** Add elt at the head of the list **/
t_list_mini_cube	*ft_list_mini_cube_add_head(t_list_mini_cube *list, char *mini_cube)
{
	t_list_mini_cube *container;

	container = (t_list_mini_cube *)malloc(sizeof(t_list_mini_cube));
	if (!container)
		return (ft_error(10));
	container->mini_cube = mini_cube;
	if (list == (t_list_mini_cube *)NULL)
	{
		container->next[6] = container;
		container->previous[6] = container;
	}
	else
	{
		container->next[6] = list;
		container->previous[6] = list->previous[6];
		list->previous[6] = container;
		container->previous[6]->next[6] = container;
	}
	return (container);
}

t_list_mini_cube	*ft_init_list_mini_cube(int i)
{
	t_list_mini_cube *list_cube;
	int count;

	if (i == 1)
		count = 6;
	else if (i == 2)
		count = 12;
	else if (i == 3)
		count = 8;
	else
		return (ft_error(8));
	list_cube = (t_list_mini_cube *)NULL;
	while (count)
	{
		list_cube = ft_list_mini_cube_add_head(list_cube, ft_list_mini_cube_create(i));
		--count;
	}
	return (list_cube);
}
