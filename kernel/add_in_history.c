/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_in_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 16:59:41 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/14 14:42:37 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history.h>
#include <libft.h>

static t_history	*new_history_elem(char *str)
{
	t_history	*history;

	history = (t_history *)j_malloc(sizeof(t_history));
	history->next = NULL;
	history->prev = NULL;
	history->str = ft_strdup(str);
	return (history);
}

static int			history_len(t_history *history)
{
	int			i;

	i = 0;
	while (history)
	{
		history = history->next;
		i = i + 1;
	}
	return (i);
}

void				add_in_history(t_history **history, char *str)
{
	t_history	*cursor;

	if (str == NULL || MAX_H_LEN <= 0)
		return ;
	if (*history == NULL)
	{
		*history = new_history_elem(str);
		return ;
	}
	cursor = (*history);
	*history = new_history_elem(str);
	(*history)->next = cursor;
	cursor->prev = (*history);
	if (history_len(*history) > MAX_H_LEN + 1)
	{
		if ((cursor = *history) == NULL)
			return ;
		while (cursor->next != NULL)
			cursor = cursor->next;
		free(cursor->str);
		free(cursor);
	}
}
