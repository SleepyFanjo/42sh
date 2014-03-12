/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:49:39 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/12 19:32:00 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int						ft_auto_dir(char *s, char *s_cmp, t_check check_it, t_list **begin)
{
	DIR					*dir;
	struct dirent		*ent;
	int					len;

	if (!s)
		s = ".";
	if ((dir = opendir(s)) == NULL)
		return (0);
	len = strlen(s_cmp);
	while ((ent = readdir(dir)) != NULL)
	{
		if (((strncmp(s_cmp, ent->d_name, len)) == 0)
				&& check_it(s, ent, s_cmp))
			*begin = l_add_to_list(*begin, ent->d_name);
	}
	ft_putchar('\n');
	closedir(dir);
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

t_param					*l_save_param(t_param *param)
{
	static t_param		*p;

	if (!param)
		return (p);
	if (p == NULL)
		p = (t_param *)malloc(sizeof(t_param));
	p->i = I;
	p->len = LEN;
	p->p_line = P_LINE;
	p->str = STR;
	p->prompt = P;
	return (p);
}

void					l_copy_par(t_param *param, t_param *cpy)
{
	I = cpy->i;
	LEN = cpy->len;
	P_LINE = cpy->p_line;
	STR = cpy->str;
	P = cpy->prompt;
}

int						ft_autocomplete(t_param *param)
{
	char				*s;
	t_list				*list;
	char				type;

	l_save_param(param);
	type = -1;
	if (!param->str)
		return (0);
	if (ft_strcmp(param->str, ""))
	{
		list = NULL;
		list = q_lexer(param->str);
		if(!(s = l_get_token(list, &type)))
			return (0);
	}
	else
		s = ft_strdup("");
	l_check_token(type, s);
	q_free_list(&list);
	l_copy_par(param, l_save_param(NULL));
	return (1);
}
