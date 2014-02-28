/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_token.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 16:12:57 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/28 14:19:44 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int			q_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

void		q_white_token(char *str, int *i)
{
	int			j;

	j = *i;
	while (q_is_whitespace(str[j]))
		j = j + 1;
	*i = j;
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
	{
		q_white_token(str, i);
		return (q_create_token(str, i, error));
	}
	k = q_count_token_len(str, i, &j, &inh);
	if (k == -1)
		return (NULL);
	name = q_strndup(str + *i, k, inh);
	*i = j;
	return (q_utility_token(name));
}
