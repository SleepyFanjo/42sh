/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_search.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:53:05 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/04 12:25:21 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int							l_search_file(char type, char *s)
{
	char					*s_cmp;

	if (type != Q_LINK && type != Q_ARG && type != Q_FILE && type != Q_EXE)
		return (0);
ft_putendl("on cherche un fichier");
/*	if (type == Q_LINK)
		{
		
		}*/
	s_cmp = ft_get_string(&s);
	if (!ft_auto_dir(s, s_cmp))
		ft_putendl("no result\n");
	return (1);
}


int							l_search_dir(char type, char *s)
{
	(void)s;
	(void)type;
	return (0);
}


int							l_search_cmd(char type, char *s)
{
	(void)s;
	if (type != Q_CMD && type != Q_CTRL)
		return (0);
	ft_putendl("On cherche une commande ou builtin");
	return (1);
}
