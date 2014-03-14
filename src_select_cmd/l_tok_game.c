/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_tok_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 18:34:13 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/14 18:44:57 by lredoban         ###   ########.fr       */
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
	buf[0] = '\x9';
int	fd;
fd = open("toto", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	insert_word(begin->elem, param, &STR);
	while (begin->next != NULL && BUF == TAB)
	{
ft_putstr_fd("into the while =[", fd);
ft_putstr_fd(tmp->elem, fd);
ft_putstr_fd("]\n", fd);
			if ((read(0, buf, 5) == -1))
				exit (0);
			if (TAB == BUF)
			{
			del_word(tmp->elem, param, &STR);
			if (tmp->next != NULL)
				tmp = tmp->next;
			else
				tmp = begin;
			insert_word(tmp->elem, param, &STR);
			}
	}
	if (BUF != RETURN && begin->next != NULL)
		char_insert(param, buf);
	else
		char_insert(param, "\x20\0\0\0\0");
	refresh_screen(param, 0);

close(fd);
}

/*static void				l_tab_loop(t_list *begin, t_param *param)
{
	t_list				*tmp;
	char				buf[5];

	insert_word(begin->elem, param, &STR);
	tmp = begin;
	ft_bzero(buf, 5);
	while (BUF != RETURN)
	{
		ft_bzero(buf, 5);
		if (read(0, buf, 4) < 0)
		 	exit (0);
		del_word(tmp->elem, param, &STR);
		if (tmp->next == NULL)
			tmp = begin;
		else
			tmp = tmp->next;
		insert_word(begin->elem, param, &STR);
	}
	char_insert(param, "\x20\0\0\0\0");
}*/

void					del_word(char *s, t_param *param, char **old)
{
	int					len;
	char				*tmp;
//tant que le tab n'est gerer que a la fin;
	len = ft_strlen(s);
	I -= len;
	LEN -= len;
	len = ft_strlen(STR) - len;
	tmp = ft_strnew(len + 1);
	tmp = ft_strncpy(tmp, STR, len);
	free(*old);
	*old = tmp;
int	fd2;
fd2 = open("tata", O_WRONLY | O_TRUNC | O_CREAT, 0644);
ft_putstr_fd("param->str =[", fd2);
ft_putstr_fd(STR, fd2);
ft_putstr_fd("] ", fd2);
ft_putstr_fd("len =[", fd2);
ft_putnbr_fd(len, fd2);
ft_putstr_fd("] ", fd2);
ft_putstr_fd("LEN =[", fd2);
ft_putnbr_fd(LEN, fd2);
ft_putstr_fd("] ", fd2);
ft_putstr_fd("I =[", fd2);
ft_putnbr_fd(I, fd2);
ft_putstr_fd("]\n", fd2);


}

void					insert_word(char *s, t_param *param, char **old)
{
	int					len;
	char				*tmp;
//tant que le tab n'est gerer que a la fin;
	len = ft_strlen(s);
	I += len;
	LEN += len;
	len = ft_strlen(STR) + len;
	tmp = ft_strnew(len + 1);
	tmp = ft_strcpy(tmp, STR);
	tmp = ft_strcat(tmp, s);
	free(*old);
	*old = tmp; 
	refresh_screen(param, 0);
int	fd2;
fd2 = open("tata", O_WRONLY | O_TRUNC | O_CREAT, 0644);
ft_putstr_fd("param->str =[", fd2);
ft_putstr_fd(STR, fd2);
ft_putstr_fd("]\n", fd2);
ft_putstr_fd("len =[", fd2);
ft_putnbr_fd(len, fd2);
ft_putstr_fd("]\n", fd2);
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
	if (begin == NULL)
	{
		tputs(tgetstr("bl", NULL), 1, tputs_putchar);
		return ;
	}
	if (ret)
		l_tab_loop(begin, param);
	else
		char_insert(param, "\x9\0\0\0\0");
	l_del_list(&begin);
}
