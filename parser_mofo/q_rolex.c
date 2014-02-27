/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_rolex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 17:45:10 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/27 18:16:45 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void		q_modify_token(t_token *token, int *ctrl, int *file)
{
	if (token->type == Q_LINK)
		*file = 1;
	else if (token->type == Q_CTRL)
		*ctrl = 1;
	else if (token->type == Q_STR)
	{
		if (*file)
		{
			*file = 0;
			token->type = Q_FILE;
		}
		else if (*ctrl)
		{
			*ctrl = 0;
			token->type = Q_CMD;
		}
		else
			token->type = Q_ARG;
	}
}

t_list		*q_rolex(t_list *list)
{
	int			is_ctrl;
	int			is_file;
	t_list		*begin;
	t_token		*token;

	is_ctrl = 1;
	is_file = 0;
	begin = list;
	while (list != NULL)
	{
		token = list->elem;
		q_modify_token(token, &is_ctrl, &is_file);
		list = list->next;
	}
	return (begin);
}
