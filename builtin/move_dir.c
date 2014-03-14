/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 12:25:46 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/14 18:56:40 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch_cmd.h"
#include <libft.h>
#include <unistd.h>
#include <stdlib.h>

static int	find_env(char *env, char **envp)
{
	int		i;
	int		j;

	i = 0;
	while (envp[i] != NULL)
	{
		j = 0;
		while (envp[i][j] != '=' && envp[i][j] != '\0')
			j = j + 1;
		if (ft_strncmp(env, envp[i], j) == 0)
			return (i);
		i = i + 1;
	}
	return (-1);
}

static void	modify_pwd(char *pwd, char *old_pwd, char ***envp)
{
	char	*new_pwd;
	char	*new_old_pwd;
	int		i;

	new_pwd = ft_strdup("PWD=");
	new_old_pwd = ft_strdup("OLDPWD=");
	ft_str_realloc_cat(&new_pwd, pwd);
	ft_str_realloc_cat(&new_old_pwd, old_pwd);
	i = find_env("PWD", *envp);
	if (i != -1)
		(*envp)[i] = new_pwd;
	else
		modify_env(envp, new_pwd);
	i = find_env("OLDPWD", *envp);
	if (i != -1)
		(*envp)[i] = new_old_pwd;
	else
		modify_env(envp, new_old_pwd);
}

char		*get_env(char **envp, char *env)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	c = (char *)malloc(sizeof(char));
	*c = '\0';
	while (envp[i] != NULL)
	{
		j = 0;
		while (envp[i][j] != '=' && envp[i][j] != '\0')
			j = j + 1;
		if (ft_strncmp(env, envp[i], j) == 0)
			return (envp[i] + j + 1);
		i = i + 1;
	}
	return (c);
}

static int	dir_error(char *str)
{
	ft_putendl_fd(str, 2);
	return (1);
}

int			move_dir(t_cmd *cmd, char ***envp)
{
	char	buf[BUFF_SIZE + 1];

	if ((cmd->arg)[1] == NULL)
	{
		if (chdir(get_env(*envp, "HOME")) == -1)
			return (dir_error("Error: Can't reach home directory"));
		else
			modify_pwd(get_env(*envp, "HOME"), get_env(*envp, "PWD"), envp);
	}
	else if (!ft_strcmp(cmd->arg[1], "-"))
	{
		if (chdir(get_env(*envp, "OLDPWD")) == -1)
			return (dir_error("Error: Can't reach old pwd"));
		else
			modify_pwd(get_env(*envp, "OLDPWD"), get_env(*envp, "PWD"), envp);
	}
	else
	{
		if (chdir(cmd->arg[1]) == -1)
			return (dir_error("Error: Can't reach directory"));
		else
			modify_pwd(getcwd(buf, BUFF_SIZE), get_env(*envp, "PWD"), envp);
	}
	return (0);
}
