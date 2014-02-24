/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 17:21:52 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/01 14:52:32 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <libft.h>
#include <termcap.h>
#include <sys/ioctl.h>

static int	term_width(void)
{
	struct winsize	term;

	ioctl(0, TIOCGWINSZ, &term);
	return ((int) term.ws_col);
}

static int	is_ctrl(t_key c)
{
	if (c == UP_K || c == DOWN_K || c == LEFT_K || c == RIGHT_K)
	   return (1);
	if (c == DEL_L_K || c == DEL_R_K || c == ALT_L_K || c == ALT_R_K)
		return (1);
	if (c == END_K || c == HOME_K || c == CTRL_D_K)
		return (1);
	return (0);
}

static int	is_printable(t_key c)
{
	if (c > 31 && c < 127)
		return (1);
	return (0);
}

static void	add_in_input(char *buff, char **input, t_pos *pos)
{
	char	*str;
	int		i;

	if ((str = (char *)malloc((ft_strlen(*input) + 2) * sizeof(char))) == NULL)
		ft_error("Error can't malloc", NULL, 1);
	i = ft_strlen(*input) - pos->cursor;
	ft_strncpy(str, *input, i);
	str[i] = buff[0];
	i = i + 1;
	while ((*input)[i - 1] != '\0')
	{
		str[i] = (*input)[i - 1];
		i = i + 1;
	}
	str[i] = '\0';
	free(*input);
	*input = str;
}


void		apply_entry(char *buff, char **input, t_list *history, t_pos *pos)
{
	t_key	c;

	c = *(t_key *)buff;
	if (is_ctrl(c))
		apply_ctrl(c, input, history, pos);
	else if (is_printable(c) && ft_strlen(*input) < term_width() - 4)
		add_in_input(buff, input, pos);
}
