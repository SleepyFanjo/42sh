/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 14:33:20 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/02/24 19:25:26 by jrenouf-         ###   ########.fr       */
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
	LEN_MAX = 100000;
	STR = ft_strdup("");
}

void					go_down(t_param *param)
{
	int					tmp_len;
	int					j;

	tmp_len = (LEN + P) / SIZE;
	if ((LEN + P) > (SIZE * tmp_len) && I <= tmp_len * SIZE)
	{
		j = I + P - SIZE;
		tputs(tgetstr("do", NULL), 1, tputs_putchar);
		while (j > 0)
		{
			tputs(tgetstr("nd", NULL), 1, tputs_putchar);
			j--;
		}
	}
}

void					if_forest(t_param *param, char *buf)
{
	int					fd;
	int					fd1;

	fd = open("toto", O_WRONLY | O_CREAT | O_APPEND, 0644);
	fd1 = open("tata", O_WRONLY | O_CREAT | O_APPEND, 0644);
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
	else if (BUF == DOWN)
		go_down(param);
	ft_putstr_fd("I : ", fd);
	ft_putendl_fd(ft_itoa(I), fd);
	ft_putstr_fd("LEN : ", fd);
	ft_putendl_fd(ft_itoa(LEN), fd);
	ft_putstr_fd("SIZE : ", fd1);
	ft_putendl_fd(ft_itoa(SIZE), fd1);
	ft_putstr_fd("P : ", fd1);
	ft_putendl_fd(ft_itoa(P), fd1);
	ft_putstr_fd("LEN_MAX : ", fd1);
	ft_putendl_fd(ft_itoa(LEN_MAX), fd1);
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
