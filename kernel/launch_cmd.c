/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 16:59:14 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/13 14:50:46 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launch_cmd.h"
#include "struct.h"

static int	my_launch(t_cmd *cmd, t_list *next)
{
	if (next != NULL)
		return (launch_one_cmd(cmd, (t_cmd *)(next->elem)));
	else
		return (launch_one_cmd(cmd, NULL));
}

static int	test_next(int *ret, t_list *cmd, t_cmd *prvs)
{
	if (prvs->next_cmd == Q_AND)
	{
		if (prvs->return_val == 0)
			*ret = my_launch((t_cmd *)cmd->elem, cmd->next);
		else
			return (1);
	}
	else if (prvs->next_cmd == Q_OR)
	{
		if (prvs->return_val != 0)
			*ret = my_launch((t_cmd *)cmd->elem, cmd->next);
		else
			return (1);
	}
	else
		*ret = my_launch((t_cmd *)cmd->elem, cmd->next);
	return (0);
}

void		launch_cmd(t_list *cmd)
{
	t_cmd		*prvs;
	int			ret;

	prvs = NULL;
	ret = 0;
	while (cmd != NULL && !(ret))
	{
		if (prvs != NULL)
		{
			if (test_next(&ret, cmd, prvs))
				return ;
		}
		else
			ret = my_launch((t_cmd *)cmd->elem, cmd->next);
		prvs = (t_cmd *)cmd->elem;
		cmd = cmd->next;
	}
}
