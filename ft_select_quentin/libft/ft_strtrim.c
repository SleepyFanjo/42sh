/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:33:10 by qchevrin          #+#    #+#             */
/*   Updated: 2013/11/25 17:17:54 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static int		only_whitespace(const char *str)
{
	while (*str != '\0')
	{
		if (!is_whitespace(*str))
			return (0);
		str = str + 1;
	}
	return (1);
}

static size_t	number_whitespaces(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		i = i + is_whitespace(*s);
		s = s + 1;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;

	if ((str = ft_strnew(ft_strlen(s) + 1 - number_whitespaces(s))) == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0' && is_whitespace(*s))
		s = s + 1;
	while (!only_whitespace(s) && *s != '\0')
	{
		str[i] = *s;
		i = i + 1;
		s = s + 1;
	}
	str[i] = '\0';
	return (str);
}
