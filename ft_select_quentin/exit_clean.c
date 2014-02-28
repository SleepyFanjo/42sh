/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 15:57:15 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/10 19:27:11 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <termcap.h>
#include <stdlib.h>

void	exit_clean(t_param param, int mode)
{
	tputs(tgetstr("ve", NULL), 1, tput_putchar);
	tputs(tgetstr("cl", NULL), 1, tput_putchar);
	tcsetattr(0, 0, &(param.old_term));
	if (mode == 1)
		exit(0);
}
