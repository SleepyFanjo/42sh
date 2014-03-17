/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 10:48:25 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/10 14:03:41 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launch_cmd.h"

int		exec_cmd(t_cmd *cmd)
{
	char	*path;

	if ((path = get_path(cmd->cmd, g_env)) == NULL)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(cmd->cmd, 2);
		exit(-1);
	}
	execve(path, cmd->arg, g_env);
	return (0);
}
