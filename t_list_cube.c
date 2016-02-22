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
	ft_link_cube_lists(cube);
	cube->node_level = 0;
	cube->rotations = ft_list_create_empty();

	return (cube);
}

int 	ft_link_cube_lists(t_cube_lists *cube)
{
	int i;
	t_faces f;
	int type_cube;
	t_list_mini_cube *cur, *s;
	t_list_mini_cube *prev;

	cur = cube->elements[1];
	/** Link des centres **/
	for (i = 0; i < 6; ++i)
	{
		cube->starts[1][i] = cur;
		cur = cur->next[6];
	}
	/** Link des sommets: init de starts[0-5] et des next[0-5]  et previous[1-5]
	**/
	/** les cubes sommets **/
	/** face_f **/
	type_cube = 3;
	f = face_f;
	s = cube->elements[type_cube];
	cube->starts[type_cube][f] = s;
	cur = s;
	i = 0;
	while (i < 3)
	{
		cur->next[f] = cur->next[6];
		cur->next[f]->previous[f] = cur;
		cur = cur->next[f];
		++i;
	}
	cur->next[f] = s;
	s->previous[f] = cur;

	/** face_b **/
	f = face_b;
	s = cur->next[6];
	cube->starts[type_cube][f] = s;
	cur = s;
	i = 0;
	while (i < 3)
	{
		cur->next[f] = cur->next[6];
		cur->next[f]->previous[f] = cur;
		cur = cur->next[f];
		++i;
	}
	cur->next[f] = s;
	s->previous[f] = cur;

	/** Face U **/
	f = face_u;
	cube->starts[type_cube][f] = cur;
	cur->next[f] = cur->previous[face_b];
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];
	cur->previous[f] = prev;
	cur->next[f] = cube->starts[type_cube][face_f]->next[face_f];
	prev = cur;
	cur = cur->next[f];
	cur->previous[f] = prev;
	prev = cur;
	cur->next[f] = cube->starts[type_cube][face_f];
	cur = cur->next[f];
	cur->previous[f] = prev;
	cur->next[f] = cube->starts[type_cube][f];
	cur->next[f]->previous[f] = cur;


	/** Face D **/
	f = face_d;
	cube->starts[type_cube][f] = cube->starts[type_cube][face_f]->previous[face_f];
	cur->next[f] = cur->previous[face_f];
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];
	
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];
	cur->next[f] = cube->starts[type_cube][face_b]->next[face_b];
	cur->next[f] = cube->starts[type_cube][face_b];
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];
	cur->next[f] = cube->starts[type_cube][f];
	cur->next[f]->previous[f] = cur;

	
	/** Face L **/
	f = face_l;
	cur = cube->starts[type_cube][face_u];
	cube->starts[type_cube][f] = cur;
	cur->next[f] = cube->starts[type_cube][face_f];
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];
	cur->next[f] = cube->starts[type_cube][face_d];
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];
	cur->next[f] = cube->starts[type_cube][face_b];
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];
	cur->next[f] = cube->starts[type_cube][f];
	cur->next[f]->previous[f] = cur;

	/** Face R **/
	f = face_r;
	cur = cube->starts[type_cube][face_f]->next[face_f];
	cube->starts[type_cube][f] = cur;
	cur->next[f] = cube->starts[type_cube][face_u]->next[face_u];
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];
	cur->next[f] = cube->starts[type_cube][face_b]->next[face_b];
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];
	cur->next[f] = cube->starts[type_cube][face_d]->next[face_d];
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];
	cur->next[f] = cube->starts[type_cube][f];
	cur->next[f]->previous[f] = cur;

	/** Link des arretes **/

		/** face_f **/
	type_cube = 2;
	f = face_f;
	s = cube->elements[type_cube];
	cube->starts[type_cube][f] = s;
	cur = s;
	i = 0;
	while (i < 3)
	{
		cur->next[f] = cur->next[6];
		cur->next[f]->previous[f] = cur;
		cur = cur->next[f];
		++i;
	}
	cur->next[f] = s;
	s->previous[f] = cur;

	/** face_b **/
	f = face_b;
	s = cur->next[6];
	cube->starts[type_cube][f] = s;
	cur = s;
	i = 0;
	while (i < 3)
	{
		cur->next[f] = cur->next[6];
		cur->next[f]->previous[f] = cur;
		cur = cur->next[f];
		++i;
	}
	cur->next[f] = s;
	s->previous[f] = cur;

	/** Face U **/
	f = face_u;
	cur = cube->starts[type_cube][face_b]->next[face_b]->next[face_b];
	cube->starts[type_cube][f] = cur;
	cur->next[f] = cube->starts[type_cube][face_b]->previous[face_b]->next[6];
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];
	cur->next[f] = cube->starts[type_cube][face_f];
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];
	cur->next[f] = cube->starts[type_cube][f]->next[f]->next[6];
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];
	cur->next[f] = cube->starts[type_cube][f];
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];

	/** Face D **/
	f = face_d;
	cur = cube->starts[type_cube][face_f]->next[face_f]->next[face_f];
	cube->starts[type_cube][f] = cur;
	cur->next[f] = cube->starts[type_cube][face_u]->previous[face_u]->next[6];
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];
	cur->next[f] = cube->starts[type_cube][face_b];
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];
	cur->next[f] = cube->starts[type_cube][f]->next[f]->next[6];
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];
	cur->next[f] = cube->starts[type_cube][f];
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];

	/** Face L **/
	f = face_l;
	cur = cube->starts[type_cube][face_u]->previous[face_u];
	cube->starts[type_cube][f] = cur;
	cur->next[f] = cube->starts[type_cube][face_f]->previous[face_f];
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];
	cur->next[f] = cube->starts[type_cube][face_d]->previous[face_d];
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];
	cur->next[f] = cube->starts[type_cube][face_b]->previous[face_b];
	cur->next[f]->previous[f] = cur;
	cur = cur->next[f];
	cur->next[f] = cube->starts[type_cube][face_u]->previous[face_u];
	cur->next[f]->previous[f] = cur;

	/** Face R **/
	f = face_r;
	cur = cube->starts[type_cube][face_u]->next[face_u];
	cube->starts[type_cube][f] = cur;
	prev = cur;
	cur->next[f] = cube->starts[type_cube][face_b]->next[face_b];
	cur = cur->next[f];
	cur->previous[f] = prev;
	prev = cur;
	cur->next[f] = cube->starts[type_cube][face_d]->next[face_d];
	cur = cur->next[f];
	cur->previous[f] = prev;
	prev = cur;
	cur->next[f] = cube->starts[type_cube][face_f]->next[face_f];
	cur = cur->next[f];
	cur->previous[f] = prev;
	prev = cur;
	cur->next[f] = cube->starts[type_cube][face_u]->next[face_u];
	cur = cur->next[f];
	cur->previous[f] = prev;

	return (EXIT_SUCCESS);	
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

