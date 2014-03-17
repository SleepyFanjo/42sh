/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_utility_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:45:30 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/17 11:59:56 by lredoban         ###   ########.fr       */
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

static char	*realloc_tilde(char *home, char *str, int i)
{
	char	*ret;
	int		len;

	len = ft_strlen(home) + ft_strlen(str);
	if ((ret = (char *)malloc(sizeof(char) * len)) == NULL)
		q_error("Error : can't malloc", NULL, 1);
	len = 0;
	while (len <= i)
	{
		ret[len] = str[len];
		len = len + 1;
	}
	ret[i] = '\0';
	ft_strcat(ret, home);
	return (ft_strcat(ret, str + len));
}

static char	*tilde(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] != '~')
	{
		if (str[i] == '\0')
			return (str);
		i = i + 1;
	}
	j = 0;
	while (g_env != NULL && g_env[j] != NULL)
	{
		if (!ft_strncmp(g_env[j], "HOME", 4))
			return (realloc_tilde(g_env[j] + 5, str, i));
		j = j + 1;
	}
	return (str);
}

static char	*eval_token_name(char *token_name)
{
	int		i;
	int		j;
	int		len;
	char	*ret;

	if (token_name == NULL)
		return (token_name);
	j = 0;
	while (token_name[j] != '$' && token_name[j] != '\0')
		j = j + 1;
	if (token_name[j] == '\0')
		return (tilde(token_name));
	len = ft_strlen(token_name + j + 1);
	i = 0;
	while (g_env != NULL && g_env[i] != NULL)
	{
		if (!ft_strncmp(token_name + j + 1, g_env[i], len))
		{
			ret = ft_strdup(g_env[i] + len - 1);
			free(token_name);
			return (ret);
		}
		i = i + 1;
	}
	return (tilde(token_name));
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
