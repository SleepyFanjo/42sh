/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 10:38:55 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/01 15:40:07 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <libft.h>
#include <termcap.h>
#include <signal.h>


static void		clear_input(char *str)
{
	if (str != NULL)
	{
		str[0] = '\0';
	}
}

static void		quit_term(int sig)
{
	extern int		g_pid;

	if (g_pid != -1)
		kill_cmd(sig);
	else
	{
		reset_term();
		exit(0);
	}
}

void			kill_cmd(int sig)
{
	extern int		g_pid;
	extern char		*g_input;

	if (g_pid != -1)
		kill(g_pid, sig);
	reset_term();
	if (g_pid == -1)
		ft_putstr("\n$> ");
	else
		ft_putstr("\n");
	make_raw();
	tputs(tgetstr("sc", NULL), 1, tput_putchar);
	clear_input(g_input);
	signal(sig, &kill_cmd);
}

void			get_signal(void)
{
	signal(SIGHUP, &quit_term);
	signal(SIGINT, &kill_cmd);
	signal(SIGQUIT, &kill_cmd);
	signal(SIGKILL, &kill_cmd);
	signal(SIGTSTP, &kill_cmd);
	signal(SIGCONT, &kill_cmd);
}
