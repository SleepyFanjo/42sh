/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:23:20 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/02/28 18:23:53 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select_cmd.h"

void					write_str(t_param *param, char *str)
{
	int					i;

	i = 0;
	ft_putstr("(.)(.) > ");
	while (str[i] != '\0')
	{
		write(1, str + i, 1);
		i++;
		if ((i + P) % (SIZE - 1) == 0)
			tputs(tgetstr("do", NULL), 1, tputs_putchar);
	}
}

static void				go_home(int i, t_param *param)
{
	int					t;

	t = 0;
	if (i % (SIZE - 1) == 0)
	{
		tputs(tgetstr("up", NULL), 1, tputs_putchar);
		while (t < (SIZE - 2))
		{
			tputs(tgetstr("nd", NULL), 1, tputs_putchar);
			t++;
		}
	}
	else
		tputs(tgetstr("le", NULL), 1, tputs_putchar);
}

void					refresh_screen(t_param *param, int mode)
{
	int					tmp;
	int					tmp2;

	tmp = I + P;
	tmp2 = LEN + 3;
	while (tmp > 0)
	{
		go_home(tmp, param);
		tmp--;
	}
	write_str(param, STR);
	if (mode == 1)
	{
		write(1, "   ", 3);
		while (tmp2 > 0)
		{
			go_home(tmp2 + P, param);
			tmp2--;
		}
		while (tmp < I)
		{
			if ((tmp + P + 1) % (SIZE - 1) == 0)
				tputs(tgetstr("do", NULL), 1, tputs_putchar);
			else
				tputs(tgetstr("nd", NULL), 1, tputs_putchar);
			tmp++;
		}
	}
}
