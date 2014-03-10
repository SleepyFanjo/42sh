/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 16:59:14 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/10 15:01:40 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launch_cmd.h"
#include "struct.h"

static void	my_launch(t_cmd *cmd, t_list *next)
{
	if (next != NULL)
		launch_one_cmd(cmd, (t_cmd *)(next->elem));
	else
		launch_one_cmd(cmd, NULL);
}

void		launch_cmd(t_list *cmd)
{
	t_cmd		*prvs;

	prvs = NULL;
	while (cmd != NULL)
	{
		if (prvs != NULL)
		{
			if (prvs->next_cmd == Q_AND)
			{
				if (prvs->return_val == 0)
					my_launch((t_cmd *)cmd->elem, cmd->next);
				else
					return ;
			}
			else if (prvs->next_cmd == Q_OR)
			{
				if (prvs->return_val != 0)
					my_launch((t_cmd *)cmd->elem, cmd->next);
				else
					return ;
			}
			else
				my_launch((t_cmd *)cmd->elem, cmd->next);
		}
		else
			my_launch((t_cmd *)cmd->elem, cmd->next);
		prvs = (t_cmd *)cmd->elem;
		cmd = cmd->next;
	}
}
