/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:28:15 by qchevrin          #+#    #+#             */
/*   Updated: 2013/12/02 14:20:42 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_neg(const char *str)
{
	if (str[0] == '-')
	{
		return (-1);
	}
	return (1);
}

int				ft_atoi(const char *str)
{
	int		res;
	int		neg;

	res = 0;
	neg = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
			|| *str == '\v' || *str == '\f')
		str = str + 1;
	if (*str == '+' || *str == '-')
	{
		neg = is_neg(str);
		str = str + 1;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		res = res * 10 + ((*str - '0') * neg);
		str = str + 1;
	}
	return (res);
}
