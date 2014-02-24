/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_lexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 15:56:39 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/24 17:35:36 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void		q_error(char *s1, char *s2, int mode)
{
	ft_putstr_fd(s1, 2);
	if (s2 != NULL)
	{
		ft_putstr_fd(" ", 2);
		ft_putstr_fd(s2, 2);
	}
	ft_putstr_fd("\n", 2);
	if (mode != 0)
		_exit(mode);
}

t_list		*q_create_obj(void *elem)
{
	t_list	*obj;

	if ((obj = (t_list *)malloc(sizeof(t_list))) == NULL)
		q_error("Error : can't malloc", NULL, 1);
	list->elem = elem;
	list->next = NULL;
	return (obj);
}

void		q_add_in_list(t_list **list, void *elem)
{
	t_list	*cursor;
	t_list	*obj;

	obj = q_create_obj(elem);
	if (*list == NULL)
	{
		*list = obj;
		return ;
	}
	cursor = *list;
	while (cursor->next != NULL)
		cursor = cursor->next;
	cursor->next = obj;
}

t_list		*q_lexer(char *str)
{
	t_list	*list;
	int		i;

	i = 0;
	list = NULL;
	while (str[i] != '\0')
	{
		q_add_in_list(&list, (void *)create_token(str, &i));
		i = i + 1;
	}
	free(str);
	return (q_rolex(list));
}
