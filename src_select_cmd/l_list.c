/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:53:21 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/13 13:56:47 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
void						l_del_list(t_list **list)
{
	t_list					*tmp;

	if (*list == NULL)
		return ;
	while(tmp != NULL)
	{
		free(tmp->elem);
		tmp = tmp->next;
		free(*list);
		*list = tmp;
	}
}


# include <fcntl.h>
void						l_print_list(t_list *list)
{
int	fd;
fd = open("list", O_WRONLY | O_TRUNC | O_CREAT, 0644);


	while (list != NULL)
	{
ft_putstr_fd("[", fd);
ft_putstr_fd((char *)list->elem, fd);
ft_putstr_fd("]", fd);

		list = list->next;
	}
	ft_putendl_fd("", fd);
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
