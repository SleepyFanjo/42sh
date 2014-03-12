/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:53:21 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/12 13:38:39 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser_mofo/parser.h" //creer un list.h et utiliser des fction lists dans la libft

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

void						l_print_list(t_list *list)
{
	while (list != NULL)
	{
		ft_printf("[%s]", (char *)list->elem);
		list = list->next;
	}
	ft_putendl("");
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
