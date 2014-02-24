/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 14:33:20 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/02/08 15:39:16 by jrenouf-         ###   ########.fr       */
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
	len = size.ws_col;
	return (len);
}

void					init_param(t_param *param, int nb)
{
	I = 0;
	P = nb;
	LEN = 0;
	STR = ft_strdup("");
}

void					if_forest(t_param *param, char *buf)
{
	if (ft_isprint(BUF) == 1)
		char_insert(param, buf);
	else if (BUF == DELETE || BUF == B_SPACE)
		char_del(param, buf);
	else if (BUF == LEFT || BUF == RIGHT)
		sideways(param, buf);
	else if (BUF == END || BUF == HOME)
		extreme_sideways(param, buf);
	else if (BUF == ALT_LEFT)
		word_jump_left(param);
	else if (BUF == ALT_RIGHT)
		word_jump_right(param);
	else if (BUF == RETURN)
		write(1, "\n", 1);
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
		p.len_max = get_lenmax();
		ft_bzero(buf, 5);
		read(0, buf, 4);
		if_forest(&p, buf);
	}
	unset_term();
	return (p.str);
}
