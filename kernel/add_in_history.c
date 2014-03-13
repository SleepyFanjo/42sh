/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_in_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 16:59:41 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/13 17:04:01 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history.h>

void		add_in_history(t_history **history, char *str)
{
	t_history	*cursor;
	if (str == NULL)
		return ;
	if (*history == NULL)
	{
		*history = new_elem(str);
		return ;
	}
	cursor = (*history);
	*history = new_elem(str);
	(*history)->next = cursor;
}
