/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:35:51 by qchevrin          #+#    #+#             */
/*   Updated: 2013/11/25 11:32:00 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*dest;
	const char	*src;
	int			i;

	i = 0;
	dest = (char *) s1;
	src = (const char *) s2;
	while (n > 0)
	{
		dest[i] = src[i];
		if (c == src[i])
		{
			return (s1 + i + 1);
		}
		i = i + 1;
		n = n - 1;
	}
	return (NULL);
}
