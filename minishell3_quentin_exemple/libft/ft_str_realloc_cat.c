/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_realloc_cat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:56:50 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/28 14:00:24 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_realloc_cat(char **s1, char *s2)
{
	char	*buff;
	int		size;

	buff = *s1;
	size = ft_strlen(*s1) + ft_strlen(s2);
	if ((*s1 = (char *) malloc((size + 1) * sizeof(char))) == NULL)
	{
		return (NULL);
	}
	ft_strcpy(*s1, buff);
	ft_strcat(*s1, s2);
	free(buff);
	return (*s1);
}
