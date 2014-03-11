/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_free_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 10:56:46 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/05 12:06:27 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void		q_free_elem(t_cmd *elem)
{
	int		i;

	i = 0;
	if (elem == NULL)
		return ;
	if (elem->cmd != NULL)
		free(elem->cmd);
	if (elem->file_in != NULL)
		free(elem->file_in);
	if (elem->file_out != NULL)
		free(elem->file_out);
	if (elem->arg != NULL)
	{
		while ((elem->arg)[i] != NULL)
		{
			free((elem->arg)[i]);
			i = i + 1;
		}
		free(elem->arg);
	}
	free(elem);
}

void		q_free_cmd(t_list **cmd)
{
	t_list		*cursor;
	t_list		*next;
	t_cmd		*elem;

	if (*cmd == NULL)
		return ;
	cursor = *cmd;
	next = cursor->next;
	while (next != NULL)
	{
		elem = (t_cmd *)cursor->elem;
		q_free_elem(elem);
		free(cursor);
		cursor = next;
		next = cursor->next;
	}
	elem = (t_cmd *)cursor->elem;
	q_free_elem(elem);
	free(cursor);
	*cmd = NULL;
}
