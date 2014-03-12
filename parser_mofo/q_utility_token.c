/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_utility_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:45:30 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/12 17:23:12 by qchevrin         ###   ########.fr       */
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
	if (!ft_strcmp(str, ";"))
		return (Q_CTRL);
	return (Q_STR);
}

static char	*eval_token_name(char *token_name)
{
	int		i;
	char	*ret;

	if (token_name == NULL || token_name[0] != '$')
		return (token_name);
	i = 0;
	while (g_env != NULL && g_env[i] != NULL)
	{
		if (!ft_strncmp(token_name + 1, g_env[i], ft_strlen(token_name + 1)))
		{
			ret = ft_strdup(g_env[i] + ft_strlen(token_name));
			free(token_name);
			return (ret);
		}
		i = i + 1;
	}
	return (token_name);
}


t_token		*q_utility_token(char *name, int inh)
{
	t_token		*token;

	if ((token = (t_token *)malloc(sizeof(t_token))) == NULL)
		q_error("Error : can't malloc", NULL, 1);
	token->name = ft_strdup(name);
	token->is_inhib = inh;
	if (inh)
		token->type = Q_STR;
	else
		token->type = q_get_utility(name);
	if (token->type == Q_STR && !inh)
		token->name = eval_token_name(token->name);
	return (token);
}
