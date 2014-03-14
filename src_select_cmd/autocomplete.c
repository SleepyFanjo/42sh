/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:49:39 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/14 19:33:58 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int						ft_auto_dir(char *s, char *s_cmp, t_check check_it, t_list **begin, t_param *param)
{
	DIR					*dir;
	struct dirent		*ent;
	int					len;
	char				*tmp;

	if (!s)
		s = ".";
	if ((dir = opendir(s)) == NULL)
		return (0);
	len = strlen(s_cmp);
	while ((ent = readdir(dir)) != NULL)
	{
		if (((strncmp(s_cmp, ent->d_name, len)) == 0)
				&& check_it(s, ent, s_cmp))
		{
			tmp = ft_strdup(ent->d_name);
			if (ent->d_type == DT_DIR)
				tmp = ft_str_realloc_cat(&tmp, "/");
			*begin = l_add_to_list(*begin, tmp);
		}
	}
	closedir(dir);
	if (*begin != NULL)
		del_word(s_cmp, param, &STR);
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

int						tab_key(t_param *param, char *buf)
{
	if (BUF != TAB)
		return (0);
	ft_autocomplete(param);
	return (1);
}

int						ft_autocomplete(t_param *param)
{
	char				*s;
	t_list				*list;
	char				type;
	char				*tmp;

	type = -1;

	if (!param->str || I != LEN)
		return (0);
	list = NULL;
	if (ft_strcmp(param->str, ""))
	{
		tmp = ft_strdup(param->str);
		list = q_lexer(tmp);
		if(!(s = l_get_token(list, &type)))
			return (0);
	}
	else
		s = ft_strdup("");
	l_check_token(type, s, param);
	if (list != NULL)
		q_free_list(&list);
	return (1);
}
