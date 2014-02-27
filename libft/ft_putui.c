/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 20:19:11 by lredoban          #+#    #+#             */
/*   Updated: 2013/12/21 23:34:48 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putui(unsigned long n, int base)
{
	char	*s;

	s = ft_uitoa(n, base);
	ft_putstr(s);
	free(s);
}
