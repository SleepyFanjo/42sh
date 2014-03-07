/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_inhib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:12:46 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/04 11:39:27 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	q_clean_inhib(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 || str[i - 1] != '\\')
		{
			if ((str[i] == '\"' || str[i] == '\'') && str[i + 1] == str[i])
			{
				str[i] = ' ';
				str[i + 1] = ' ';
			}
		}
		i = i + 1;
	}
}

int		q_count_inhib(char *str, int *beg, int *end, int *inh)
{
	char	c;
	int		k;

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
