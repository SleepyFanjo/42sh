/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 15:26:29 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/07 17:11:06 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int		q_file_error(void)
{
	ft_putendl_fd("Error : nothing after file redirection", 2);
	return (1);
}

int		q_add_in_cmd(t_token *elem, t_token *next, t_cmd *cmd)
{
	if (elem->type == Q_LINK)
		return (q_add_link(elem->name, next, cmd));
	if (elem->type == Q_FILE)
		return (0);
	if (elem->type == Q_ARG)
		return (q_add_in_arg(elem->name, cmd));
	if (elem->type == Q_CTRL)
		return (q_add_ctrl(elem->name, cmd));
	if (elem->type == Q_CMD || elem->type == Q_EXE)
	{
		cmd->cmd = ft_strdup(elem->name);
		return (q_add_in_arg(elem->name, cmd));
	}
	return (0);
}

int		q_is_ctrl(t_token *elem)
{
	return (elem->type == Q_CTRL);
}

t_cmd	*q_init_cmd(void)
{
	t_cmd	*cmd;

	if ((cmd = (t_cmd *)malloc(sizeof(t_cmd))) == NULL)
		q_error("Error : can't malloc", NULL, 1);
	cmd->cmd = NULL;
	cmd->arg = NULL;
	cmd->pipe_in = -1;
	cmd->file_in = NULL;
	cmd->file_out = NULL;
	cmd->in_mode = -1;
	cmd->out_mode = -1;
	cmd->next_cmd = -1;
	return (cmd);
}
