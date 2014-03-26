/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_search.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:53:05 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/26 11:49:16 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int			l_search_file(char type, char *s, t_list **begin, t_param *param)
{
	t_dummy	*sd;

	sd = (t_dummy *)malloc(sizeof(t_dummy));
	sd->s = s;
	if (type != Q_ARG && type != Q_FILE)
		return (0);
	sd->s_cmp = ft_get_string(&(sd->s));
	if (!ft_auto_dir(sd, to_check[2], begin, param))
		ft_printf("couldn't find [%s] as a directory\n", sd->s);
	free(sd->s_cmp);
	free(sd);
	return (1);
}

int			l_search_exe(char type, char *s, t_list **begin, t_param *param)
{
	t_dummy	*sd;

	sd = (t_dummy *)j_malloc(sizeof(t_dummy));
	sd->s = s;
	if (type != Q_EXE)
		return (0);
	sd->s_cmp = ft_get_string(&s);
	if (!ft_auto_dir(sd, to_check[0], begin, param))
		ft_printf("couldn't find [%s] as a directory\n", sd->s);
	free(sd->s_cmp);
	free(sd);
	return (1);
}

int			l_search_link(char type, char *s, t_list **begin, t_param *param)
{
	t_dummy	*sd;

	(void)s;
	sd = (t_dummy *)j_malloc(sizeof(t_dummy));
	sd->s = NULL;
	sd->s_cmp = "\0";
	if (type != Q_LINK)
		return (0);
	ft_auto_dir(sd, to_check[2], begin, param);
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

int			tab_key(t_param *param, char *buf)
{
	if (BUF != TAB)
		return (0);
	ft_autocomplete(param);
	return (1);
}
