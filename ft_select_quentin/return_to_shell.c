/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_shell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 14:15:16 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/09 15:02:28 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <libft.h>
#include <fcntl.h>
#include <unistd.h>

void		return_to_shell(t_list *list)
{
	if (list == NULL)
		return ;
	ft_putstr_fd(list->str, 1);
	list = list->next;
	while (list->is_begin != 1)
	{
		ft_putchar_fd(' ', 1);
		ft_putstr_fd(list->str, 1);
		list = list->next;
	}
}
