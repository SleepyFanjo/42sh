/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 11:34:48 by lredoban          #+#    #+#             */
/*   Updated: 2014/01/23 15:14:19 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_string(t_printf_env *e, char *s)
{
	if (!s)
	{
		ft_putstr("(null)");
		e->len += 6;
	}
	else
	{
		ft_putstr(s);
		e->len += ft_strlen(s);
	}
}

static void		ft_char(t_printf_env *e, int c)
{
	ft_putchar(c);
	e->len += 1;
}

static void		ft_pointer(t_printf_env *e, unsigned long p)
{
	ft_putstr("0x");
	e->len += 2;
	ft_unsigned(e, p, 16);
}

static void		ft_dispatch(t_printf_env *e, const char *format)
{
	e->pos += 1;
	if (format[e->pos] == 'd' || format[e->pos] == 'i')
		ft_num(e, (va_arg(e->ap, int)));
	if (format[e->pos] == 'u')
		ft_unsigned(e, (va_arg(e->ap, unsigned int)), 10);
	if (format[e->pos] == 'o')
		ft_unsigned(e, (va_arg(e->ap, unsigned int)), 8);
	if (format[e->pos] == 'x')
		ft_unsigned(e, (va_arg(e->ap, unsigned int)), 16);
	if (format[e->pos] == 'X')
		ft_maj_hexa(e, (va_arg(e->ap, unsigned int)));
	if (format[e->pos] == 's')
		ft_string(e, (va_arg(e->ap, char *)));
	if (format[e->pos] == 'c')
		ft_char(e, (va_arg(e->ap, int)));
	if (format[e->pos] == 'p')
		ft_pointer(e, (va_arg(e->ap, unsigned long)));
	if (format[e->pos] == '%')
	{
		ft_putchar('%');
		e->len += 1;
	}
}

int				ft_printf(const char *format, ...)
{
	t_printf_env		e;

	e.pos = 0;
	e.len = 0;
	va_start(e.ap, format);
	while (format[e.pos] != '\0')
	{
		if (format[e.pos] == '%' && format[e.pos] != '\0')
			ft_dispatch(&e, format);
		else
		{
			ft_putchar(format[e.pos]);
			e.len += 1;
		}
		e.pos += 1;
	}
	if (e.pos != 0)
		va_end(e.ap);
	return (e.len);
}
