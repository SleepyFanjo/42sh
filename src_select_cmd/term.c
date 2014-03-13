/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 15:23:26 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/13 14:11:02 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/select_cmd.h"

int						set_term(void)
{
	struct termios		term;

	if (tgetent(NULL, getenv("TERM")) < 1)
		return (-1);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ISIG);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &term);
	return (0);
}

int						unset_term(void)
{
	struct termios		term;

	tcgetattr(0, &term);
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	term.c_lflag |= ISIG;
	tcsetattr(0, TCSADRAIN, &term);
	return (0);
}

int						get_lenmax(void)
{
	int				len;
	struct winsize	size;

	ioctl(1, TIOCGWINSZ, &size);
	len = size.ws_col - 1;
	return (len);
}

void					init_param(t_param *param, int nb, char *str)
{
	I = 0;
	P = nb;
	LEN = 0;
	LEN_MAX = get_lenmax();
	STR = ft_strdup("");
	P_LINE = ft_strdup(str);
}

t_param					*save_param(t_param *param)
{
	static t_param		*p = NULL;

	if (param == NULL)
		return (p);
	else
	{
		if (p == NULL)
			p = (t_param *)malloc(sizeof(t_param));
		p->i = I;
		p->len = LEN;
		p->p_line = P_LINE;
		p->str = STR;
		p->prompt = P;
	}
	return (p);
}
