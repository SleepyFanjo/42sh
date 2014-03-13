/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_one_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 17:09:27 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/13 14:55:33 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launch_cmd.h"

static int	connect_pipe(t_cmd *cmd, t_cmd *next)
{
	int		fd_pipe[2];

	if (next == NULL)
		return (-1);
	if (cmd->next_cmd == Q_PIPE)
	{
		if ((pipe(fd_pipe)) < 0)
			return (-1);
		cmd->pipe_out = fd_pipe[1];
		next->pipe_in = fd_pipe[0];
	}
	return (0);
}

static int	connect_file(t_cmd *cmd)
{
	if (cmd->in_mode != -1)
	{
		if (cmd->in_mode == Q_DOUBLE)
			get_word_in(cmd);
		else if (cmd->in_mode == Q_SIMPLE)
			get_file_in(cmd);
	}
	if (cmd->out_mode != -1)
	{
		if (cmd->out_mode == Q_SIMPLE)
			get_simple_fd_out(cmd);
		else if (cmd->out_mode == Q_DOUBLE)
			get_double_fd_out(cmd);
	}
	return (0);
}

int			launch_one_cmd(t_cmd *cmd, t_cmd *next)
{
	int		ret;

	connect_file(cmd);
	connect_pipe(cmd, next);
	if (!(ret = exec_builtin(cmd)))
	{
		return (launch_fork(cmd));
	}
	return (ret);
}
