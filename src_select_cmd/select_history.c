/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 15:19:19 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/13 17:30:44 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/select_cmd.h"

void					change_str(t_param *param, char *s)
{
	int					tmp;

	free(STR);
	STR = ft_strdup(s);
	LEN = ft_strlen(s);
	exleft(I + P);
	write_str(P_LINE, s);
	if (I > LEN)
		I = LEN;
	else
	{
		tmp = LEN;
		while (tmp > I)
		{
			tputs(tgetstr("le", NULL), 1, tputs_putchar);
			tmp--;
		}
	}
}

int						s_history(t_param *param, char *buf)
{
	static int			first = 0;

	if ((BUF == UP || BUF == DOWN) && HISTORY != NULL)
	{
		if (BUF == UP && H_NEXT != NULL)
		{
			if (first == 0)
				param->save_str = ft_strdup(STR);
			change_str(param, H_STR);
			HISTORY = H_NEXT;
			first = 1;
		}
		else if (BUF == DOWN && first != 0)
		{
			if (H_PREV == NULL)
				change_str(param, param->save_str);
			else
			{
				HISTORY = H_PREV;
				change_str(param, H_STR);
			}
		}
		return (1);
	}
	return (0);
}
