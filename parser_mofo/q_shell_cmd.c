/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_shell_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 12:19:15 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/14 15:49:00 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int			is_subshell(t_token *elem)
{
	return (elem->type == Q_SHELL);
}

t_cmd		*q_shell_cmd(t_token *elem, char *argv, t_list **token)
{
	t_cmd	*cmd;
	t_token	*next;

	(*token) = (*token)->next;
	if (*token != NULL)
		next = (t_token *)(*token)->elem;
	else
		next = NULL;
	if (next != NULL && next->type != Q_CTRL)
	{
		ft_putendl_fd("Error : no control after )", 2);
		return (NULL);
	}
	cmd = q_init_cmd();
	cmd->cmd = ft_strdup(argv);
	if (next != NULL)
	{
		q_add_ctrl(next->name, cmd);
		(*token) = (*token)->next;
	}
	q_add_in_arg(argv, cmd);
	q_add_in_arg(elem->name, cmd);
	return (cmd);
}
