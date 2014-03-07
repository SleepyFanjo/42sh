/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:02:59 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/07 17:36:55 by qchevrin         ###   ########.fr       */
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

void		q_free_token(t_list *token)
{
	t_token		*elem;

	elem = token->elem;
	free(elem->name);
	free(elem);
	free(token);
}

int			q_is_blank(void *elem)
{
	t_token		*token;

	token = (t_token *)elem;
	if (token->type == Q_SPACE)
		return (1);
	return (0);
}

void		q_delete_whitespace(t_list **list)
{
	t_list	*cursor;
	t_list	*next;

	cursor = *list;
	while (cursor != NULL && q_is_blank(cursor->elem))
	{
		next = cursor->next;
		q_free_token(cursor);
		cursor = next;
	}
	*list = cursor;
	next = cursor;
	while (cursor->next != NULL)
	{
		next = cursor->next;
		if (q_is_blank(next->elem))
		{
			cursor->next = next->next;
			q_free_token(next);
		}
		else
			cursor = cursor->next;
	}
}

t_list		*q_parser(t_list *token_list)
{
	t_list	*list;
	int		error;

	list = NULL;
	q_delete_whitespace(&token_list);
	ft_putendl("whitespace are delete");
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
