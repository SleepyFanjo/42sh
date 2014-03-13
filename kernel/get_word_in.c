/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 17:26:44 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/13 17:39:45 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launch_cmd.h"

int			get_word_in(t_cmd *cmd)
{
	int		fd_pipe[2];
	char	*line;

	if (pipe(fd_pipe) < 0)
		return (-1);
	if ((line = select_cmd(6, "()()> ", NULL)) == NULL)
		return (-1);
	while (ft_strcmp(line, cmd->file_in) != 0)
	{
		write(fd_pipe[1], line, ft_strlen(line));
		write(fd_pipe[1], "\n", 1);
		ft_putstr(">");
		free(line);
		if ((line = tmp_prompt()) == NULL)
			return (-1);
	}
	free(line);
	close(fd_pipe[1]);
	cmd->fd_in = fd_pipe[0];
	return (0);
}
