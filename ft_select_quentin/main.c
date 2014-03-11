/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 18:21:11 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/11 17:16:30 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <libft.h>
#include <termcap.h>
#include <signal.h>
#include <sys/ioctl.h>

t_param		g_param;

static void	update_print(int sig)
{
	(void) sig;
	print_list(get_term_size(), g_param.list);
	signal(SIGWINCH, &update_print);
}

static void	quit_correctly(int sig)
{
	char	cp[2];

	(void) sig;
	if (isatty(1) == 0)
	{
		signal(SIGTSTP, &quit_correctly);
		return ;
	}
	cp[1] = 0;
	cp[0] = (g_param.old_term).c_cc[VSUSP];
	exit_clean(g_param, 0);
	clear_term();
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}

static void	restore_window(int sig)
{
	(void) sig;
	ft_make_raw();
	print_list(get_term_size(), g_param.list);
	signal(SIGTSTP, &quit_correctly);
	signal(SIGCONT, &restore_window);
}

static void	get_signal(void)
{
	signal(SIGWINCH, &update_print);
	signal(SIGTSTP, &quit_correctly);
	signal(SIGCONT, &restore_window);
}

int			main(int argc, char **argv)
{
	char		read_buff[4];

	if (argc < 2)
		ft_error("Error: Too few arguments");
	if (tgetent(NULL,  getenv("TERM")) < 1)
		ft_error("Error : couldn't load term");
	g_param.old_term = ft_make_raw();
	g_param.list = init_list(argc, argv);
	fill_list(argc, argv, &(g_param.list));
	get_signal();
	print_list(get_term_size(), g_param.list);
	get_read(read_buff, g_param);
	g_param.list = get_begin_list(g_param.list);
	clean_list(&(g_param.list));
	exit_clean(g_param, 0);
	return_to_shell(g_param.list);
	return (0);
}
