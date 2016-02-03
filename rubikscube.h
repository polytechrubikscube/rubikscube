/** 
 **         ////////    |   /__/__/__/ 
 **        ///   ///    |  |__|__|__|/  Le Rubik's Cube
 **       ///   ///     |  |__|__|__|/    Projet d'Algorithmie - INFO 3A
 **      ////////       |  |__|__|__|/      2015 - 2016
 **     ///olytech      |                                CONNET Cyprien
 **    ///   Marseille  |                                GUZZI  Olivier
 ** ######################################################################
 **  Nom du fichier       : rubikscube.h
 **  Date de création     : Le 20 Décembre 2015 à 10h00
 **  Date de modification : Le 24 Décembre 2015 à 13h00
 **/

#ifndef RUBIKSCUBE_H
# define RUBIKSCUBE_H
# define BUFF_SIZE 100

# include <stdio.h>
# include <assert.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

/** Les types **/

/** t_liste: elt.data, elt.next **/

typedef struct s_liste
{

	char data;
	struct s_liste *next;

}		t_liste;


/** t_face: elt[line][column] **/
typedef char t_face[3][3];


/** t_cube: elt.faces[f][line][column], elt.rotations->data,
		elt.rotations->next, elt.profondeur_arbre **/
typedef struct s_cube
{
	t_face faces[6];
	t_liste *rotations;
	char profondeur_arbre;
}		t_cube;


#endif
