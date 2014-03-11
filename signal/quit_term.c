/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:31:25 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/11 17:18:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch_cmd.h"

void		quit_term(int sig)
{
	extern int		g_pid;

	if (g_pid != -1)
		kill_cmd(SIGQUIT);
	else
		exit(0);
	signal(sig, quit_term);
}
