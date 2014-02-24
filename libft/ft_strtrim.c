/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 19:28:52 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/01 13:58:42 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*del_space(char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t')
		str++;
	return (str);
}

char		*ft_strtrim(char const *s)
{
	char			*str;
	char			*str_start;
	int				size;
	int				i;
	int				j;

	j = 0;
	i = 0;
	str_start = del_space((char *)s);
	size = ft_strlen(str_start);
	str = ft_strnew(ft_strlen(s));
	if (size == 0)
		return (str);
	size--;
	while (size - j >= 0
			&& (str_start[size - j] == ' ' || str_start[size - j] == '\t'
				|| str_start[size - j] == '\n'))
		j++;
	while (i < size - j + 1)
	{
		str[i] = str_start[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
