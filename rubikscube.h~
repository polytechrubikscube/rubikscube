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
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


/** Les types **/

/** t_list: elt.data, elt.next **/

typedef struct s_liste
{
	char data;
	struct s_liste *next;
}				t_list;

/** t_case: elt.color, elt.id **/
typedef struct s_case
{
	char color;
	char id;
}			t_case;

/** t_face: elt[line][column] **/
typedef t_case t_face[3][3];


/** t_cube: elt.faces[f][line][column], elt.rotations->data,
		elt.rotations->next, elt.profondeur_arbre **/
typedef struct s_cube
{
	t_face faces[6];
	t_list *rotations;
	int node_level;
}				t_cube;

/** t_faces: int, **/
typedef enum e_faces {
        face_f, face_b, face_u, face_d, face_l, face_r
}               		t_faces;

/** t_couleur: int, **/
typedef enum e_couleur {
        red, green, blue, white, orange, yellow,
	rouge = 0, vert = 1, bleu = 2, blanc = 3, jaune = 5,
	r = 0, g = 1, b = 2, w = 3, o = 4, y = 5 
}               		t_couleur;

/***************************/
/** Functions prototypes **/
/***************************/

/** Rotations **/
void ft_rot_f(t_cube *cube);
void ft_rot_frev(t_cube *cube);
void ft_rot_f2(t_cube *cube);
void ft_rot_b(t_cube *cube);
void ft_rot_brev(t_cube *cube);
void ft_rot_b2(t_cube *cube);
void ft_rot_u(t_cube *cube);
void ft_rot_urev(t_cube *cube);
void ft_rot_u2(t_cube *cube);
void ft_rot_d(t_cube *cube);
void ft_rot_drev(t_cube *cube);
void ft_rot_d2(t_cube *cube);
void ft_rot_l(t_cube *cube);
void ft_rot_lrev(t_cube *cube);
void ft_rot_l2(t_cube *cube);
void ft_rot_r(t_cube *cube);
void ft_rot_rrev(t_cube *cube);
void ft_rot_r2(t_cube *cube);

/** cube.c **/

t_cube	*ft_new_cube(void);

/** ft_io.c: I/O functions **/
void	ft_print_cube(t_cube *cube);

/** ft_file.c - File IO functions  **/
t_cube	*ft_read_file(char *path);

/** ft_error.c - Error treatment **/
void	*ft_error(int e);

#endif
