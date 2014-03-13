/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_in_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 16:59:41 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/13 17:08:28 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history.h>

static t_history	*new_history_elem(char *str)
{
	t_history	*history;

	history = (t_history *)j_malloc(sizeof(t_history));
	history->next = NULL;
	history->prev = NULL;
	history->str = str;
	return (history);
}

void				add_in_history(t_history **history, char *str)
{
	t_history	*cursor;
	if (str == NULL)
		return ;
	if (*history == NULL)
	{
		*history = new_history_elem(str);
		return ;
	}
	cursor = (*history);
	*history = new_history_elem(str);
	(*history)->next = cursor;
}
