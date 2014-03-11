/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 13:04:47 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/09 14:31:53 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static int	not_assigned(int res)
{
	if (res != 32 && res != 4348699 && res != 4283163)
		return (1);
	return (0);
}

void		modify_list(t_list **list, char *buff)
{
	int		res;

	res = *(unsigned int *)buff;
	if (not_assigned(res))
		return ;
	(*list)->mode = (*list)->mode - 1;
	if (res == 4348699)
		(*list) = (*list)->next;
	if (res == 4283163)
		(*list) = (*list)->prev;
	if (res == 32)
	{
		if ((*list)->mode < 2)
			(*list)->mode = (*list)->mode + 2;
		else
			(*list)->mode = (*list)->mode - 2;
		(*list) = (*list)->next;
	}
	(*list)->mode = (*list)->mode + 1;
}

t_list		*get_begin_list(t_list *list)
{
	while (list->is_begin != 1)
		list = list->next;
	return (list);
}
