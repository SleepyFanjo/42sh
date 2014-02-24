/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_raw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 15:17:38 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/29 17:35:28 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <termios.h>
#include <termcap.h>

void	make_raw(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &term);
	if (tgetent(NULL, getenv("TERM")) < 1)
		ft_error("Boouh nul", NULL, 1);
}

void	reset_term(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag |= (ICANON | ECHO);
	tcsetattr(0, TCSADRAIN, &term);
}
