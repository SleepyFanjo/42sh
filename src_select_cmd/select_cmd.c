/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 14:33:20 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/11 17:01:50 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select_cmd.h"
//#include "autocomplete.h"  // seulement dans le fichier contenant la fonction tab_key

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

	tmp_len = (LEN + P) / (SIZE - 1);
	if (BUF == ALT_DOWN &&
			((LEN + P) > ((SIZE - 1) * tmp_len) && I <= (tmp_len * (SIZE - 1))))
	{
		j = SIZE - 1;
		while (I < LEN && j > 0)
		{
			go_right(param);
			j--;
		}
		return (1);
	}
	return (0);
}

int						go_up(t_param *param, char *buf)
{
	int					j;

	j = SIZE - 1;
	if (BUF == ALT_UP && (P + I) > SIZE)
	{
		while (j > 0 && I > 0)
		{
			go_left(param);
			j--;
		}
		return (1);
	}
	return (0);
}

int						tab_key(t_param *param, char *buf)
{
	if (BUF != TAB)
		return (0);
	ft_autocomplete(param);
	(void)param;
	return (1);
}

void					extreme_end(t_param *param)
{
	while (I != LEN)
	{
		go_right(param);
	}
}

void					if_forest(t_param *param, char *buf)
{
	int					i;

	i = 0;
	while (key_tab[i] != NULL)
	{
		if ((key_tab[i])(param, buf))
			break ;
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