int ft_adt_cube(t_cube_lists *cube, int f, int i, int j)
{

	int access, ind_f, ind[2][4], count;
	t_list_mini_cube *begin, *cur;

	if (i == 1 && j == 1)
		return (cube->starts[1][f]->mini_cube[0]);
	begin = cube->starts[3 - ((i + j) % 2)][f];
	
	if (!((i + j) % 2))
	{
		/** 3 elts **/
		if (f == face_b || f == face_f)
			access = 0;
		else if (f == face_u || f == face_d)
			access = 1;
		else
			access = 2;
	}
	else
	{	
		/** 2 elts **/
		if (f == face_b || f == face_f || ((f == face_u || f == face_d) && i == 1))
			access = 0;
		else
			access = 1;
	}
	ind[0][0] = 0;
	ind[0][1] = 2;
	ind[0][2] = 22;
	ind[0][3] = 20;
	ind[1][0] = 1;
	ind[1][1] = 12;
	ind[1][2] = 21;
	ind[1][3] = 10;
	ind_f = i * 10 + j;
	count = 0;
	cur = begin;
	while (ind[(i + j) % 2][count] != ind_f)
	{
		++count;
		cur = cur->next[f];
	}
	return (cur->mini_cube[access]);
}

int ft_adt_cube_ecrire(t_cube_lists *cube, int f, int i, int j, int c)
{	

	int access, ind_f, ind[2][4], count;
	t_list_mini_cube *begin, *cur;

	if (i == 1 && j == 1)
	{	cube->starts[1][f]->mini_cube[0] = c;
		return (cube->starts[1][f]->mini_cube[0]);
	}
	begin = cube->starts[3 - ((i + j) % 2)][f];
	if (!((i + j) % 2))
	{
		/** 3 elts **/
		if (f == face_b || f == face_f)
			access = 0;
		else if (f == face_u || f == face_d)
			access = 1;
		else
			access = 2;
	}
	else
	{	
		/** 2 elts **/
		if (f == face_b || f == face_f || ((f == face_u || f == face_d) && i == 1))
			access = 0;
		else
			access = 1;
	}
	ind[0][0] = 0;
	ind[0][1] = 2;
	ind[0][2] = 22;
	ind[0][3] = 20;
	ind[1][0] = 1;
	ind[1][1] = 12;
	ind[1][2] = 21;
	ind[1][3] = 10;
	ind_f = i * 10 + j;
	count = 0;
	cur = begin;
	while (ind[(i + j) % 2][count] != ind_f)
	{
		++count;
		cur = cur->next[f];
	}
	cur->mini_cube[access] = c;
	return (cur->mini_cube[access]);

}