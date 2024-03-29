/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_check_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 10:30:54 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/14 14:49:06 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_cmd		*q_check_cmd(t_cmd *cmd)
{
	t_token		*cat;
	char		*str;

	str = ft_strdup("cat");
	cat = q_utility_token(str, 0);
	free(str);
	cat->type = Q_CMD;
	if (cmd->cmd == NULL && (cmd->file_in != NULL || cmd->file_out != NULL))
		q_add_in_cmd(cat, NULL, cmd);
	if (cmd->next_cmd != -1 && cmd->cmd == NULL)
	{
		q_error("Syntax error:no command before a logical operator", NULL, 0);
		free(cmd);
		return (NULL);
	}
	free(cat->name);
	free(cat);
	return (cmd);
}
