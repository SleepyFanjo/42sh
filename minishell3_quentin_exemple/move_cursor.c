/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 16:02:53 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/01 14:54:06 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <libft.h>

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
		return (1);
	return (0);
}

static void	move_left(t_pos *pos, char *input, int len)
{
	int		i;

	i = len - pos->cursor;
	while (i > 0 && is_whitespace(input[i - 1]))
	{
		pos->cursor = pos->cursor + 1;
		i = i - 1;
	}
	while (i > 0 && !is_whitespace(input[i - 1]))
	{
		pos->cursor = pos->cursor + 1;
		i = i - 1;
	}
}

static void	move_right(t_pos *pos, char *input, int len)
{
	int		i;

	i = len - pos->cursor;
	while (pos->cursor > 0 && !is_whitespace(input[i]))
	{
		pos->cursor = pos->cursor - 1;
		i = i + 1;
	}
	while (pos->cursor > 0 && is_whitespace(input[i]))
	{
		pos->cursor = pos->cursor - 1;
		i = i + 1;
	}
}

void		move_cursor_unit(t_key c, t_pos *pos, char *input)
{
	if (c == LEFT_K && pos->cursor < ft_strlen(input))
		pos->cursor = pos->cursor + 1;
	if (c == RIGHT_K && pos->cursor > 0)
		pos->cursor = pos->cursor - 1;
	if (c == END_K)
		pos->cursor = 0;
	if (c == HOME_K)
		pos->cursor = ft_strlen(input);
}

void		move_cursor_word(t_key c, t_pos *pos, char *input)
{
	int		len;

	len = ft_strlen(input);
	if (c == ALT_L_K)
		move_left(pos, input, len);
	else
		move_right(pos, input, len);
}
