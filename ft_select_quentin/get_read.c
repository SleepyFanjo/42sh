/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 15:37:56 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/09 16:37:38 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <unistd.h>
#include <stdlib.h>
#include <libft.h>

static void	clean_read(char *buff)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		buff[i] = 0;
		i = i + 1;
	}
}

void		get_read(char *read_buff, t_param param)
{
	int		res;

	clean_read(read_buff);
	while (*(unsigned int *)read_buff != 10)
	{
		clean_read(read_buff);
		while (read_buff[0] == 0)
			read(0, read_buff, 4);
		res = *(unsigned int *)read_buff;
		if (res == 127 || res == 2117294875)
		{
			delete_elem_list(&(param.list));
			if (param.list != NULL)
				(param.list)->mode = (param.list)->mode + 1;
		}
		if (param.list == NULL || res == 27)
			exit_clean(param, 1);
		modify_list(&(param.list), read_buff);
		print_list(get_term_size(), get_begin_list(param.list));
	}
}
