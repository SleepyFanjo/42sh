/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fucking_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 17:40:21 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/14 18:12:51 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch_cmd.h"

static int	is_cmd(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			return (0);
		i = i + 1;
	}
	return (1);
}

static int	exec_arg(char *cmd, char **arg, char **envp)
{
	pid_t	pid;
	char	*path;
	int		stat;

	path = get_path(cmd, envp);
	stat = 0;
	if (path == NULL)
	{
		q_error("Can't find path, sorry :(", NULL, 0);
		return (1);
	}
	if ((pid = fork()) == -1)
	{
		q_error("Fork you !", NULL, 0);
		return (1);
	}
	if (pid == 0)
		execve(path, arg, envp);
	else
		wait(&stat);
	return (stat);
}

static void	free_table(char ***table)
{
	char	**copy;
	int		i;

	copy = *table;
	i = 0;
	while (copy && copy[i])
	{
		free(copy[i]);
		i = i + 1;
	}
	if (copy)
		free(copy);
	*table = NULL;
}

int			env(t_cmd *cmd, char **envp, int fd)
{
	int		i[2];

	i[0] = 1;
	i[1] = 0;
	if ((cmd->arg)[1] != NULL && !ft_strcmp((cmd->arg)[i[0]], "-i"))
	{
		free_table(&envp);
		i[0] = i[0] + 1;
	}
	if ((cmd->arg)[1] == NULL)
	{
		print_env(envp, fd);
		return (0);
	}
	while ((cmd->arg)[i[0]] != NULL && !is_cmd((cmd->arg)[i[0]]))
	{
		modify_env(&envp, (cmd->arg)[i[0]]);
		i[0] = i[0] + 1;
	}
	if ((cmd->arg)[i[0]] == NULL)
		print_env(envp, fd);
	else
		i[1] = exec_arg((cmd->arg)[i[0]], cmd->arg + i[0], envp);
	free_table(&envp);
	return (i[1]);
}
