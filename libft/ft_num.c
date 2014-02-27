/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 22:03:24 by lredoban          #+#    #+#             */
/*   Updated: 2014/02/27 18:14:15 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_num(t_printf_env *e, int num)
{
	if (num < 0)
		e->len += 1;
	if (num == 0)
	{
		ft_putchar('0');
		e->len += 1;
	}
	else
	{
		ft_putnbr(num);
		while (num != 0)
		{
			e->len += 1;
			num /= 10;
		}
	}
}

void		ft_unsigned(t_printf_env *e, unsigned long num, int base)
{
	if (num == 0)
	{
		ft_putchar('0');
		e->len += 1;
	}
	else
	{
		ft_putui(num, base);
		while (num != 0)
		{
			e->len += 1;
			num /= base;
		}
	}
}

void		ft_maj_hexa(t_printf_env *e, unsigned int num)
{
	if (num == 0)
	{
		ft_putchar('0');
		e->len += 1;
	}
	else
	{
		ft_put_maj_hexa(num, 16);
		while (num != 0)
		{
			e->len += 1;
			num /= 16;
		}
	}
}
