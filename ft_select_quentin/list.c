/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 17:37:31 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/09 14:55:31 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <stdlib.h>
#include <libft.h>

t_list		*init_list(int argc, char **argv)
{
	t_list		*begin;

	(void) argc;
	if ((begin = (t_list *)malloc(sizeof(t_list))) == NULL)
		ft_error("Error : can't malloc");
	begin->str = argv[1];
	begin->mode = 1;
	begin->is_begin = 1;
	begin->next = begin;
	begin->prev = begin;
	return (begin);
}

t_list		*new_elem_list(char *str, int mode)
{
	t_list		*elem;

	if ((elem = (t_list *)malloc(sizeof(t_list))) == NULL)
		ft_error("Error : Can't malloc");
	elem->str = str;
	elem->mode = mode;
	elem->is_begin = 0;
	elem->next = elem;
	elem->prev = elem;
	return (elem);
}

void		delete_elem_list(t_list **elem)
{
	t_list		*cursor;
	t_list		*prev;
	t_list		*next;

	cursor = *elem;
	prev = cursor->prev;
	next = cursor->next;
	if (cursor->is_begin == 1)
	{
		next->is_begin = 1;
	}
	if (prev == cursor)
	{
		free(cursor);
		*elem = NULL;
		return ;
	}
	free(cursor);
	cursor = NULL;
	prev->next = next;
	next->prev = prev;
	*elem = next;
}


void		clean_list(t_list **list)
{
	t_list		*cursor;

	cursor = *list;
	while (cursor != NULL && cursor->next->is_begin != 1)
	{
		if (cursor->mode < 2)
			delete_elem_list(&cursor);
		else
			cursor = cursor->next;
	}
	while (cursor != NULL && cursor->mode < 2)
		delete_elem_list(&cursor);
	while (cursor != NULL && cursor->is_begin != 1)
		cursor = cursor->next;
	*list = cursor;
}

void		fill_list(int argc, char **argv, t_list **list)
{
	int			i;
	t_list		*elem;
	t_list		*cursor;

	i = 2;
	cursor = *list;
	while (i < argc)
	{
		elem = new_elem_list(argv[i], 0);
		elem->next = cursor;
		cursor->prev = elem;
		while (cursor->next->is_begin != 1)
			cursor = cursor->next;
		cursor->next = elem;
		elem->prev = cursor;
		cursor = *list;
		i = i + 1;
	}
}
