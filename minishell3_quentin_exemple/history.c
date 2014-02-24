/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 16:12:43 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/29 17:17:54 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <libft.h>

static t_list	*create_elem(char *str)
{
	t_list		*elem;

	if ((elem = (t_list *)malloc(sizeof(t_list))) == NULL)
		ft_error("Error: Can't malloc", NULL, 1);
	elem->str = ft_strdup(str);
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

static void	clean_list(t_list **list)
{
	t_list		*cursor;
	t_list		*prev;
	int			i;

	cursor = *list;
	prev = NULL;
	i = 0;
	while (cursor != NULL && cursor->next != NULL)
	{
		prev = cursor;
		cursor = cursor->next;
		i = i + 1;
	}
	if (i > HISTORY_LEN && prev != NULL)
	{
		free(cursor->str);
		free(cursor);
		prev->next = NULL;
	}
}

void		add_in_history(char *str, t_list **list)
{
	t_list		*elem;

	elem = create_elem(str);
	if (*list == NULL)
	{
		*list = elem;
		return ;
	}
	elem->next = *list;
	*list = elem;
	clean_list(list);
}
