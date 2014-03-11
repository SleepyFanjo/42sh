/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 12:13:15 by lredoban          #+#    #+#             */
/*   Updated: 2014/02/27 18:08:21 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct	s_printf_env
{
	va_list		ap;
	char		*format;
	int			pos;
	int			len;
}				t_printf_env;

/*
**   ft_printf.c
*/
int			ft_printf(const char *format, ...);

/*
**   ft_putui.c
*/
void		ft_putui(unsigned long n, int base);

/*
**   ft_uitoa.c
*/
char		*ft_uitoa(unsigned long n, int base);

/*
**   ft_num.c
*/
void		ft_num(t_printf_env *e, int num);
void		ft_unsigned(t_printf_env *e, unsigned long num, int base);
void		ft_maj_hexa(t_printf_env *e, unsigned int num);

/*
**   ft_hexa.c
*/
void		ft_put_maj_hexa(unsigned int n, int base);
#endif
