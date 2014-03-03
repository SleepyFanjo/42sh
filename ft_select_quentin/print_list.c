/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 11:27:28 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/11 15:25:15 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <sys/ioctl.h>
#include <libft.h>

static void		fill_space(int len, int space)
{
	while (len < space)
	{
		ft_putchar_fd(' ', 2);
		space = space - 1;
	}
	ft_putchar_fd(' ', 2);
}

static t_list	*jump_list(t_list *list, int jump)
{
	jump = jump - 1;
	list = list->next;
	while (jump > 0)
	{
		if (list->is_begin == 1)
			return (NULL);
		list = list->next;
		jump = jump - 1;
	}
	if (list->is_begin == 1)
		return (NULL);
	return (list);
}

static void		final_print(t_list *list, int col, int size, int row)
{
	int		i;
	int		j;
	t_list	*tmp;

	j = 0;
	while (j < row)
	{
		print_correct(list);
		fill_space(ft_strlen(list->str), size);
		i = 1;
		while (i < col)
		{
			if ((tmp = jump_list(list, row * i)) != NULL)
			{
				print_correct(tmp);
				fill_space(ft_strlen(tmp->str), size);
			}
			i = i + 1;
		}
		j = j + 1;
		if (j < row)
			ft_putstr_fd("\n", 2);
		list = list->next;
	}
}

void			print_list(struct winsize size, t_list *list)
{
	int		size_max;
	int		size_list;
	int		number_column;

	size_max = size_max_list(list);
	size_list = get_size_list(list);
	number_column = 1;
	clear_term();
	if (size_list <= (int)size.ws_row && size_max < (int)size.ws_col)
	{
		final_print(list, number_column, size_max, size_list);
		return ;
	}
	while (size_list > (int)size.ws_row)
	{
		size_list = size_list - (int)size.ws_row;
		number_column = number_column + 1;
		if (size_max * number_column + number_column > (int)size.ws_col)
		{
			ft_puterror("Not enough space");
			return ;
		}
	}
	final_print(list, number_column, size_max, (int)size.ws_row);
}
