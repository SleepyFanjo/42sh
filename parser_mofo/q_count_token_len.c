/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_count_token_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 14:24:50 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/26 17:51:08 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	is_separator(char *str, int i)
{
	if (q_is_whitespace(str[i]) || q_is_special_char(str, i))
		return (1);
	if (str[i] == '\0')
		return (1);
}

int			q_is_special_char(char *str, int i)
{
	if (str[i] == '<' || str[i] == '>' || str[i] == '&' || str[i] == '|')
	{
		if (str[i + 1] == str[i])
			return (2);
		return (1);
	}
	return (0);
}

int			q_count_normal(char *str, int *beg, int *end)
{
	while (!is_separator(str, *end))
		*end = *end + 1;
	return (*end - *beg);
}

int			q_count_token_len(char *str, int *beg, int *end)
{
	char	c;
	int		k;

	if (str[beg] == '\"' || str[beg] == '\'')
	{
		c = str[*beg];
		*beg = *beg + 1;
		while (str[*end + 1] != '\0' &&
				(str[*end + 1] != c || str[*end] == '\\'))
			*end = *end + 1;
		k = *end - beg + 1;
		if (str[*end + 1] == c)
			*end = *end + 1;
		return (k);
	}
	if ((k = q_is_special_char(str, *beg)) > 0)
		return (k);
	else
		return (q_count_normal(str, beg, end));
}
