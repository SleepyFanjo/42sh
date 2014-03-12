/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_in_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 15:39:43 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/10 16:16:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch_cmd.h"

static char	*get_variable(char **arg)
{
	char		*env;

	env = ft_strdup(arg[1]);
	if ((ft_str_realloc_cat(&env, "=")) == NULL)
		return (NULL);
	if (arg[2] != NULL)
		ft_str_realloc_cat(&env, arg[2]);
	return (env);
}

static int	verify_name(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
		{
			ft_printf("%rSyntax error: %s\n", str);
			return (1);
		}
		i = i + 1;
	}
	return (0);
}

int		add_in_env(t_cmd *cmd, char ***envp, int *fd_b)
{
	char		*env;
	int			i;

	if (cmd->arg[1] == NULL)
	{
		print_env(*envp, fd_b[OUT_B]);
		return (0);
	}
	i = 0;
	while (cmd->arg[i] != NULL)
		i = i + 1;
	if (i > 3)
	{
		ft_printf("%rError : Too many arguments\n");
		return (1);
	}
	if (verify_name(cmd->arg[1]) == 1)
		return (1);
	if ((env = get_variable(cmd->arg)) == NULL)
	{
		ft_printf("Allocation fail\n");
		return (1);
	}
	modify_env(envp, env);
	return (0);
}
