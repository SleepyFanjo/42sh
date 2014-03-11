/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:10:20 by qchevrin          #+#    #+#             */
/*   Updated: 2013/12/02 14:20:51 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	size_t		index;

	i = 0;
	if (s2[0] == '\0')
		return ((char *) s1);
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		index = i;
		while (s1[i] == s2[j] && i < n)
		{
			if (s2[j] == '\0' || s2[j + 1] == '\0')
				return ((char *) (s1 + index));
			j = j + 1;
			i = i + 1;
		}
		i = index;
		i = i + 1;
	}
	return (NULL);
}
