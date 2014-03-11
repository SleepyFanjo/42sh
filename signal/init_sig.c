/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:26:41 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/11 17:18:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch_cmd.h"

int		init_sig(void)
{
	signal(SIGHUP, quit_term);
	signal(SIGINT, kill_cmd);
	signal(SIGQUIT, kill_cmd);
	signal(SIGKILL, kill_cmd);
	signal(SIGTSTP, kill_cmd);
	signal(SIGCONT, kill_cmd);
	return (0);
}
