/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:03:15 by qchevrin          #+#    #+#             */
/*   Updated: 2013/11/25 15:56:49 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	ret;
	int		i;

	if ((len = ft_strlen(dst)) >= size)
	{
		return (ft_strlen(src) + size);
	}
	ret = len;
	size = size - len - 1;
	i = 0;
	while (size > 0 && src[i] != '\0')
	{
		dst[len] = src[i];
		len = len + 1;
		i = i + 1;
		size = size - 1;
	}
	dst[len] = '\0';
	return (ret + ft_strlen(src));
}
