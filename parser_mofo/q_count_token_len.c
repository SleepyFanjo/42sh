/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_count_token_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 14:24:50 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/27 15:38:31 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	is_separator(char *str, int i)
{
	if (q_is_whitespace(str[i]) || q_is_special_char(str, i, NULL))
		return (1);
	if (str[i] == '\0')
		return (1);
	return (0);
}

int			q_is_special_char(char *str, int i, int *end)
{
	if (str[i] == '<' || str[i] == '>' || str[i] == '&' || str[i] == '|')
	{
		if (str[i + 1] == str[i])
		{
			if (end != NULL)
				*end = *end + 1;
			return (2);
		}
		return (1);
	}
	return (0);
}

int			q_count_normal(char *str, int *beg, int *end)
{
	int		i;

	i = 0;
	while (!is_separator(str, *end))
	{
		if (str[*end] == '\\')
		{
			i = i + 1;
			if (str[*end + 1] != '\0')
				*end = *end + 1;
		}
		*end = *end + 1;
	}
	*end = *end - 1;
	return (*end - *beg + 1 - i);
}

int			q_count_token_len(char *str, int *beg, int *end, int *inh)
{
	char	c;
	int		k;

	*inh = 0;
	if (str[*beg] == '\"' || str[*beg] == '\'')
	{
		*inh = 1;
		c = str[*beg];
		*beg = *beg + 1;
		while (str[*end + 1] != c || str[*end] == '\\')
		{
			if (str[*end] == '\0')
				return (-1);
			*end = *end + 1;
		}
		k = *end - *beg + 1;
		if (str[*end + 1] == c)
			*end = *end + 1;
		return (k);
	}
	if ((k = q_is_special_char(str, *beg, end)) > 0)
		return (k);
	else
		return (q_count_normal(str, beg, end));
}
