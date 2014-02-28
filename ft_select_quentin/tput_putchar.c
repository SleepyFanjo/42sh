/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tput_putchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 12:46:19 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/09 15:09:38 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "select.h"
#include <unistd.h>

int		tput_putchar(int c)
{
	static int	fd = 0;

	if (fd == 0)
		fd = open("/dev/tty", O_WRONLY | O_APPEND);
	if (fd == -1)
		ft_error("Error: can't open /dev/tty");
	write(fd, &c, 1);
	return (0);
}
