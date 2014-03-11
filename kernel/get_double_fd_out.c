/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double_fd_out.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 19:30:42 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/10 14:10:32 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launch_cmd.h"

int		get_double_fd_out(t_cmd *cmd)
{
	int		fd;

	if (cmd->file_out == NULL)
		return (-1);
	if ((fd = open(cmd->file_out, O_WRONLY | O_CREAT | O_APPEND, 0644)) < 0)
		return (-1);
	cmd->fd_out = fd;
	return (0);
}
