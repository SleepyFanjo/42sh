/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tput_putchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 19:00:19 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/28 19:29:22 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		tput_putchar(int c)
{
	write(1, &c, 1);
	return (0);
}