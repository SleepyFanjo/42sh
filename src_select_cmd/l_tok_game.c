/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_tok_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:34:13 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/13 17:36:38 by lredoban         ###   ########.fr       */
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

static void				l_tab_loop(t_list *begin, t_param *param)
{
	t_list				*tmp;
	char				buf[5];

	tmp = begin;
l_print_list(begin);
	ft_bzero(buf, 5);
	insert_word(begin->elem, param);
	while ((begin->next != NULL) && (BUF == TAB || *buf == '\0'))
	{
int	fd;
fd = open("toto", O_WRONLY | O_TRUNC | O_CREAT, 0644);
ft_putstr_fd("into the while =[", fd);
ft_putstr_fd(tmp->elem, fd);
ft_putstr_fd("]\n", fd);



		ft_bzero(buf, 5);
		if (read(0, buf, 4) == -1)
			exit(27) ;
		if (BUF == TAB)
		{
			del_word(tmp->elem, param);
			if (tmp->next != NULL)
				tmp = tmp->next;
			else
				tmp = begin;
			insert_word(tmp->elem, param);
		}
	}
	if (BUF != RETURN)
		char_insert(param, buf);
	else
		char_insert(param, "\x20\0\0\0\0");
}

void					del_word(char *s, t_param *param)
{
	int					len;

	len = ft_strlen(s);
	while (len > 0)
	{
		char_del(param, "\x7f\x0\x0\x0\0");
		len--;
	}
}

void					insert_word(char *s, t_param *param)
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
		char_insert(param, buf);
		i += 1;
	}
	free(buf);
}

void					l_check_token(char type, char *s, t_param *param)
{
	int					i;
	t_list				*begin;
	int					ret;

	i = 0;
	begin = NULL;
	while (tok_tab[i] != NULL)
	{
		if ((ret = tok_tab[i](type, s, &begin, param)))
			break ;
		i += 1;
	}
	if (ret)
		l_tab_loop(begin, param);
	else
		char_insert(param, "\x9\0\0\0\0");
	l_del_list(&begin);
}
