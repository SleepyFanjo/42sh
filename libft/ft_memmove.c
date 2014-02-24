/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:24:29 by qchevrin          #+#    #+#             */
/*   Updated: 2013/11/20 11:15:46 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*dest;
	const char	*src;

	dest = s1;
	src = s2;
	if (src <= dest)
	{
		dest = dest + n - 1;
		src = src + n - 1;
		while (n > 0)
		{
			*dest = *src;
			dest = dest - 1;
			src = src - 1;
			n = n - 1;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (s1);
}
