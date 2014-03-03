/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:59:46 by qchevrin          #+#    #+#             */
/*   Updated: 2013/12/10 13:49:48 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_signed(int nbr)
{
	if (nbr < 0)
		return (1);
	return (0);
}

static int		ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static size_t	power(int nbr)
{
	size_t	i;

	nbr = abs(nbr);
	i = 1;
	while (nbr > 10)
	{
		i = i + 1;
		nbr = nbr / 10;
	}
	return (i);
}

static char		*reverse_str(char *str)
{
	int		i;
	int		j;
	char	buff;

	i = 0;
	j = (int) ft_strlen(str) - 1;
	while (i < j)
	{
		buff = str[i];
		str[i] = str[j];
		str[j] = buff;
		i = i + 1;
		j = j - 1;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		i;

	sign = is_signed(n);
	i = 0;
	if ((str = ft_strnew(power(n) + 1 + sign)) == NULL)
		return (NULL);
	while (n > 9 || n < -9)
	{
		str[i] = ft_abs(n % 10) + '0';
		i = i + 1;
		n = n / 10;
	}
	str[i] = ft_abs(n) + '0';
	if (sign == 1)
	{
		str[i + 1] = '-';
		i = i + 1;
	}
	str[i + 1] = '\0';
	return (reverse_str(str));
}
