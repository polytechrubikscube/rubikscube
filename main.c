#include "rubikscube.h"

int	main(int argc, char **argv)
{
	t_cube_lists *cube;

	if (argc != 2)
	{
		printf("Error, please enter a file path.\n");
		return (EXIT_FAILURE);
	}
	
	 cube = ft_read_file(argv[1]);
	 	ft_print_cube(cube);
	 printf("%d, %d, %d\n", cube->starts[3][face_d]->next[face_d]->mini_cube[0], cube->starts[3][face_d]->next[face_d]->mini_cube[1], cube->starts[3][face_d]->next[face_d]->mini_cube[2]);
	 printf("%d, %d\n", cube->starts[2][face_l]->next[face_l]->mini_cube[0],
	 	cube->starts[2][face_l]->next[face_l]->mini_cube[1]);
	 	 printf("%d, %d\n", cube->starts[2][face_l]->previous[face_l]->previous[face_l]->mini_cube[0],
	 	cube->starts[2][face_l]->previous[face_l]->previous[face_l]->mini_cube[1]);
	 	 	 printf("%d, %d\n", cube->starts[2][face_l]->previous[face_l]->previous[face_l]->previous[face_l]->mini_cube[0],
	 	cube->starts[2][face_l]->previous[face_l]->previous[face_l]->previous[face_l]->mini_cube[1]);
	 	 	 printf("%d, %d\n", cube->starts[2][face_l]->previous[face_l]->previous[face_l]->previous[face_l]->previous[face_l]->mini_cube[0],
	 	cube->starts[2][face_l]->previous[face_l]->previous[face_l]->previous[face_l]->previous[face_l]->mini_cube[1]);
	 	 	ft_cube_lists_rot(cube, rot_f);
	 printf("%d, %d, %d\n", cube->starts[3][face_d]->next[face_d]->mini_cube[0], cube->starts[3][face_d]->next[face_d]->mini_cube[1], cube->starts[3][face_d]->next[face_d]->mini_cube[2]);
	 printf("%d, %d, %d\n", cube->starts[3][face_d]->next[face_d]->next[face_d]->mini_cube[0], cube->starts[3][face_d]->next[face_d]->next[face_d]->mini_cube[1], cube->starts[3][face_d]->next[face_d]->next[face_d]->mini_cube[2]);

	ft_print_cube(cube);
	return (EXIT_SUCCESS);
}
