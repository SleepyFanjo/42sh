/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:51:48 by qchevrin          #+#    #+#             */
/*   Updated: 2013/11/28 14:15:35 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	if ((ptr = malloc(size * sizeof(char))) == NULL)
	{
		return (NULL);
	}
	while (size > 0)
	{
		ptr[size - 1] = '\0';
		size = size - 1;
	}
	return (ptr);
}
