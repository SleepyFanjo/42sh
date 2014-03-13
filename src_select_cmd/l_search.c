/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_search.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:53:05 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/13 14:54:03 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int			l_search_file(char type, char *s, t_list **begin, t_param *param)
{
	char	*s_cmp;

	if (type != Q_ARG && type != Q_FILE)
		return (0);
	s_cmp = ft_get_string(&s);
	if (!ft_auto_dir(s, s_cmp, to_check[2], begin, param))
		ft_printf("couldn't find [%s] as a directory\n", s);
	free(s_cmp);
	return (1);
}

int			l_search_exe(char type, char *s, t_list **begin, t_param *param)
{
	char	*s_cmp;

	if(type != Q_EXE)
		return (0);
	s_cmp = ft_get_string(&s);
	if (!ft_auto_dir(s, s_cmp, to_check[0], begin, param))
		ft_printf("couldn't find [%s] as a directory\n", s);
	free(s_cmp);
	return (1);
}

int			l_search_link(char type, char *s, t_list **begin, t_param *param)
{
	(void)s;
	if (type != Q_LINK)
		return (0);
	ft_putendl("Link:");
	ft_auto_dir(NULL, "\0", to_check[2], begin, param);
	return (1);
}

int			l_search_cmd(char type, char *s, t_list **begin, t_param *param)
{
	if (type != Q_CMD && type != Q_CTRL)
		return (0);
	(void)type;
	ft_checkpath(s, begin, param);
	return (1);
}
