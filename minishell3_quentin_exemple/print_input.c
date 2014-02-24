/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 18:57:33 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/04 14:01:30 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <termcap.h>
#include <libft.h>

void	print_input(char *input)
{
	tputs(tgetstr("rc", NULL), 1, tput_putchar);
	tputs(tgetstr("sc", NULL), 1, tput_putchar);
	ft_putstr(input);
}

void	move_cursor(int nbr)
{
	tputs(tgetstr("rc", NULL), 1, tput_putchar);
	tputs(tgetstr("sc", NULL), 1, tput_putchar);
	while (nbr > 0)
	{
		tputs(tgetstr("nd", NULL), 1, tput_putchar);
		nbr = nbr - 1;
	}
}
