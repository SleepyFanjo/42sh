/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_search.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:53:05 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/07 19:24:30 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int							l_search_file(char type, char *s, t_list *begin)
{
	char					*s_cmp;

	if (type != Q_ARG && type != Q_FILE)
		return (0);
	ft_putendl("Looking for files or a directories:");
	s_cmp = ft_get_string(&s);
	if (!ft_auto_dir(s, s_cmp, to_check[2], begin))
		ft_printf("couldn't find [%s] as a directory\n", s);
	free(s_cmp);
	return (1);
}

int							l_search_exe(char type, char *s, t_list *begin)
{
	char					*s_cmp;

	if(type != Q_EXE)
		return (0);
	ft_putendl("Looking for directories or executable files:");
	s_cmp = ft_get_string(&s);
	if (!ft_auto_dir(s, s_cmp, to_check[0], begin))
		ft_printf("couldn't find [%s] as a directory\n", s);
	free(s_cmp);
	return (1);
}

int							l_search_link(char type, char *s, t_list *begin)
{
	(void)s;
	if (type != Q_LINK)
		return (0);
	ft_putendl("Link:");
	ft_auto_dir(NULL, "\0", to_check[2], begin);
	return (1);
}

int							l_search_dir(char type, char *s, t_list *begin)
{
	//ft_putendl("Looking for directories:");
	(void)s;
	(void)type;
	(void)begin;
	return (0);
}

int							l_search_cmd(char type, char *s, t_list *begin)
{
	if (type != Q_CMD && type != Q_CTRL)
		return (0);
	ft_putendl("Looking for commands:");
	ft_checkpath(s, begin);
	ft_putchar('\n');
	return (1);
}
