int	main(int argc, char **argv)
{
	t_cube *cube;

	if (argc != 2)
	{
		printf("Error, 1 argument est demandé");
		return (EXIT_FAILURE);
	}
	
	cube = ft_read_file(argv[1]);

	ft_afficher_cube(cube);
	return (EXIT_SUCCESS);
}
