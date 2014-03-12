/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 17:48:13 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/10 12:15:18 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launch_cmd.h"

int		get_file_in(t_cmd *cmd)
{
	int		fd;

	if (cmd->file_in == NULL)
		return (-1);
	if ((fd = open(cmd->file_in, O_RDONLY)) < 0)
		return (-1);
	cmd->fd_in = fd;
	return (0);
}
