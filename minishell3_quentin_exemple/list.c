/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 17:26:04 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/28 16:29:27 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

static t_lst	*create_lst(t_cmd *elem)
{
	t_lst		*lst;

	if ((lst = (t_lst *)malloc(sizeof(t_lst))) == NULL)
		ft_error("Error: Can't malloc", NULL, 1);
	lst->cmd = elem;
	lst->next = NULL;
	return (lst);
}

void			add_in_list(t_lst **lst, t_cmd *elem)
{
	t_lst	*obj;
	t_lst	*cursor;

	obj = create_lst(elem);
	cursor = *lst;
	if (cursor == NULL)
	{
		*lst = obj;
		return ;
	}
	while (cursor->next != NULL)
		cursor = cursor->next;
	cursor->next = obj;
}

void			free_list(t_lst **list)
{
	t_lst		*cursor;
	t_lst		*prev;

	cursor = *list;
	while (cursor != NULL)
	{
		free_cmd(cursor->cmd);
		prev = cursor;
		cursor = cursor->next;
		free(prev);
	}
}

void			free_cmd(t_cmd *elem)
{
	if (elem == NULL)
		return ;
	if (elem->cmd != NULL)
		free(elem->cmd);
	if (elem->arg != NULL)
		free_table(&(elem->arg));
	if (elem->end != NULL)
		free(elem->end);
	else if (elem->fd_in != NULL)
		free(elem->fd_in);
	if (elem->fd_out != NULL)
		free(elem->fd_out);
	free(elem);
}
