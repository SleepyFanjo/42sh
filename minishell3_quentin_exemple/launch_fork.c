/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:28:51 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/01 13:54:22 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h>
#include <libft.h>
#include <unistd.h>
#include <stdlib.h>

/*
** I use this global for signal handling
*/

pid_t		g_pid = -1;

static void	read_on_stdin(char *end)
{
	int		fd[2];
	int		ret;
	char	buff[RD_SIZE + 1];

	pipe(fd);
	ft_putstr("heredoc : ");
	dup2(fd[0], 0);
	while ((ret = read(1, buff, RD_SIZE)) != -1)
	{
		buff[ret - 1] = '\0';
		if (ft_strcmp(buff, end) == 0)
		{
			close(fd[1]);
			return ;
		}
		write(fd[1], buff, ret - 1);
		write(fd[1], "\n", 1);
		ft_putstr("heredoc : ");
	}
}

static int	open_correctly(char *file, int mode)
{
	int		fd;

	if (mode == 0)
	{
		if ((fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644)) == -1)
			ft_error("Error can't create ", file, 1);
	}
	else
	{
		if ((fd = open(file, O_WRONLY | O_APPEND)) == -1)
			ft_error("Error can't open ", file, 1);
	}
	return (fd);
}

static void	dup_and_close(t_cmd *elem, t_lst *list, int *fd)
{
	int		fd_dup;

	if (elem->pipe != -1)
		dup2(elem->pipe, 0);
	else if (elem->fd_in != NULL && elem->end == NULL)
	{
		if ((fd_dup = open(elem->fd_in, O_RDONLY)) == -1)
			ft_error("Error: Can't open ", elem->fd_in, 1);
		dup2(fd_dup, 0);
	}
	else if (elem->fd_in != NULL)
		read_on_stdin(elem->end);
	if (list->next != NULL && list->cmd->fd_out == NULL)
		dup2(fd[1], 1);
	else if (list->cmd->fd_out != NULL)
	{
		fd_dup = open_correctly(list->cmd->fd_out, list->cmd->fd_mode);
		dup2(fd_dup, 1);
	}
	close(fd[0]);
}

void		launch_fork(t_lst *list, char **path, char **envp)
{
	int		fd[2];

	while (list != NULL && list->cmd != NULL && list->cmd->cmd != NULL)
	{
		pipe(fd);
		if ((g_pid = fork()) == -1)
			ft_error("Fork you !", NULL, 1);
		else if (g_pid == 0)
		{
			dup_and_close(list->cmd, list, fd);
			list->cmd->cmd = get_cmd_input(path, list->cmd->cmd);
			execve(list->cmd->cmd, list->cmd->arg, envp);
			exit(1);
		}
		else
		{
			wait(NULL);
			g_pid = -1;
			close(fd[1]);
			list = list->next;
			if (list != NULL && list->cmd->fd_in == NULL)
				list->cmd->pipe = fd[0];
		}
	}
}
