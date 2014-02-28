/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_correct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 12:49:25 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/11 15:34:37 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <termcap.h>
#include <libft.h>
#include <fcntl.h>

void	print_correct(t_list *elem)
{
	static int	fd = 0;

	if (fd == 0)
		fd = open("/dev/tty", O_WRONLY | O_APPEND);
	if (fd == -1)
		ft_error("Error: Can't open /dev/tty");
	if (elem->mode == 2 || elem->mode == 3)
		tputs(tgetstr("mr", NULL), 1, tput_putchar);
	if (elem->mode == 1 || elem->mode == 3)
		tputs(tgetstr("us", NULL), 1, tput_putchar);
	ft_putstr_fd(elem->str, fd);
	tputs(tgetstr("me", NULL), 1, tput_putchar);
}
