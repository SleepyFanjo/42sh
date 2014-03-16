/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:53:21 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/16 11:17:04 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
void						l_del_list(t_list **list)
{
	t_list					*tmp;

	if (*list == NULL)
		return ;
	while (tmp != NULL)
	{
		free(tmp->elem);
		tmp = tmp->next;
		free(*list);
		*list = tmp;
	}
}

// a supprimer a la fin
//
# include <fcntl.h>
void						l_print_list(t_list *list)
{
	t_token *t;

int fd = open("list", O_WRONLY | O_CREAT | O_APPEND, 0644);
	while (list != NULL)
	{
		ft_putstr_fd("[", fd);
		t = list->elem;
		ft_putstr_fd(t->name, fd);
		ft_putstr_fd("]", fd);
		ft_putstr_fd("[", fd);
		ft_putnbr_fd((int)(t->type), fd);
		ft_putendl_fd("]", fd);
		list = list->next;
	}
}

t_list						*l_add_to_list(t_list *list, char *data)
{
	t_list					*new;
	t_list					*tmp;

	new = (t_list *)malloc(sizeof(t_list));
	new->next = NULL;
	new->elem = ft_strdup(data);
	if (!list)
		return (new);
	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}
