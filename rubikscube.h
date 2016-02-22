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
        white, yellow, blue, green, orange, red,
		blanc = 0, jaune = 1, bleu = 2, vert = 3, rouge = 5,
	w = 0, y = 1, b = 2, g = 3, o = 4, r = 5
}               		t_couleur;

/** t_list_mini_cube: char data->mini_cube[i], data->previous[5], data->next[5] **/
typedef struct 	s_list_mini_cube
{
	char		 									*mini_cube;
	struct s_list_mini_cube 	*next[7];
	struct s_list_mini_cube 	*previous[7];
}								t_list_mini_cube;

/** t_cube_lists: t_list_mini_cube *cube.elements[1,2,3], t_list *cube.rotations, int cube.node_level **/
typedef struct s_cube_lists
{
	t_list_mini_cube *elements[4];  /** elements [0] -> NULL / [1] -> 1 color by element  / [2] -> ... / [3] -> .. **/
	t_list_mini_cube *starts[4][6];
	t_list	  			 *rotations;
	int	     node_level;
}		t_cube_lists;


/***************************/
/** Functions prototypes **/
/***************************/

/** cube.c **/

/** ft_io.c: I/O functions **/
void	ft_print_cube(t_cube_lists *cube);

/** ft_file.c - File IO functions  **/
t_cube_lists	*ft_read_file(char *path);

/** ft_error.c - Error treatment **/
void	*ft_error(int e);

t_cube_lists	*ft_init_cube_lists(void);
int 	ft_link_cube_lists(t_cube_lists *cube);


/** Add elt at the head of the list **/
t_list_mini_cube	*ft_list_mini_cube_add_head(t_list_mini_cube *list, char *mini_cube);
t_list_mini_cube	*ft_init_list_mini_cube(int i);
/** Return an empty list **/
t_list	*ft_list_create_empty(void);
/** Return 1 or 0 if list is empty or not. **/
int	ft_list_is_empty(t_list *list);
/** Add elt at the head of the list **/
t_list	*ft_list_add_head(t_list *list, char elt);
/** Delete the first element at the head of the list and free memory.
    Return the next element or the empty list. **/
t_list	*ft_list_del_head(t_list *list);
void	ft_list_del_list(t_list *list);
t_list	*ft_list_del_queue(t_list *list);
t_list	*ft_list_queue(t_list *list);
char	ft_list_head(t_list *list);
t_list	*ft_list_add_end(t_list *list, char elt);
t_list	*ft_list_del_end(t_list *list);
int	ft_cube_lists_rot(t_cube_lists *cube, int rot);
int	ft_is_equal_to_one_of_3(char i, char a, char b, char c);

int	ft_is_equal_to_one_of_6(char i, char a, char b, char c, char d, char e, char f);

t_list	*ft_determine_movs(t_cube_lists *cube);

int	ft_backtrack(t_cube_lists *cube);

int	ft_cube_is_solved(t_cube_lists *cube);

int	ft_forbidden_set(t_cube_lists *cube);

int ft_cube_lists_rot_del_last(t_cube_lists *cube);
#endif
