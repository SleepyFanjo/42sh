/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 12:05:49 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/04 14:22:28 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <libft.h>

char		**table_cpy(char **table)
{
	int		i;
	char	**copy;

	i = 0;
	while (table[i] != NULL)
		i = i + 1;
	if ((copy = (char **)malloc((i + 1) * sizeof(char *))) == NULL)
		ft_error("Error: Can't malloc", NULL, 1);
	i = 0;
	while (table[i] != NULL)
	{
		copy[i] = ft_strdup(table[i]);
		i = i + 1;
	}
	copy[i] = NULL;
	return (copy);
}

static int	is_builtin(char *cmd)
{
	if (!ft_strcmp("exit", cmd) || !ft_strcmp("cd", cmd))
		return (1);
	if (!ft_strcmp("setenv", cmd) || !ft_strcmp("unsetenv", cmd))
		return (1);
	if (!ft_strcmp("env", cmd))
		return (1);
	return (0);
}

static void	exec_builtin(t_cmd *cmd, char ***envp)
{
	if (ft_strcmp("cd", cmd->cmd) == 0)
		move_dir(cmd, envp);
	else if (ft_strcmp("exit", cmd->cmd) == 0)
		ft_exit(cmd);
	else if (ft_strcmp("env", cmd->cmd) == 0)
		fucking_env(cmd, table_cpy(*envp));
	else if (ft_strcmp("setenv", cmd->cmd) == 0)
		add_in_env(cmd, envp);
	else if (ft_strcmp("unsetenv", cmd->cmd) == 0)
		delete_in_env(cmd, envp);
}

int			find_builtin(t_lst *list, char ***envp)
{
	int		ret;

	ret = 1;
	while (list != NULL)
	{
		if (is_builtin(list->cmd->cmd))
		{
			exec_builtin(list->cmd, envp);
			ret = 0;
		}
		list = list->next;
	}
	return (ret);
}
