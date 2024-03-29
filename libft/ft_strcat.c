/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:00:23 by qchevrin          #+#    #+#             */
/*   Updated: 2013/11/21 10:17:16 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		i = i + 1;
	}
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i = i + 1;
		j = j + 1;
	}
	s1[i] = s2[j];
	return (s1);
}
