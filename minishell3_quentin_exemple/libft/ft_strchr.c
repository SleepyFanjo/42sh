/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:21:52 by qchevrin          #+#    #+#             */
/*   Updated: 2013/11/29 12:20:31 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return ((char *)(s + i));
		}
		i = i + 1;
	}
	if (s[i] == c)
	{
		return ((char *)(s + i));
	}
	return (NULL);
}
