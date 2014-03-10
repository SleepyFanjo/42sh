/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 19:48:06 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/10 13:24:38 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launch_cmd.h"

static int	close_pipe_father(t_cmd *cmd)
{
	int		res;

	res = 0;
	if (cmd->pipe_in > -1)
	{
		if (close(cmd->pipe_in) < 0)
			res = -1;
	}
	if (cmd->pipe_out > -1)
	{
		if (close(cmd->pipe_out) < 0)
			res = -1;
	}
	return (res);
}

void		launch_fork(t_cmd *cmd)
{
	pid_t	pid;

	if ((pid = fork()) < 0)
	{
		ft_printf("%rUnable to create fork\n");
		return ;
	}
	if (pid == 0)
	{
		dup_cmd(cmd);
		exec_cmd(cmd);
		exit(1);
	}
	else
	{
		if (close_pipe_father(cmd))
		{
			ft_printf("%rUnable to close pipe\n");
			kill(pid, SIGINT);
		}
		wait(&(cmd->return_val));
	}
}
