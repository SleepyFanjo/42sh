/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_utility_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:45:30 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/27 16:18:55 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>


char		q_get_utility(char *str)
{
	if (!ft_strcmp(str, "<") || !ft_strcmp(str, ">"))
		return (Q_LINK);
	if (!ft_strcmp(str, "<<") || !ft_strcmp(str, ">>"))
		return (Q_LINK);
	if (!ft_strcmp(str, "|") || !ft_strcmp(str, "&"))
		return (Q_CTRL);
	if (!ft_strcmp(str, "||") || !ft_strcmp(str, "&&"))
		return (Q_CTRL);
	return (Q_STR);
}

t_token		*q_utility_token(char *name)
{
	t_token		*token;

	if ((token = (t_token *)malloc(sizeof(t_token))) == NULL)
		q_error("Error : can't malloc", NULL, 1);
	token->name = name;
	token->type = q_get_utility(name);
	return (token);
}
