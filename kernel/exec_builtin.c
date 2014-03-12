/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 14:41:29 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/12 15:05:29 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch_cmd.h"

static void	init_fd(int *fd_builtin, t_cmd *cmd)
{
	if (cmd->fd_in != -1)
		fd_builtin[IN_B] = cmd->fd_in;
	else if (cmd->pipe_in != -1)
		fd_builtin[IN_B] = cmd->pipe_in;
	else
		fd_builtin[IN_B] = 0;
	if (cmd->fd_out != -1)
		fd_builtin[OUT_B] = cmd->fd_out;
	else if (cmd->pipe_out != -1)
		fd_builtin[OUT_B] = cmd->pipe_out;
	else
		fd_builtin[OUT_B] = 1;
}

static void	close_fd(t_cmd *cmd)
{
	if (cmd->fd_in != -1)
	{
		if (close(cmd->fd_in) < 0)
			ft_printf("%rUnable to close fd_in\n");
	}
	if (cmd->pipe_in != -1)
	{
		if (close(cmd->pipe_in) < 0)
			ft_printf("%rUnable to close pipe_in\n");
	}
	if (cmd->fd_out != -1)
	{
		if (close(cmd->fd_out) < 0)
			ft_printf("%rUnable to close fd_out\n");
	}
	if (cmd->pipe_out != -1)
	{
		close(cmd->pipe_out);
	}
}

static int	exec_builtin_2(t_cmd *cmd, int *fd_builtin)
{
	if (ft_strcmp(cmd->cmd, "echo") == 0)
	{
		ft_echo(cmd->arg, fd_builtin[OUT_B]);
		close_fd(cmd);
		return (1);
	}
	if (ft_strcmp(cmd->cmd, "env") == 0)
	{
		env(cmd, table_cpy(g_env), fd_builtin[OUT_B]);
		close_fd(cmd);
		return (1);
	}
	if (ft_strcmp(cmd->cmd, "cd") == 0)
	{
		move_dir(cmd, &g_env);
		close_fd(cmd);
		return (1);
	}

	return (0);
}

int			exec_builtin(t_cmd *cmd)
{
	int		fd_builtin[2];

	init_fd(fd_builtin, cmd);
	if (ft_strcmp(cmd->cmd, "setenv") == 0)
	{
		my_setenv(cmd, fd_builtin);
		close_fd(cmd);
		return (1);
	}
	if (ft_strcmp(cmd->cmd, "unsetenv") == 0)
	{
		my_unsetenv(cmd);
		close_fd(cmd);
		return (1);
	}
	if (ft_strcmp(cmd->cmd, "exit") == 0)
	{
		ft_exit(cmd, fd_builtin[OUT_B]);
		close_fd(cmd);
		return (1);
	}
	return (exec_builtin_2(cmd, fd_builtin));
}
