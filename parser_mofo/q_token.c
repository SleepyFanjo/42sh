/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_token.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 16:12:57 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/27 16:16:37 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int			q_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

t_token		*q_white_token(char *str, int *i)
{
	t_token		*token;
	int			j;

	if ((token = (t_token *)malloc(sizeof(t_token))) == NULL)
		q_error("Error : can't malloc", NULL, 1);
	j = *i;
	while (q_is_whitespace(str[j]))
		j = j + 1;
	token->name = q_strndup(str + *i, j - *i, 0);
	token->type = Q_SPACE;
	*i = j - 1;
	return (token);
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

t_token		*q_create_token(char *str, int *i)
{
	char		*name;
	int			inh;
	int			k;
	int			j;

	j = *i;
	if (q_is_whitespace(str[j]))
		return (q_white_token(str, i));
	k = q_count_token_len(str, i, &j, &inh);
	if (k == -1)
		return (NULL);
	name = q_strndup(str + *i, k, inh);
	*i = j;
	return (q_utility_token(name));
}
