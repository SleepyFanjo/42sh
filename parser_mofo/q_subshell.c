/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_subshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 10:51:24 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/14 15:49:13 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void		q_test_inhib(char *str, int *j, int *inh, char *inh_c)
{
	if (*inh && *inh_c == '\\')
	{
		*inh = 0;
		*inh_c = 0;
		*j = *j + 1;
	}
	else if (!*inh && (str[*j] == '\"' || str[*j] == '\'' || str[*j] == '\\'))
	{
		*inh = 1;
		*inh_c = str[*j];
	}
	else if (*inh && str[*j] == *inh_c)
	{
		*inh = 0;
		*inh_c = 0;
	}
}

static t_token	*q_shell_token(char *str, int *i, int j)
{
	t_token		*token;
	int			k;
	char		*ret;

	token = (t_token *)j_malloc(sizeof(t_token *));
	token->type = Q_SHELL;
	ret = (char *)j_malloc(sizeof(char) * (j - *i + 2));
	k = 0;
	while (*i < j)
	{
		ret[k] = str[*i];
		k = k + 1;
		*i = *i + 1;
	}
	ret[k] = '\0';
	*i = *i + 1;
	token->name = ret;
	return (token);
}

t_token			*q_subshell(char *str, int *i)
{
	int			j;
	char		inh_c;
	int			inh;

	*i = *i + 1;
	j = *i;
	inh = 0;
	inh_c = 0;
	while (str[j] != '\0')
	{
		q_test_inhib(str, &j, &inh, &inh_c);
		if (!inh && str[j] == ')')
			return (q_shell_token(str, i, j));
		j = j + 1;
	}
	return (NULL);
}
