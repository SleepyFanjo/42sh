/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_in_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 15:57:08 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/18 16:32:55 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <libft.h>


static int	match(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == '*' && *(s1 + 1) != '\0' && *s2 == '\0')
		return (0);
	if (*s1 == '?' || *s1 == *s2)
		return (match(s1 + 1, s2 + 1));
	if (*s1 == '*')
		return (match(s1 + 1, s2) || match(s1, s2 + 1));
	return (0);
}

static void	remove_variable(char **envp, int i)
{
	char	*str;

	free(envp[i]);
	envp[i] = NULL;
	i = i + 1;
	while (envp[i] != NULL)
	{
		str = envp[i - 1];
		envp[i - 1] = envp[i];
		envp[i] = str;
		i = i + 1;
	}
}

static int	variable_match(char *str, char *env)
{
	int		i;
	char	c;
	int		ret;

	i = 0;
	while (env[i] != '=' && env[i] != '\0')
		i = i + 1;
	c = env[i];
	env[i] = '\0';
	ret = match(str, env);
	env[i] = c;
	return (ret);
}

static void	env_match(char *str, char ***envp)
{
	int		i;

	i = 0;
	while (*envp != NULL && (*envp)[i] != NULL)
	{
		if (variable_match(str, (*envp)[i]))
		{
			remove_variable(*envp, i);
			i = 0;
		}
		else
			i = i + 1;
	}
}

void		delete_in_env(t_cmd *cmd, char ***envp)
{
	int		i;

	if (cmd->arg[1] == NULL)
	{
		ft_error("Error: Too few arguments", NULL, 0);
		return ;
	}
	i = 1;
	while ((cmd->arg)[i] != NULL)
	{
		env_match((cmd->arg)[i], envp);
		i = i + 1;
	}
}
