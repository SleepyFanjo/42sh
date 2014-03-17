/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:34:00 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/17 15:16:13 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch_cmd.h"

void		kill_cmd(int sig)
{
	extern int		g_pid;

	if (g_pid != -1)
	{
		if (sig == SIGTSTP)
			ft_putstr("\nJob controls are not done, killing cmd");
		kill(g_pid, 9);
		ft_putchar('\n');
		g_pid = -1;
	}
	signal(sig, &kill_cmd);
}
