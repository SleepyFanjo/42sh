/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 14:33:20 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/12 19:44:16 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select_cmd.h"

int						tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}


void					extreme_end(t_param *param)
{
	while (I != LEN)
	{
		tputs(tgetstr("nd", NULL), 1, tputs_putchar);
		I++;
	}
}

char					*ft_end_sig(t_param *param, char *buf)
{
	if (BUF == C_D)
	{
		free(STR);
		return (ft_strdup("exit"));
	}
	if (BUF == C_C)
	{
		free(STR);
		return (ft_strdup(""));
	}
	return (NULL);
}

void					if_forest(t_param *param, char *buf)
{
	int					i;

	i = 0;
	LEN_MAX = get_lenmax();
	if (LEN >= LEN_MAX)
		return ;
	while (key_tab[i] != NULL)
	{
		if ((key_tab[i])(param, buf))
			break ;
		i += 1;
	}
	if (BUF == RETURN)
		extreme_end(param);
	save_param(param);
}

char					*select_cmd(int nb, char *str)
{
	t_param				p;
	char				buf[5];

	if (set_term() < 0)
		return (NULL);
	signal(SIGWINCH, &sc_clear);
	init_param(&p, nb, str);
	ft_bzero(buf, 5);
	ft_putstr(str);
	while (BUF != RETURN)
	{
		ft_bzero(buf, 5);
		if (read(0, buf, 4) < 0)
			return (NULL);
		if (BUF == C_C || BUF == C_D)
			return (ft_end_sig(&p, buf));
		if_forest(&p, buf);
	}
	unset_term();
	write(1, "\n", 1);
	return (p.str);
}
