#include "rubikscube.h"

int	main(int argc, char **argv)
{
	t_cube *cube;

	if (argc != 2)
	{
		printf("Error, please enter a file path.\n");
		return (EXIT_FAILURE);
	}
	
	cube = ft_read_file(argv[1]);

	ft_print_cube(cube);
	return (EXIT_SUCCESS);
}
