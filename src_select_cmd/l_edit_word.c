/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_edit_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 16:02:40 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/16 16:03:48 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select_cmd.h"

static void					lil_del_word(char *s, t_param *param, char **old)
{
	int					len;
	char				*tmp;

	exleft(I + P);
	len = ft_strlen(s);
	I -= len;
	LEN -= len;
	len = ft_strlen(*old) - len;
	tmp = ft_strnew(len + 1);
	tmp = ft_strncpy(tmp, *old, len);
	free(*old);
	*old = tmp;
}

void					del_word(char *s, t_param *param, char **old)
{
	char				*part1;
	char				*part2;

	if (I == LEN)
		lil_del_word(s, param, old);
	else
	{
		part2 = ft_strdup(&STR[I]);
		part1 = ft_strnew(I + 1);
		part1 = ft_strncpy(part1, STR, I);
		lil_del_word(s, param, &part1);
		part1 = ft_str_realloc_cat(&part1, part2);
		free(part2);
		free(*old);
		*old = part1;
	}
}

void					lil_insert_word(char *s, t_param *param, char **old)
{
	int					len;
	char				*tmp;

	len = ft_strlen(s);
	I += len;
	LEN += len;
	len = ft_strlen(*old) + len;
	tmp = ft_strnew(len + 1);
	tmp = ft_strcpy(tmp, *old);
	tmp = ft_strcat(tmp, s);
	free(*old);
	*old = tmp;
}

void					insert_word(char *s, t_param *param, char **old)
{
	char				*part1;
	char				*part2;

	if (I == LEN)
	{
		lil_insert_word(s, param, old);
		write_str(P_LINE, *old);
	}
	else
	{
		part2 = ft_strdup(&STR[I]);
		part1 = ft_strnew(I + 1);
		part1 = ft_strncpy(part1, STR, I);
		lil_insert_word(s, param, &part1);
		part1 = ft_str_realloc_cat(&part1, part2);
		free(part2);
		free(*old);
		*old = part1;
		write_str(P_LINE, *old);
		l_exleft(LEN - I);
	}
}

