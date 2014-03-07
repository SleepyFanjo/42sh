/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:53:21 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/07 19:50:41 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser_mofo/parser.h" //creer un list.h et utiliser des fction lists dans la libft

void						l_print_list(t_list *list)
{
	while (list != NULL)
	{
//ft_putstr("on compare deux pointeur");
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
//ft_printf("{%s}", new->elem);
	if (!list)
		return (new);
//ft_putendl("@");
	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}
