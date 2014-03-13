/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:51:48 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/13 20:31:37 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	if ((ptr = (char *)j_malloc((size + 1) * sizeof(char))) == NULL)
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
