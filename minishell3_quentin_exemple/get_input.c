/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 15:42:56 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/29 17:10:09 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <termcap.h>
#include <fcntl.h>
#include <libft.h>

char		*g_input = NULL;

static char	*init_input(void)
{
	char	*str;

	if ((str = (char *)malloc(sizeof(char))) == NULL)
		ft_error("Error can't malloc str", NULL, 1);
	str[0] = '\0';
	return (str);
}

static void	init_buff(char *buff)
{
	int		i;

	i = 0;
	while (i < 20)
	{
		buff[i] = '\0';
		i = i + 1;
	}
}

static int	get_entry(char *buff)
{
	read(0, buff, 19);
	if (*(unsigned long int *)buff == 10)
		return (0);
	return (1);
}

char		*get_input(t_list **history)
{
	t_pos	pos;
	char	buff[20];

	make_raw();
	g_input = init_input();
	init_buff(buff);
	pos.cursor = 0;
	pos.history = 0;
	pos.cmd = NULL;
	tputs(tgetstr("sc", NULL), 1, tput_putchar);
	while (get_entry(buff))
	{
		apply_entry(buff, &g_input, *history, &pos);
		print_input(g_input);
		move_cursor(ft_strlen(g_input) - pos.cursor);
		init_buff(buff);
	}
	add_in_history(g_input, history);
	if (pos.cmd != NULL)
		free(pos.cmd);
	reset_term();
	ft_putstr("\n");
	return (g_input);
}
