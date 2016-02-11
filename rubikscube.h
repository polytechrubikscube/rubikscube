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
# define CFC(face, line, col) cube->faces[face][line][col].color

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

/** t_rot: int, (rot + 6) = rot 2, (rot +12) = rotrev **/
typedef enum e_rot {
        rot_f, rot_b, rot_u, rot_d, rot_l, rot_r, rot_f2, rot_b2, rot_u2, rot_d2, rot_l2, rot_r2, rot_frev, rot_brev, rot_urev, rot_drev, rot_lrev, rot_rrev
}               		t_rot;

/** t_couleur: int, **/
typedef enum e_couleur {
        white, red, green, orange, blue,yellow,
	blanc = 0,rouge = 1, vert = 2, bleu = 4, jaune = 5,
	w = 0, r = 1, g = 2, o = 3, b = 4, y = 5 
}               		t_couleur;

/** t_list_mini_cube: char data->mini_cube[i], data->previous[5], data->next[5] **/
typedef struct s_list_mini_cube
{
	char		 	*mini_cube;
	struct s_list_mini_cube 	*next[25];
}		t_list_mini_cube;

/** t_cube_lists: t_list_mini_cube *cube.elements[1,2,3], t_list *cube.rotations, int cube.node_level **/
typedef struct s_cube_lists
{
	t_list_mini_cube *elements[4];  /** elements [0] -> NULL / [1] -> 1 color by element  / [2] -> ... / [3] -> .. **/
	t_list_mini_cube *starts[4][25];
	t_list	    *rotations;
	int	     node_level;
}		t_cube_lists;


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
