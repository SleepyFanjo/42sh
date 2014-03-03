/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 14:33:20 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/03 14:29:45 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select_cmd.h"

int						tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int						get_lenmax(void)
{
	int				len;
	struct winsize	size;

	ioctl(1, TIOCGWINSZ, &size);
	len = size.ws_col - 1;
	return (len);
}

void					init_param(t_param *param, int nb)
{
	I = 0;
	P = nb;
	LEN = 0;
	LEN_MAX = 100000;
	STR = ft_strdup("");
}

int						go_down(t_param *param, char *buf)
{
	int					tmp_len;
	int					j;

	tmp_len = (LEN + P) / SIZE;
	if (BUF == ALT_DOWN &&
			((LEN + P) > (SIZE * tmp_len) && I <= tmp_len * SIZE))
	{
		j = (I + P) % SIZE;
		I = I + (SIZE - j) + 1;
		tputs(tgetstr("do", NULL), 1, tputs_putchar);
		while (I < LEN && j > 0)
		{
			tputs(tgetstr("nd", NULL), 1, tputs_putchar);
			j--;
			I++;
		}
		return (1);
	}
	return (0);
}

int						go_up(t_param *param, char *buf)
{
	int					j;

	j = 0;
	if (BUF == ALT_UP && I > SIZE)
	{
		while (j <= SIZE)
		{
			tputs(tgetstr("le", NULL), 1, tputs_putchar);
			I--;
			j++;
		}
		return (1);
	}
	return (0);
}

void					extreme_end(t_param *param)
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

void					if_forest(t_param *param, char *buf)
{
	int					i;

	i = 0;
	while (key_tab[i] != NULL)
	{
		if ((key_tab[i])(param, buf))
			return ;
		i += 1;
	}
	if (BUF == RETURN)
		extreme_end(param);
}

char					*select_cmd(int nb)
{
	t_param				p;
	char				buf[5];

	if (set_term() < 0)
		return (NULL);
	init_param(&p, nb);
	ft_bzero(buf, 5);
	while (BUF != RETURN)
	{
		p.size = get_lenmax();
		ft_bzero(buf, 5);
		read(0, buf, 4);
		if_forest(&p, buf);
	}
	unset_term();
	return (p.str);
}
