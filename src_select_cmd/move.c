/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:34:00 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/02/25 15:57:31 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select_cmd.h"

void					sideways(t_param *param, char *buf)
{
	if (BUF == RIGHT && I < LEN)
	{
		if ((I + P) % SIZE == 0)
			tputs(tgetstr("do", NULL), 1, tputs_putchar);
		else
			tputs(tgetstr("nd", NULL), 1, tputs_putchar);
		I++;
	}
	else if (BUF == LEFT && I != 0)
	{
		tputs(tgetstr("le", NULL), 1, tputs_putchar);
		I--;
	}
}

void					extreme_sideways(t_param *param, char *buf)
{
	if (BUF == HOME && I != 0)
	{
		while (I > 0)
		{
			tputs(tgetstr("le", NULL), 1, tputs_putchar);
			I--;
		}
	}
	else if (BUF == END && I != LEN)
	{
		while (I != LEN)
		{
			if ((I + P) % SIZE == 0)
				tputs(tgetstr("do", NULL), 1, tputs_putchar);
			else
				tputs(tgetstr("nd", NULL), 1, tputs_putchar);
			I++;
		}
	}
}

void					word_jump_left(t_param *param)
{
	if (I != 0)
	{
		if ((ft_isprint(STR[I]) == 1 && STR[I - 1] == ' ') || I == LEN)
		{
			tputs(tgetstr("le", NULL), 1, tputs_putchar);
			I--;
		}
		while (I > 0 && STR[I] == ' ')
		{
			tputs(tgetstr("le", NULL), 1, tputs_putchar);
			I--;
		}
		while (I >= 1 && STR[I - 1] != ' ' && ft_isprint(STR[I]) == 1)
		{
			tputs(tgetstr("le", NULL), 1, tputs_putchar);
			I--;
		}
	}
}

void					word_jump_right(t_param *param)
{
	if (I != LEN)
	{
		while (I != LEN && STR[I] != ' ')
		{
			if ((I + P) % SIZE == 0)
				tputs(tgetstr("do", NULL), 1, tputs_putchar);
			else
				tputs(tgetstr("nd", NULL), 1, tputs_putchar);
			I++;
		}
		while (I != LEN && STR[I] == ' ')
		{
			if ((I + P) % SIZE == 0)
				tputs(tgetstr("do", NULL), 1, tputs_putchar);
			else
				tputs(tgetstr("nd", NULL), 1, tputs_putchar);
			I++;
		}
	}
}

