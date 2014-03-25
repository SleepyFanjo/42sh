/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:23:20 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/25 16:25:14 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/select_cmd.h"

void					l_exleft(int tmp)
{
	while (tmp > 0)
	{
		tputs(tgetstr("le", NULL), 1, tputs_putchar);
		tmp--;
	}
}

void					exleft(int tmp)
{
	while (tmp > 0)
	{
		tputs(tgetstr("le", NULL), 1, tputs_putchar);
		tmp--;
	}
	tputs(tgetstr("cd", NULL), 1, tputs_putchar);
}

void					sc_clear(int sig)
{
	t_param				*param;
	int					tmp;

	param = save_param(NULL);
	LEN_MAX = get_lenmax();
	tmp = I + P;
	if (LEN + P >= LEN_MAX)
	{
		exleft(I + P);
		ft_putstr("> window too small..");
	}
	else
	{
		exleft(I + P);
		write_str(P_LINE, STR);
		tmp = LEN;
		while (tmp > I)
		{
			tputs(tgetstr("le", NULL), 1, tputs_putchar);
			tmp--;
		}
	}
	signal(sig, &sc_clear);
}

void					write_str(char *p_line, char *str)
{
	int					i;

	i = 0;
	ft_putstr(p_line);
	if (str[0] == '\0')
		return ;
	while (str[i] != '\0')
	{
		write(1, str + i, 1);
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
	write_str(P_LINE, STR);
	if (mode == 1)
	{
		write(1, " ", 1);
		tputs(tgetstr("rc", NULL), 1, tputs_putchar);
	}
}
