/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:34:00 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/11 16:57:02 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch_cmd.h"

void		kill_cmd(int sig)
{
	extern int		g_pid;

	if (g_pid != -1)
	{
		kill(g_pid, sig);
		ft_putchar('\n');
		g_pid = -1;
	}
	signal(sig, &kill_cmd);
}
