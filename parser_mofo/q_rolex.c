/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_rolex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 17:45:10 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/12 18:38:43 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int			q_is_slash(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '/')
			return (1);
		i = i + 1;
	}
	return (0);
}

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
		if (token->type == Q_CMD && q_is_slash(token->name))
			token->type = Q_EXE;
		list = list->next;
	}
	return (begin);
}
