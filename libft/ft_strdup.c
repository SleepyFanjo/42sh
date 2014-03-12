/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:05:21 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/12 18:11:17 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*res;

	if ((res = (char *)j_malloc((ft_strlen(s1) + 1) * sizeof(char))) == NULL)
	{
		return (NULL);
	}
	res = ft_strcpy(res, s1);
	return (res);
}
