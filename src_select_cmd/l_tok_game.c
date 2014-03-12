/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_tok_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:34:13 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/12 19:28:35 by lredoban         ###   ########.fr       */
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

void					print_tmp(char *s, int former_len)
{
	ft_putstr(&s[former_len]);
}

static void				l_tab_loop(t_list *begin, int len)
{
	t_list				*tmp;
	char				buf[5];
	t_param				*par;

	par = l_save_param(NULL);
	tmp = begin;
	ft_bzero(buf, 5);
	while (BUF == TAB || *buf == '\0')
	{
		refresh_screen(par, 0);
		ft_putstr(par->str);
		print_tmp(tmp->elem, len);
		ft_bzero(buf, 5);
		if (read(0, buf, 4) == -1)
			exit(27) ;
		if (BUF == TAB)
		{
			if (tmp->next != NULL)
				tmp = tmp->next;
			else
				tmp = begin;
		}
	}
	insert_word(tmp->elem, len);
	if (BUF != RETURN)
		char_insert(par, buf);
	else
		char_insert(par, "\x20\0\0\0\0");
	l_save_param(par);
}

/*void					del_word(char *s)
{
	int					len;
int	fd;
fd = open("toto", O_WRONLY | O_TRUNC | O_CREAT);

ft_putstr_fd("chaine=", fd);
ft_putendl_fd(s, fd);

	len = ft_strlen(s);
	while (len > 0)
	{
ft_putstr_fd("len", fd);
ft_putnbr_fd(len, fd);
ft_putendl_fd("", fd);
		char_del(par, "\x7b\x0\x0\x0\0");
	sleep(1);
		len--;
	}
}*/

void					insert_word(char *s, int former_len)
{
	int					i;
	int					len;
	char				*buf;
	t_param				*par;

	par = l_save_param(NULL);
	i = 0;
	len = ft_strlen(s);
	buf = (char *)malloc(sizeof(char));
//ft_printf("%s len=%d\n", s, len);
	i += former_len;
	while (i < len)
	{
	//	buf = ft_strdup("");
		buf[0] = s[i];
		char_insert(par, buf);
		i += 1;
	}
	free(buf);
	l_save_param(par);
}

void					l_check_token(char type, char *s)
{
	int					i;
	t_list				*begin;
	int					ret;

	i = 0;
	begin = NULL;
	while (tok_tab[i] != NULL)
	{
		if ((ret = tok_tab[i](type, s, &begin)))
			break ;
		i += 1;
	}
	if (ret)
		l_tab_loop(begin, ft_strlen(s));
	else
		char_insert(par, "\x9\0\0\0\0");
	l_del_list(&begin);
	//	ft_printf("%s%s", par->str, begin->elem);
}
