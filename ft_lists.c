/**
 **         ////////    |   /__/__/__/
 **        ///   ///    |  |__|__|__|/  Le Rubik's Cube
 **       ///   ///     |  |__|__|__|/    Projet d'Algorithmie - INFO 3A
 **      ////////       |  |__|__|__|/      2015 - 2016
 **     ///olytech      |                                CONNET Cyprien
 **    ///   Marseille  |                                GUZZI  Olivier
 ** ######################################################################
 **  Nom du fichier       : ft_lists.c
 **  Date de création     : Le 20 Décembre 2015 à 10h00
 **  Date de modification : Le 24 Décembre 2015 à 13h00
 **/

#include "rubikscube.h"

/** Lists ADT functions **/

/** Return an empty list **/
t_list	*ft_list_create_empty(void)
{
	return ((t_list *)NULL);
}

/** Return 1 or 0 if list is empty or not. **/
int	ft_list_is_empty(t_list *list)
{
	return (list == ft_list_create_empty());
}

/** Add elt at the head of the list **/
t_list	*ft_list_add_head(t_list *list, char elt)
{
	t_list *container;

	container = (t_list *)malloc(sizeof(t_list));
	if (!container)
		return (ft_error(10));
	container->data = elt;
	container->next = list;
	return (container);
}

/** Delete the first element at the head of the list and free memory.
    Return the next element or the empty list. **/
t_list	*ft_list_del_head(t_list *list)
{
	t_list *to_del;

	if (!list)
		return (ft_list_create_empty());
	to_del = list;
	list = list->next;
	free(to_del);
	return (list);
}

/** Fusion of head and queue **/
t_list	*ft_list_fusion(t_list *head, t_list *queue)
{
	t_list *cur;
	if (!head)
		return (queue);
	else if (!queue)
		return (head);
	while (cur->next)
		cur = cur->next;
	cur->next = queue;
	return (head);
}

void	ft_list_del_list(t_list *list)
{
	if (list)
	{
		ft_list_del_list(list->next);
		free (list);
	}
}

t_list	*ft_list_del_queue(t_list *list)
{
	t_list *to_del;

	if (!list || !list->next)
		return (list);
	to_del = list->next;
	list->next = ft_list_create_empty();
	ft_list_del_list_del(to_del);
	return (list);
}

t_list	*ft_list_queue(t_list *list)
{
	if (list)
		return (list->next);
	return(ft_list_create_empty());
}

char	ft_list_head(t_list *list)
{
	return (list->data);
}

t_list	*ft_list_add_end(t_list *list, char elt)
{
	t_list *container;
	t_list *cur;

	container = (t_list *)malloc(sizeof(t_list));
	if (!container)
		return (ft_error(10));
	container->data = elt;
	container->next = ft_list_create_empty();
	if (!list)
		return (container);
	cur = list;
	while (cur->next)
		cur = cur->next;
	cur->next = container;
	return (list);
}

t_list	*ft_list_del_end(t_list *list)
{
	t_list *cur;

	if (!list)
		return (list);
	cur = list;
	while (cur->next)
		cur = cur->next
	free(cur);
	return (list);
}
