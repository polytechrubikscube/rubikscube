#include "rubikscube.h"

int	ft_char_to_color(char c)
{
	switch (c)
	{
		case 'r':
			return (r);
			break ;
		case 'g':
			return (g);
			break ;
		case 'b':
			return (b);
			break ;
		case 'w':
			return (w);
			break ;
		case 'o':
			return (o);
			break ;
		case 'y':
			return (y);
			break ;
		default :
			printf("Erreur \'%c\' n'est pas une couleur valide.\n", c);
			return (-1);
	}
}

char	ft_color_to_char(int c)
{
	switch (c)
	{
		case r:
			return ('r');
			break ;
		case g:
			return ('g');
			break ;
		case b:
			return ('b');
			break ;
		case w:
			return ('w');
			break ;
		case o:
			return ('o');
			break ;
		case y:
			return ('y');
			break ;
		default :
			printf("Erreur \'%d\' n'est pas une couleur valide. [0..5]\n", c);
			return (-1);
	}
}

void	ft_print_cube(t_cube_lists *cube)
{
	int cur_face;
	int cur_line;
	int cur_col;

	for (cur_col = 0; cur_col < 4; cur_col++)
		printf("___");
	printf("\n");

	for (cur_face = 0; cur_face < 6; cur_face++)
	{
		for (cur_line = 0; cur_line < 3; cur_line++)
		{
			printf("||");
			for (cur_col = 0; cur_col < 3; cur_col++)
				printf(" %c |", ft_color_to_char(ft_adt_cube(cube, cur_face, cur_line, cur_col)));
			printf("|\n");
		}
		for (cur_col = 0; cur_col < 4; cur_col++)
			printf("____");
		printf("\n");
	}
	
}
