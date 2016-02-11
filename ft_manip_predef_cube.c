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
