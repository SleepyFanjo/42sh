/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:34:00 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/02/24 15:14:10 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select_cmd.h"

void					sideways(t_param *param, char *buf)
{
	if (BUF == RIGHT && I < LEN)
	{
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
		while (I != 0)
		{
			tputs(tgetstr("le", NULL), 1, tputs_putchar);
			I--;
		}
	}
	else if (BUF == END && I != LEN)
	{
		while (I != LEN)
		{
			tputs(tgetstr("nd", NULL), 1, tputs_putchar);
			I++;
		}
	}
}

void					word_jump_left(t_param *param)
{
	if (I != 0)
	{
		if (I > 0 && STR[I - 1] == ' ' && ft_isprint(STR[I]) == 1)
		{
			tputs(tgetstr("le", NULL), 1, tputs_putchar);
			I--;
		}
		while (I > 0 && STR[I] == ' ')
		{
			tputs(tgetstr("le", NULL), 1, tputs_putchar);
			I--;
		}
		while (I != 0 && STR[I] != ' ')
		{
			tputs(tgetstr("le", NULL), 1, tputs_putchar);
			I--;
		}
		if (STR[I] == ' ')
		{
			tputs(tgetstr("nd", NULL), 1, tputs_putchar);
			I++;
		}
	}
}

void					word_jump_right(t_param *param)
{
	if (I != LEN)
	{
		while (I != LEN && STR[I] != ' ')
		{
			tputs(tgetstr("nd", NULL), 1, tputs_putchar);
			I++;
		}
		while (I != LEN && STR[I] == ' ')
		{
			tputs(tgetstr("nd", NULL), 1, tputs_putchar);
			I++;
		}
	}
}

