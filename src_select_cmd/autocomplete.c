/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:49:39 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/16 16:40:53 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int					ft_auto_dir(t_dummy *s, t_check c, t_list **b, t_param *p)
{
	DIR				*dir;
	struct dirent	*ent;
	int				len;
	char			*tmp;

	if (!s->s)
		s->s = ".";
	if ((dir = opendir(s->s)) == NULL)
		return (0);
	len = strlen(s->s_cmp);
	while ((ent = readdir(dir)) != NULL)
	{
		if (((strncmp(s->s_cmp, ent->d_name, len)) == 0)
				&& c(s->s, ent, s->s_cmp))
		{
			tmp = ft_strdup(ent->d_name);
			if (ent->d_type == DT_DIR)
				tmp = ft_str_realloc_cat(&tmp, "/");
			*b = l_add_to_list(*b, tmp);
		}
	}
	closedir(dir);
	if (*b != NULL)
		del_word(s->s_cmp, p, &p->str);
	return (1);
}

char					*ft_get_string(char **s1)
{
	int					i;
	int					len;
	char				*s;
	char				*dir;

	dir = *s1;
	len = ft_strlen(dir);
	i = len;
	while (i-- > 0)
	{
		if (dir[i] == '/')
		{
			s = ft_strdup(&dir[i + 1]);
			if (i == 0)
				ft_bzero(&dir[1], len + 1);
			else
				ft_bzero(&dir[i], len - i);
			return (s);
		}
	}
	s = ft_strdup(dir);
	*s1 = NULL;
	return (s);
}

static char				*get_tmp(t_param *param)
{
	char				*ret;

	if (I == LEN)
		ret = ft_strdup(STR);
	else
	{
		ret = ft_strnew(I + 1);
		ret = ft_strncpy(ret, STR, I);
	}
	return (ret);
}

int						ft_autocomplete(t_param *param)
{
	char				*s;
	t_list				*list;
	char				type;
	char				*tmp;

	type = -1;
	list = NULL;
	if (ft_strcmp(param->str, ""))
		{
		tmp = get_tmp(param);
		list = q_lexer(tmp);
		if (!(s = l_get_token(list, &type)))
			return (0);
	}
	else
		s = "";
	l_check_token(type, s, param);
	if (list != NULL)
		q_free_list(&list);
	return (1);
}
