/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:23:20 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/12 17:11:32 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select_cmd.h"

void					sc_clear(int sig)
{
	t_param				*param;

	param = save_param(NULL);
	LEN_MAX = get_lenmax();
	if (I + P >=  LEN_MAX)
	{
		tputs(tgetstr("cl", NULL), 1, tputs_putchar);
		ft_putstr("> too small..");
	}
	else
	{
		tputs(tgetstr("cl", NULL), 1, tputs_putchar);
		write_str(param);
	}
	signal(sig, &sc_clear);
}

void					write_str(t_param *param)
{
	int					i;

	i = 0;
	ft_putstr(P_LINE);
	while (STR[i] != '\0')
	{
		write(1, STR + i, 1);
		i++;
	}
}

void					refresh_screen(t_param *param, int mode)
{
	int					tmp;

	tmp = I + P;
	if (mode == 1)
		tputs(tgetstr("sc", NULL), 1, tputs_putchar);
	while (tmp > 0)
	{
		tputs(tgetstr("le", NULL), 1, tputs_putchar);
		tmp--;
	}
	write_str(param);
	if (mode == 1)
	{
		write(1, " ", 1);
		tputs(tgetstr("rc", NULL), 1, tputs_putchar);
	}
}
