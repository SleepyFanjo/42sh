/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 11:29:31 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/08 11:41:08 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <libft.h>

int			get_size_list(t_list *list)
{
	int			i;

	if (list == NULL)
		return (0);
	i = 1;
	while (list->next->is_begin != 1)
	{
		i = i + 1;
		list = list->next;
	}
	return (i);
}

int			size_max_list(t_list *list)
{
	int			i;

	if (list == NULL)
		return (0);
	i = ft_strlen(list->str);
	while (list->next->is_begin != 1)
	{
		if (ft_strlen(list->str) > i)
			i = ft_strlen(list->str);
		list = list->next;
	}
	return (i);
}
