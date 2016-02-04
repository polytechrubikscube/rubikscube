/** 
 **         ////////    |   /__/__/__/ 
 **        ///   ///    |  |__|__|__|/  Le Rubik's Cube
 **       ///   ///     |  |__|__|__|/    Projet d'Algorithmie - INFO 3A
 **      ////////       |  |__|__|__|/      2015 - 2016
 **     ///olytech      |                                CONNET Cyprien
 **    ///   Marseille  |                                GUZZI  Olivier
 ** ######################################################################
 **  Nom du fichier       : lecture_fichier.c
 **  Date de création     : Le 20 Décembre 2015 à 10h00
 **  Date de modification : Le 24 Décembre 2015 à 13h00
 **/

#include "rubikscube.h"

/** void	*ft_error(int e)
{
	printf ("Error\t");
	switch (e)
	{
		case 1:
			printf("File Reading Error");
	}
	return (NULL);
} **/

t_cube	*ft_read_file(char *path)
{
	int fd;
	int cur_color;
	int cur_face;
	int line;
	int col;
	int index;
	ssize_t size;
	char *buff;
	t_cube *cube;

	/** Ouverture du fichier et récupération du file descriptor **/
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		print_f("File Reading Error\n");
		return (NULL);
	}

	/** Initialisation du buffer **/
	buff = (char *)malloc(size_t(char) * BUFF_SIZE + 1);
	for (index = 0; index <= BUFF_SIZE; index++)
		buff[index] = '\0';

	/** Lecture du fichier **/
	size = read(fd, buff, BUFF_SIZE);
	if (size <= 0)
	{
		printf("File Reading Error. Not found or corrupt.");
		return (NULL);
	}
	if (size != 78)
	{
		printf("File Reading Error [2]\n");
		printf("Please control the format of your file.\n");
		printf("\'bbb.bbb.bbb.\\n\' for each face without any\nspace");
		printf(" (78 char, do not miss the last \\n).\n");
		return (NULL);
	}
	
	/** Traitement du buffer **/
	cube = ft_new_cube();
	for (index = 0; index <= size; size ++)
	{
		cur_color = ft_char_to_color(buff[index]);
		if (cur_color >= 0)
			cube->faces[cur_face][line][col] = cur_color;
		else
		{
			printf("File Reading Error [bad color]");
			return (NULL);
		}

		/** On incrémente les indices de face, 
			colonne et ligne puis on oublie
			les caractères de mise en forme.
		 **/			
		col++;
		line = line + col / 3;
		if (col / 3 && buff[index + 1] == '.')
			++index;
		else if (col / 3)
		{
			printf("File Reading Error [2]\n");
			printf("Please control the format of your file.\n");
			printf("\'bbb.bbb.bbb.\\n\' for each face without any space");
			printf(" or new line.\n");
			return (NULL);
		}
		col = col % 3;
		cur_face = cur_face + line / 3;
		if (line / 3 && buff[index + 1] == '\n')
			++index;
		else if (line / 3)
		{
			printf("File Reading Error [2]\n");
			printf("Please control the format of your file.\n");
			printf("\'bbb.bbb.bbb.\\n\' for each face without any space");
			printf(" or new line.\n");
			return (NULL);
		}
		line = line % 3;
	}

	return (cube);	
} 

