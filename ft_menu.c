#include "rubikscube.h"

int	ft_print_menu(void){
	printf("################################################\n");
	printf("#######          RUBIK'S CUBE 2016       #######\n");
	printf("################################################\n");
	printf("####                  MENU                  ####\n");
	printf("################################################\n");
	printf("Entree/Sortie du cube......................... 1\n");
	printf("Rotations..................................... 2\n");
	printf("Resolution Mecanique.......................... 3\n");
	printf("Resolution par Backtrack...................... 4\n");
	printf("Quitter le programme.......................... 5\n");
	printf("################################################\n");
	return (1);

}
int	ft_afficher_solution_backtrack(t_cube_lists *cube)
{
	ft_print_cube(cube);
	return (1);
}

int ft_switch_menu (int choice, t_cube_lists *cube)
{
	switch (choice)
	{
		case 1:
			/**ft_menu_e_s_cube();**/
			break ;
		case 2:
			break ;
		case 3:
			break ;
		case 4:
			if (!cube)
				printf("Vous devez saisir un cube !\n");
			else
			{
				if (ft_backtrack(cube))
					ft_afficher_solution_backtrack(cube);
				else
					printf("Le cube saisie n'a pas été résolu !\n");
			}
			break ;
		case 5:
			printf("A bientot !\n");
			break ;
		default:
			choice = 10;
	}
	return (choice);
}

int ft_read_choice(void){
	int choice;

	fseek(stdin, 0, SEEK_END);
	scanf("%d", &choice);
	return (choice);
}

int	ft_print_header(void){
	printf("         ////////    |   /__/__/__/ \n");
	printf("        ///   ///    |  |__|__|__|/  Le Rubik's Cube\n");
	printf("       ///   ///     |  |__|__|__|/    Projet d'Algorithmie - INFO 3A\n");
	printf("      ////////       |  |__|__|__|/      2015 - 2016\n");
	printf("     ///olytech      |                                CONNET Cyprien\n");
	printf("    ///   Marseille  |                                GUZZI  Olivier\n");
	printf(" ######################################################################\n");
	return (1);
}

int ft_use_menu(t_cube_lists *cube)
{
	int choice, first;

	first = 1;
	ft_print_header();
	ft_print_menu();
	choice = 0;
	while (choice != 5)
	{
		if (!first && (choice > 5 || choice < 0))
			printf("Votre choix est erroné, veuillez saisir un autre choix.\n");
		else if (first)
			first = 0;
		else
		{
			ft_print_header();
			ft_print_menu();
		}
		choice = ft_read_choice();
		ft_switch_menu(choice, cube);
	}
	return (choice);
}