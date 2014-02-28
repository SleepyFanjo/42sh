/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_term.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 12:42:59 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/09 13:00:01 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <termcap.h>
#include <stdlib.h>

void	clear_term(void)
{
	tputs(tgetstr("cl", NULL), 1, tput_putchar);
}
