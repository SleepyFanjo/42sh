/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:01:53 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/07 17:03:33 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	q_free_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i = i + 1;
	}
}

char	**q_tabjoin(char **tab, char *str)
{
	char	**copy;
	int		i;

	i = 0;
	while (tab[i] != NULL)
		i = i + 1;
	if ((copy = (char **)malloc(sizeof(char *) * (i + 2))) == NULL)
		q_error("Error : can't malloc", NULL, 1);
	i = 0;
	while (tab[i] != NULL)
	{
		copy[i] = ft_strdup(tab[i]);
		i = i + 1;
	}
	copy[i] = ft_strdup(str);
	copy[i + 1] = NULL;
	q_free_tab(tab);
	return (copy);
}

int		q_add_in_arg(char *str, t_cmd *cmd)
{
	if (cmd->arg == NULL)
	{
		if ((cmd->arg = (char **)malloc(sizeof(char *) * 2)) == NULL)
			q_error("Error : can't malloc", NULL, 1);
		(cmd->arg)[0] = ft_strdup(str);
		(cmd->arg)[1] = NULL;
		return (0);
	}
	cmd->arg = q_tabjoin(cmd->arg, str);
	return (0);
}

int		q_add_link(char *link, t_token *file, t_cmd *cmd)
{
	if (file == NULL)
		return (q_file_error());
	if (file->type != Q_FILE)
	{
		ft_putstr_fd("Error : elements after ", 2);
		ft_putstr_fd(link, 2);
		ft_putendl_fd(" is not a file.", 2);
		return (1);
	}
	if (link[0] == '<')
	{
		cmd->file_in = ft_strdup(file->name);
		cmd->in_mode = Q_SIMPLE;
		if (link[1] == link[0])
			cmd->in_mode = Q_DOUBLE;
	}
	if (link[0] == '>')
	{
		cmd->file_out = ft_strdup(file->name);
		cmd->out_mode = Q_SIMPLE;
		if (link[1] == link[0])
			cmd->out_mode = Q_DOUBLE;
	}
	return (0);
}

int		q_add_ctrl(char *str, t_cmd *cmd)
{
	if (!ft_strcmp(str, ";") || !ft_strcmp(str, "&"))
		cmd->next_cmd = Q_SEP;
	if (!ft_strcmp(str, "|"))
		cmd->next_cmd = Q_PIPE;
	if (!ft_strcmp(str, "&&"))
		cmd->next_cmd = Q_AND;
	if (!ft_strcmp(str, "||"))
		cmd->next_cmd = Q_OR;
	return (0);
}
