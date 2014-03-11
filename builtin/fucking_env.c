/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fucking_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 17:40:21 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/11 14:55:29 by qchevrin         ###   ########.fr       */
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

static void	exec_cmd(char *cmd, char **arg, char **envp)
{
	pid_t	pid;
	char	**path;

	path = get_path(cmd, envp);
	if ((pid = fork()) == -1)
	{
		ft_error("Fork you !", NULL, 0);
		return ;
	}
	if (pid == 0)
		execve(path, arg, envp);
	else
		wait(NULL);
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

void		env(t_cmd *cmd, char **envp)
{
	int		i;

	i = 1;
	if ((cmd->arg)[1] != NULL && !ft_strcmp((cmd->arg)[i], "-i"))
	{
		free_table(&envp);
		i = i + 1;
	}
	if ((cmd->arg)[1] == NULL)
	{
		print_env(envp);
		return ;
	}
	while ((cmd->arg)[i] != NULL && !is_cmd((cmd->arg)[i]))
	{
		modify_env(&envp, (cmd->arg)[i]);
		i = i + 1;
	}
	if ((cmd->arg)[i] == NULL)
		print_env(envp);
	else
		exec_cmd((cmd->arg)[i], cmd->arg + i, envp);
	free_table(&envp);
}
