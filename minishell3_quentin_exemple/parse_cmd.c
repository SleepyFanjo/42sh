/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 15:02:05 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/01 14:02:30 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "struct.h"
#include <unistd.h>
#include <libft.h>

t_cmd		*fill_cmd(char *cmd, int *i)
{
	t_cmd	*elem;

	elem = init_elem();
	while (cmd[*i] != '\0')
	{
		while (cmd[*i] == ' ' || cmd[*i] == '\t')
			*i = *i + 1;
		if (cmd[*i] == '\0')
			return (elem);
		if (cmd[*i] == '<')
			get_fd_in(elem, cmd, i);
		else if (cmd[*i] == '>')
			get_fd_out(elem, cmd, i);
		else if (cmd[*i] == '|')
		{
			*i = *i + 1;
			return (elem);
		}
		else
			get_cmd(elem, cmd, i);
	}
	return (elem);
}

void		reparse_cmd(char *cmd, char **path, char ***envp)
{
	t_cmd	*elem;
	t_lst	*list;
	int		i;

	i = 0;
	list = NULL;
	while (cmd[i] != '\0')
	{
		elem = fill_cmd(cmd, &i);
		if (elem->cmd != NULL)
			add_in_list(&list, elem);
	}
	if (find_builtin(list, envp))
		launch_fork(list, path, *envp);
	free_list(&list);
}

void		parse_cmd(char *cmd, char **path, char ***envp)
{
	int		i;
	char	**cmd_lst;

	i = 0;
	cmd_lst = ft_strsplit(cmd, ';');
	while (cmd_lst[i] != NULL)
	{
		reparse_cmd(cmd_lst[i], path, envp);
		i = i + 1;
	}
	free_table(&cmd_lst);
}
