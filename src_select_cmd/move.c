/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:34:00 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/26 11:48:45 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/select_cmd.h"

int						sideways(t_param *param, char *buf)
{
	if (BUF == LEFT || BUF == RIGHT)
	{
		if (BUF == RIGHT && I < LEN)
		{
			tputs(tgetstr("nd", NULL), 1, tputs_putchar);
			I++;
			return (1);
		}
		else if (BUF == LEFT && I != 0)
		{
			tputs(tgetstr("le", NULL), 1, tputs_putchar);
			I--;
			return (1);
		}
		tputs(tgetstr("bl", NULL), 1, tputs_putchar);
	}
	return (0);
}

int						extreme_sideways(t_param *param, char *buf)
{
	if (BUF == END || BUF == HOME)
	{
		if (BUF == HOME && I != 0)
		{
			while (I > 0)
			{
				tputs(tgetstr("le", NULL), 1, tputs_putchar);
				I--;
			}
			return (1);
		}
		else if (BUF == END && I != LEN)
		{
			while (I != LEN)
			{
				tputs(tgetstr("nd", NULL), 1, tputs_putchar);
				I++;
			}
			return (1);
		}
		tputs(tgetstr("bl", NULL), 1, tputs_putchar);
	}
	return (0);
}

int						word_jump_left(t_param *param, char *buf)
{
	if (BUF == ALT_LEFT && I != 0)
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
		return (1);
	}
	return (0);
}

int						word_jump_right(t_param *param, char *buf)
{
	if (BUF == ALT_RIGHT && I != LEN)
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
		return (1);
	}
	return (0);
}
