/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:24:18 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/15 19:08:48 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	len_word(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (*str != c && *str != '\0')
	{
		i = i + 1;
		str = str + 1;
	}
	return (i);
}

static int		nbr_word(const char *str, char c)
{
	int		i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == c)
			str = str + 1;
		else
		{
			i = i + 1;
			while (*str != c && *str != '\0')
				str = str + 1;
		}
	}
	return (i);
}

static void		copy_word(char *dst, const char *src, int *i, char c)
{
	while (src[*i] != c && src[*i] != '\0')
	{
		*dst = src[*i];
		*i = *i + 1;
		dst = dst + 1;
	}
	*dst = '\0';
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if ((tab = (char **) malloc((nbr_word(s, c) + 1) * sizeof(char *))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i = i + 1;
		else
		{
			if ((tab[j] = ft_strnew(len_word(s + i, c) + 1)) == NULL)
					return (NULL);
			copy_word(tab[j], s, &i, c);
			j = j + 1;
		}
		tab[j] = 0;
	}
	tab[j] = NULL;
	return (tab);
}

