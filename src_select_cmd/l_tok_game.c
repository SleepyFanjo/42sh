/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_tok_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:34:13 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/11 18:35:32 by lredoban         ###   ########.fr       */
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

/*static void				l_tab_loop(t_list *begin)
{
	t_list				*tmp;
	char				buf[5];

	tmp = begin;
	ft_bzero(buf, 5);
	while (BUF == TAB)
	{
		ft_putstr(tmp->elem);
		ft_bzero(buf, 5);
		if (read(0, buf, 4) == -1)
			break ;  // exit?
		if (BUF == TAB)
		{
			if (tmp->next != NULL)
				tmp = tmp->next;
			else
				tmp = begin;
		}
	}
	if (BUF != RETURN)
		char_insert(par, buf);
	char_insert(par, " ");
}*/

void					del_word(char *s)
{
	int					len;
int	fd;
fd = open("toto", O_WRONLY | O_TRUNC | O_CREAT);

ft_putendl_fd("on est al\n", fd);

	len = ft_strlen(s);
	while (len >= 0)
	{
		char_del(par, "\x7b\x0\x0\x0\0");
		len--;
	}
}

void					insert_word(char *s)
{
	int					i;
	int					len;
	char				*buf;

	i = 0;
	len = ft_strlen(s);
	buf = (char *)malloc(sizeof(char));
//ft_printf("%s len=%d\n", s, len);
	while (i < len)
	{
	//	buf = ft_strdup("");
		buf[0] = s[i];
		char_insert(par, buf);
		i += 1;
	}
	free(buf);
}

void					l_check_token(char type, char *s)
{
	int					i;
	t_list				*begin;

	i = 0;
	begin = NULL;
	while (tok_tab[i] != NULL)
	{
		if (tok_tab[i](type, s, &begin))
			break ;
		i += 1;
	}
//	l_tab_loop(begin);
//	ft_printf("%s%s", par->str, begin->elem);
	insert_word(begin->elem);
}
