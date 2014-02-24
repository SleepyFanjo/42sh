/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:06:24 by qchevrin          #+#    #+#             */
/*   Updated: 2013/11/25 16:38:20 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	const char	*src;
	char		*dest;

	src = (const char *) s2;
	dest = (char *) s1;
	while (n > 0)
	{
		*dest = *src;
		dest = dest + 1;
		src = src + 1;
		n = n - 1;
	}
	return (s1);
}
