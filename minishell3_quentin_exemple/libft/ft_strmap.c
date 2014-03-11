/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:20:13 by qchevrin          #+#    #+#             */
/*   Updated: 2013/11/21 13:39:02 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if ((str = ft_strnew(ft_strlen(s) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		str[i] = f(*s);
		i = i + 1;
		s = s + 1;
	}
	return (str);
}
