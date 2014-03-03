/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:34:00 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/02/28 18:23:56 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select_cmd.h"

void					go_right(t_param *param)
{
	if ((I + P + 1) % (SIZE - 1) == 0)
		tputs(tgetstr("do", NULL), 1, tputs_putchar);
	else
		tputs(tgetstr("nd", NULL), 1, tputs_putchar);
	I++;
}

void					go_left(t_param *param)
{
	int					t;

	t = 0;
	if ((I + P) % (SIZE - 1) == 0)
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
	I--;
}

int						sideways(t_param *param, char *buf)
{
	if (BUF == LEFT || BUF == RIGHT)
	{
		if (BUF == RIGHT && I < LEN)
			go_right(param);
		else if (BUF == LEFT && I != 0)
			go_left(param);
		return (1);
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
				go_left(param);
		}
		else if (BUF == END && I != LEN)
		{
			while (I != LEN)
				go_right(param);
		}
		return (1);
	}
	return (0);
}

int						word_jump_left(t_param *param, char *buf)
{
	if (BUF == ALT_LEFT && I != 0)
	{
		if ((ft_isprint(STR[I]) == 1 && STR[I - 1] == ' ') || I == LEN)
		{
				go_left(param);
		//	tputs(tgetstr("le", NULL), 1, tputs_putchar);
		//	I--;
		}
		while (I > 0 && STR[I] == ' ')
		{
				go_left(param);
		//	tputs(tgetstr("le", NULL), 1, tputs_putchar);
		//	I--;
		}
		while (I >= 1 && STR[I - 1] != ' ' && ft_isprint(STR[I]) == 1)
		{
				go_left(param);
		//	tputs(tgetstr("le", NULL), 1, tputs_putchar);
		//	I--;
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
				go_right(param);
	//		if ((I + P) % SIZE == 0)
	//			tputs(tgetstr("do", NULL), 1, tputs_putchar);
	//		else
	//			tputs(tgetstr("nd", NULL), 1, tputs_putchar);
	//		I++;
		}
		while (I != LEN && STR[I] == ' ')
		{
				go_right(param);
	//		if ((I + P) % SIZE == 0)
	//			tputs(tgetstr("do", NULL), 1, tputs_putchar);
	//		else
	//			tputs(tgetstr("nd", NULL), 1, tputs_putchar);
	//		I++;
		}
		return (1);
	}
	return (0);
}

