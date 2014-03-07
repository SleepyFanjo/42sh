/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:02:59 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/07 15:31:16 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_cmd		*q_fill_cmd(t_list **token_list)
{
	t_cmd	*cmd;
	t_token	*elem;

	cmd = q_init_cmd();
	while (*token_list != NULL) 
	{
		elem = NULL;
		if ((*token_list)->next != NULL)
			elem = (*token_list)->next->elem;
		if (q_add_in_cmd((*token_list)->elem, elem, cmd))
			return (NULL);
		if (q_is_ctrl((t_token *)(*token_list)->elem))
		{
			(*token_list) = (*token_list)->next;
			return (q_check_cmd(cmd));
		}
		(*token_list) = (*token_list)->next;
	}
	return (q_check_cmd(cmd));
}


t_list		*q_parser(t_list *token_list)
{
	t_list	*list;
	int		error;

	list = NULL;
	while (token_list != NULL)
	{
		error = q_add_in_list(&list, (void *)q_fill_cmd(&token_list));
		if (error)
		{
			q_free_cmd(&list);
			return (NULL);
		}
	}
	return (list);
}
