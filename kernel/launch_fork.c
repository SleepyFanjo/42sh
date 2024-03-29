/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 19:48:06 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/14 15:58:55 by qchevrin         ###   ########.fr       */
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

static int	father(t_cmd *cmd, pid_t pid)
{
	g_pid = pid;
	if (close_pipe_father(cmd))
	{
		ft_putstr_fd("Unable to close pipe\n", 2);
		kill(pid, SIGINT);
	}
	wait(&(cmd->return_val));
	if (g_pid == -1)
		return (-1);
	g_pid = -1;
	return (0);
}

int			launch_fork(t_cmd *cmd)
{
	pid_t	pid;
	int		ret;

	ret = 0;
	if ((pid = fork()) < 0)
	{
		ft_putstr_fd("Unable to create fork\n", 2);
		return (-1);
	}
	if (pid == 0)
	{
		dup_cmd(cmd);
		exec_cmd(cmd);
		exit(1);
	}
	else
		ret = father(cmd, pid);
	return (ret);
}
