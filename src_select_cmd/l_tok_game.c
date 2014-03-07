/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_tok_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:34:13 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/07 19:52:23 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

static char				l_find_tok(t_list *prev)
{
	t_token				*tok;

	tok = prev->elem;
	if (tok->type == Q_CMD)
		tok->type = Q_ARG;
	if (tok->type == Q_EXE)
		tok->type = Q_ARG;
	return (tok->type);
}

char					*l_get_token(t_list *list, char *type)
{
	t_token				*token;
	t_list				*prev;
	char				*ret;


	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
	{
		prev = list;
		list = list->next;
	}
	token = list->elem;
	if (token->type == Q_SPACE)
	{
		*type = l_find_tok(prev);
		ret = "";
	}
	else
	{
		ret = token->name;
		*type = token->type;
	}
	return (ret);
}

void					l_check_token(char type, char *s)
{
	int					i;
	t_list				*begin;

	i = 0;
	begin = NULL;
	while (tok_tab[i] != NULL)
	{
		if (tok_tab[i](type, s, begin))
			break ;
		i += 1;
	}
ft_putendl("on va print la liste finale");
	l_print_list(begin);
}
