/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:33:57 by qchevrin          #+#    #+#             */
/*   Updated: 2013/11/21 13:43:35 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*str;
	unsigned int		i;

	if ((str = ft_strnew(ft_strlen(s) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		str[i] = f(i, *s);
		s = s + 1;
		i = i + 1;
	}
	return (str);
}
