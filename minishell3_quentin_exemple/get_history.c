/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 14:06:05 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/29 17:57:53 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <libft.h>
#include <termcap.h>

static char	*find_in_history(t_list *history, t_pos *pos)
{
	char	*str;
	int		i;

	if (pos->history == 0)
	{
		str = ft_strdup(pos->cmd);
		free(pos->cmd);
		pos->cmd = NULL;
		return (str);
	}
	i = pos->history - 1;
	while (i > 0)
	{
		history = history->next;
		i = i - 1;
	}
	return (ft_strdup(history->str));
}


static int	history_len(t_list *history)
{
	int		i;

	i = 0;
	while (history != NULL)
	{
		history = history->next;
		i = i + 1;
	}
	return (i);
}

void	clear_line(int n)
{
	tputs(tgetstr("rc", NULL), 1, tput_putchar);
	tputs(tgetstr("sc", NULL), 1, tput_putchar);
	while (n > 0)
	{
		ft_putstr(" ");
		n = n - 1;
	}
}

void		get_history(t_key c, char **input, t_list *history, t_pos *pos)
{
	if (pos->cmd == NULL)
	{
		pos->cmd = ft_strdup(*input);
	}
	if (c == UP_K && pos->history < history_len(history))
		pos->history = pos->history + 1;
	else if (c == DOWN_K && pos->history > 0)
		pos->history = pos->history - 1;
	clear_line(ft_strlen(*input) + 1);
	free(*input);
	*input = find_in_history(history, pos);
	pos->cursor = 0;
}
