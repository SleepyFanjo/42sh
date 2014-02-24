/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 12:21:54 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/24 11:32:34 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <libft.h>
#include <unistd.h>
#include <stdlib.h>

static int	check_arrow(char *cmd)
{
	int		i;
	int		arrow;

	i = 0;
	while (*cmd == ' ' || *cmd == '\t')
		cmd = cmd + 1;
	arrow = 0;
	if (cmd[i] == '<')
		arrow = 1;
	else if (cmd[i] == '>')
		arrow = 2;
	while (cmd[i] == '<' || cmd[i] == '>')
	{
		if (cmd[i] == '<' && arrow == 2)
			return (2);
		else if (cmd[i] == '>' && arrow == 1)
			return (2);
		i = i + 1;
	}
	if (i > 2)
		return (2);
	return (0);
}

static int	check_cmd(char *cmd)
{
	int		i;
	int		error;
	int		is_ctrl;

	i = 0;
	is_ctrl = 0;
	error = 0;
	while (cmd[i] != '\0' && error != 1)
	{
		while (cmd[i] == ' ' || cmd[i] == '\t')
			i = i + 1;
		if (cmd[i] == ';' || cmd[i] == '|' || cmd[i] == '<' || cmd[i] == '>')
		{
			while (cmd[i + 1] == ' ' || cmd[i + 1] == '\t')
				i = i + 1;
			if (cmd[i + 1] == ';' || cmd[i + 1] == '|')
				error = 1;
		}
		if (check_arrow(cmd + i) == 2)
			error = 1;
		i = i + 1;
	}
	if (error == 1)
		ft_error("Error: Incorrect syntax in commande", NULL, 0);
	return (error);
}

void		ft_error(char *str, char *str_2, int mode)
{
	ft_putstr_fd(str, 2);
	if (str_2 != NULL)
		ft_putendl_fd(str_2, 2);
	else
		ft_putstr_fd("\n", 2);
	if (mode == 1)
	{
		reset_term();
		exit(1);
	}
}

void		free_table(char ***table)
{
	char	**tmp;

	tmp = *table;
	if (tmp == NULL)
		return ;
	while (*tmp != NULL)
	{
		free(*tmp);
		tmp = tmp + 1;
	}
	free(*table);
	*table = NULL;
}

int			main(int argc, char **argv, char **envp)
{
	char	**path;
	char	**env;
	t_list	*history;
	char	*cmd;

	ft_putstr("$> ");
	history = NULL;
	(void) argc;
	(void) argv;
	env = table_cpy(envp);
	get_signal();
	while ((cmd = get_input(&history)) != NULL)
	{
		path = get_path(env);
		if (!check_cmd(cmd))
			parse_cmd(cmd, path, &env);
		free(cmd);
		free_table(&path);
		ft_putstr("$> ");
	}
	return (0);
}
