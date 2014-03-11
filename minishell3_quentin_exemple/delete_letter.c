/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_letter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 17:51:39 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/29 18:14:52 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <libft.h>

static void	cp_without(char *dest, char *src, int index)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		if (i == index)
			i = i + 1;
		dest[j] = src[i];
		j = j + 1;
		i = i + 1;
	}
	dest[j] = '\0';
}

void		delete_letter(t_key c, char **input, t_pos *pos)
{
	int		pos_c;
	int		len;
	char	*str;

	len = ft_strlen(*input);
	if (!ft_strcmp(*input, ""))
		return ;
	if (c == DEL_L_K && pos->cursor < len)
		pos_c = pos->cursor + 1;
	else
	{
		pos_c = pos->cursor;
		if (pos->cursor > 0)
			pos->cursor = pos->cursor - 1;
	}
	if ((str = (char *)malloc(len * sizeof(char))) == NULL)
		ft_error("Error can't malloc", NULL, 1);
	cp_without(str, *input, len - pos_c);
	clear_line(len);
	free(*input);
	*input = str;
}
