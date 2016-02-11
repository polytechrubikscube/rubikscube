/** 
 **         ////////    |   /__/__/__/ 
 **        ///   ///    |  |__|__|__|/  Le Rubik's Cube
 **       ///   ///     |  |__|__|__|/    Projet d'Algorithmie - INFO 3A
 **      ////////       |  |__|__|__|/      2015 - 2016
 **     ///olytech      |                                CONNET Cyprien
 **    ///   Marseille  |                                GUZZI  Olivier
 ** ######################################################################
 **  Nom du fichier       : ft_manip_predef_cube.c
 **  Date de création     : Le 11 Février 2016 à 15h37
 **  Date de modification :
 **/

#include "rubikscube.h"
#define CSNS(nb_colors, sens_rot_lecture_face) cube->starts[nb_colors][sens_rot_lecture_face]
/** CSNS(n, f) => Pointeur sur le premier mini_cube d'une face correspondant au type n **/

/** Entrée : f
 ** |f00 |f01 |f02 |		 |f00 |f01 |f02 |
 ** |f10 |f11 |f12x| r === >     |f10 |f11 |f12y|
 ** |f20 |f21y|f22 |		 |f20 |f21x|f22 |
 **       d       
 **
 **
 **/
int	ft_le_belge(t_cube_lists *cube, t_faces f, t_faces r, t_faces d)
{
	return(ft_cube_lists_rot(cube, d + 12) &&
	ft_cube_lists_rot(cube, r + 12) &&
	ft_cube_lists_rot(cube, d) &&
	ft_cube_lists_rot(cube, r) &&
	ft_cube_lists_rot(cube, d) &&
	ft_cube_lists_rot(cube, f) &&
	ft_cube_lists_rot(cube, d + 12) &&
	ft_cube_lists_rot(cube, f + 12));
	
}

int	ft_le_belge_rev(t_cube_lists *cube, t_faces f, t_faces d, t_faces l)
{
	return(ft_cube_lists_rot(cube, d) &&
	ft_cube_lists_rot(cube, l) &&
	ft_cube_lists_rot(cube, d + 12) &&
	ft_cube_lists_rot(cube, l + 12) &&
	ft_cube_lists_rot(cube, d + 12) &&
	ft_cube_lists_rot(cube, f + 12) &&
	ft_cube_lists_rot(cube, d) &&
	ft_cube_lists_rot(cube, f));
	
}

int	ft_white_cross(t_cube_lists *cube, t_cube *cube_matrice)
{
	begin = CSNS(2, face_f); // curent pointe sur le premier cube arrete de f (centre white)
	current = begin;

	do{
		if (current->mini_cube[0] == white)
			/** rechercher la couleur opposée à current->mini_cube[1]  (=color+1 %...)
				la placer en face cur->next[rot_f]->next[rot_f]**/
			while (current2 != begin && current2->mini_cube[0] != color_op && current2->mini_cube[1] != color_op)
				curent2 = curent2->next_general;
			
		else if (current->mini_cube[1] == white)
				
		current = current->next[rot_f];
	}
	while (current != begin)
}


