/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_token.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 16:12:57 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/14 11:39:28 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int			q_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

t_token		*q_white_token(char *str, int *i)
{
	t_token		*white;
	int			k;
	int			j;

	j = *i;
	if ((white = (t_token *)malloc(sizeof(t_token))) == NULL)
		q_error("Error : can't malloc", NULL, 1);
	white->type = Q_SPACE;
	while (q_is_whitespace(str[j]))
		j = j + 1;
	if ((white->name = (char *)malloc(sizeof(char) * (j - *i + 3))) == NULL)
		q_error("Error : can't malloc", NULL, 1);
	j = *i;
	k = 0;
	while (q_is_whitespace(str[j]))
	{
		(white->name)[k] = str[j];
		k = k + 1;
		j = j + 1;
	}
	(white->name)[k] = '\0';
	*i = j - 1;
	return (white);
}

char		*q_strndup(char *str, int n, int inh)
{
	char		*dup;
	int			i;

	if (n <= 0)
		return (NULL);
	if ((dup = (char *)malloc(sizeof(char) * (n + 2))) == NULL)
		q_error("Error : can't malloc", NULL, 1);
	i = 0;
	while (i < n)
	{
		if (!inh && str[i] == '\\' && str[i + 1] != '\0')
			str = str + 1;
		dup[i] = str[i];
		i = i + 1;
	}
	dup[i] = '\0';
	return (dup);
}

t_token		*q_create_token(char *str, int *i, int *error)
{
	char		*name;
	t_token		*tmp;
	int			inh;
	int			k;
	int			j;

	j = *i;
	if (str[*i] == '\0')
	{
		*error = 1;
		return (NULL);
	}
	if (q_is_whitespace(str[j]))
		return (q_white_token(str, i));
	if (str[*i] == '(')
		return (q_subshell(str, i));
	k = q_count_token_len(str, i, &j, &inh);
	if (k == -1)
		return (NULL);
	name = q_strndup(str + *i, k, inh);
	*i = j;
	tmp = q_utility_token(name, inh);
	free(name);
	return (tmp);
}
