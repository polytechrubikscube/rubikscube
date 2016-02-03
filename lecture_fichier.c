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

t_cube	*ft_read_file(char *path)
{
	int fd;
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
	if (size <= 0 || size > 79)
	{
		printf("File Reading Error [2]\n");
		printf("Please control the format of your file.\n");
		printf("\'bbb.bbb.bbb..\' for each face without any space");
		printf(" or new line.\n");
		return (NULL);
	}
	
	/** Traitement du buffer **/
	cube = ft_new_cube();
	for (index = 0; index <= size; size ++)
	{}

	return (cube);	
} 
