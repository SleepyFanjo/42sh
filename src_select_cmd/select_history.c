/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 15:19:19 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/17 15:28:16 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/select_cmd.h"

void					change_str(t_param *param, char *s)
{
	free(STR);
	STR = ft_strdup(s);
	LEN = ft_strlen(s);
	exleft(I + P);
	write_str(P_LINE, s);
	I = LEN;
}

void					change_up(t_param *param)
{
	if (param->hist_f == 0)
	{
		param->save_str = ft_strdup(STR);
		change_str(param, H_STR);
		param->hist_f = 1;
	}
	else
	{
		if (H_NEXT != NULL)
			HISTORY = H_NEXT;
		if (H_NEXT == NULL)
			tputs(tgetstr("bl", NULL), 1, tputs_putchar);
		change_str(param, H_STR);
	}
}

void					change_down(t_param *param)
{
	if (H_PREV == NULL)
	{
		change_str(param, param->save_str);
		free(param->save_str);
		param->hist_f = 0;
	}
	else
	{
		HISTORY = H_PREV;
		change_str(param, H_STR);
	}
}

int						s_history(t_param *param, char *buf)
{
	if (BUF == UP || BUF == DOWN)
	{
		if (BUF == UP && HISTORY != NULL)
		{
			change_up(param);
			return (1);
		}
		else if (BUF == DOWN && param->hist_f != 0)
		{
			change_down(param);
			return (1);
		}
		tputs(tgetstr("bl", NULL), 1, tputs_putchar);
	}
	return (0);
}
