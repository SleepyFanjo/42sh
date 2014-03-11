/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_free_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:33:33 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/05 12:06:17 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void		q_free_list(t_list **list)
{
	t_list		*cursor;
	t_list		*next;
	t_token		*elem;

	if (*list == NULL)
		return ;
	cursor = *list;
	next = cursor->next;
	while (next != NULL)
	{
		elem = (t_token *)cursor->elem;
		free(elem->name);
		free(cursor->elem);
		free(cursor);
		cursor = next;
		next = cursor->next;
	}
	elem = (t_token *)cursor->elem;
	free(elem->name);
	free(cursor->elem);
	free(cursor);
	*list = NULL;
}
