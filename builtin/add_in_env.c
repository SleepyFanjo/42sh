/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_in_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 15:39:43 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/18 15:52:35 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <libft.h>

static char	*get_variable(char **arg)
{
	char		*env;

	env = ft_strdup(arg[1]);
	ft_str_realloc_cat(&env, "=");
	if (arg[2] != NULL)
		ft_str_realloc_cat(&env, arg[2]);
	return (env);
}

static void	print_env(char **env)
{
	int		i;

	i = 0;
	while (env != NULL && env[i] != NULL)
	{
		ft_putendl(env[i]);
		i = i + 1;
	}
}

static int	verify_name(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
		{
			ft_error("Error: Syntax error", NULL, 0);
			return (1);
		}
		i = i + 1;
	}
	return (0);
}

void		add_in_env(t_cmd *cmd, char ***envp)
{
	char		*env;
	int			i;

	if (cmd->arg[1] == NULL)
	{
		print_env(*envp);
		return ;
	}
	i = 0;
	while (cmd->arg[i] != NULL)
		i = i + 1;
	if (i > 3)
	{
		ft_error("Error : Too many arguments", NULL, 0);
		return ;
	}
	if (verify_name(cmd->arg[1]) == 1)
		return ;
	env = get_variable(cmd->arg);
	modify_env(envp, env);
}
