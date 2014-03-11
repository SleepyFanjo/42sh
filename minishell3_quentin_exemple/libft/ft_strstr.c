/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:52:28 by qchevrin          #+#    #+#             */
/*   Updated: 2013/11/22 15:41:58 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	n;
	char	*f_occ;

	n = (size_t) ft_strlen(s2);
	f_occ = (char *) s1;
	if (ft_strncmp("", s2, 1) == 0)
	{
		return ((char *) s1);
	}
	while ((f_occ = ft_strchr(f_occ, s2[0])) != NULL)
	{
		if (ft_strncmp(f_occ, s2, n) == 0)
		{
			return (f_occ);
		}
		f_occ = f_occ + 1;
	}
	return (NULL);
}
