/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 22:10:51 by lredoban          #+#    #+#             */
/*   Updated: 2014/02/10 15:59:09 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_hexatoa_len(unsigned int n, int base)
{
	int			len;

	len = 0;
	while (n != 0)
	{
		n /= base;
		len += 1;
	}
	return (len);
}

static char		*ft_hexatoa(unsigned int n, int base)
{
	int			len;
	char		*str;

	if (n == 0)
		return ("0");
	len = ft_hexatoa_len(n, base);
	str = ft_strnew(len + 1);
	str[len] = '\0';
	while (len != 0)
	{
		len -= 1;
		if (n % base > 9)
			str[len] = 'A' - 10 + n % base;
		else
			str[len] = '0' + n % base;
		n /= base;
	}
	return (str);
}

void			ft_put_maj_hexa(unsigned int n, int base)
{
	char		*s;

	s = ft_hexatoa(n, base);
	ft_putstr(s);
	free(s);
}
