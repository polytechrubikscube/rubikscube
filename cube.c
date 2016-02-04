/** 
 **         ////////    |   /__/__/__/ 
 **        ///   ///    |  |__|__|__|/  Le Rubik's Cube
 **       ///   ///     |  |__|__|__|/    Projet d'Algorithmie - INFO 3A
 **      ////////       |  |__|__|__|/      2015 - 2016
 **     ///olytech      |                                CONNET Cyprien
 **    ///   Marseille  |                                GUZZI  Olivier
 ** ######################################################################
 **  Nom du fichier       : cube.c
 **  Date de création     : Le 20 Décembre 2015 à 10h00
 **  Date de modification : Le 4 Février 2016   à 15h06
 **/

#include "rubikscube.h"

t_cube	*ft_new_cube(void)
{
	t_cube *cube;
	int cur_face;
	int cur_line;
	int cur_col;

	cube = NULL;
	/** Memory allocation **/
	cube = (t_cube *)malloc(sizeof(t_cube));
	
	/** Cube init if malloc succeded **/
	if (cube)
	{
		cube->rotations = NULL;
		cube->profondeur_arbre = 0;

		/** e_colors [0..5] ==> init des couleurs à -1 **/
		for (cur_face = 0; cur_face < 6; cur_face++)
		for (cur_line = 0; cur_line < 3; cur_line++)
		for (cur_col = 0; cur_col < 3; cur_col++)
		{
			cube->faces[cur_face][cur_line][cur_col].color = -1;
			cube->faces[cur_face][cur_line][cur_col].id = -1;
		}
	}
	return (cube);
}
