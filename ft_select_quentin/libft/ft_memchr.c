/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:57:18 by qchevrin          #+#    #+#             */
/*   Updated: 2013/11/25 09:38:27 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	void		*ret;

	str = (const char *) s;
	while (*str != c)
	{
		if (n <= 0)
		{
			return (NULL);
		}
		str = str + 1;
		n = n - 1;
	}
	ret = (void*)str;
	return (ret);
}
