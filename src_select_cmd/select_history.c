/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 15:19:19 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/13 15:57:44 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/select_cmd.h"

void					change_str(t_param *param)
{
	int					tmp;

	free(STR);
	STR = ft_strdup(H_STR);
	LEN = ft_strlen(H_STR);
	exleft(I + P);
	write_str(P_LINE, H_STR);
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
	if (BUF == UP || BUF == DOWN)
	{
		if (BUF == UP && H_NEXT != NULL)
		{
			change_str(param);
		}
		else if (BUF == DOWN && H_PREV != NULL)
		{
			change_str(param);
		}
		return (1);
	}
	return (0);
}
