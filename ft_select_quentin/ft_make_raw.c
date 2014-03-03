/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_raw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 19:14:47 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/09 14:49:38 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <termcap.h>
#include <unistd.h>

struct termios	ft_make_raw(void)
{
	struct termios	term;
	struct termios	old;

	tcgetattr(0, &term);
	tcgetattr(0, &old);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &term);
	tputs(tgetstr("vi", NULL), 1, tput_putchar);
	return (old);
}
