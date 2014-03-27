/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:25:37 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/27 11:30:02 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int		*ptr;

	if ((ptr = (int *)malloc(size)) == NULL)
	{
		return (NULL);
	}
	while (size > 0)
	{
		ptr[size - 1] = 0;
		size = size - 1;
	}
	return ((void*)ptr);
}
