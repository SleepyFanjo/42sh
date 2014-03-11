/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 20:13:42 by lredoban          #+#    #+#             */
/*   Updated: 2013/12/21 23:20:38 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_uitoa_len(unsigned long n, int base)
{
	int		len;

	len = 0;
	while (n != 0)
	{
		n /= base;
		len += 1;
	}
	return (len);
}

char		*ft_uitoa(unsigned long n, int base)
{
	int		len;
	char	*str;

	if (n == 0)
		return ("0");
	len = ft_uitoa_len(n, base);
	str = ft_strnew(len + 1);
	str[len] = '\0';
	while (len != 0)
	{
		len -= 1;
		if (n % base > 9)
			str[len] = 'a' - 10 + n % base;
		else
			str[len] = '0' + n % base;
		n /= base;
	}
	return (str);
}
