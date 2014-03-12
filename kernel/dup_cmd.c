/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 10:54:13 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/10 12:14:34 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launch_cmd.h"

static int	my_dup2(int fd1, int fd2, int fd_connect)
{
	if (fd1 >= 0)
	{
		if (dup2(fd1, fd_connect) < 0)
		{
			ft_printf("%rSystem call dup2 fail (file)\n");
			return (-1);
		}
	}
	else if (fd2 >= 0)
	{
		if (dup2(fd2, fd_connect) < 0)
		{
			ft_printf("%rSystem call dup2 fail (pipe)\n");
			return (-1);
		}
	}
	return (0);
}

int			dup_cmd(t_cmd *cmd)
{
	if (my_dup2(cmd->fd_in, cmd->pipe_in, 0))
		return (-1);
	if (my_dup2(cmd->fd_out, cmd->pipe_out, 1))
		return (-1);
	return (0);
}
