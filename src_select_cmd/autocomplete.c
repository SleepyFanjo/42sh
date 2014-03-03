/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:49:39 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/03 18:59:59 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int						ft_auto_dir(char *s, char *s_cmp)
{
	DIR					*dir;
	struct dirent		*ent;
	int					len;

	if (!s)
		s = ".";
	if ((dir = opendir(s)) == NULL)
	{
		return (0);
	}
	len = strlen(s_cmp);
	while ((ent = readdir(dir)) != NULL)
	{
		if ((strncmp(s_cmp, ent->d_name, len)) == 0)
			ft_printf("%s%s ", dir, ent->d_name);
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
			ft_bzero(&dir[i], len - i);
			return (s);
		}
	}
	s = ft_strdup(dir);
	*s1 = NULL;
	return (s);
}

char					*l_get_token(t_list *list, char *type)
{
	t_token				*token;

	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	token = list->elem;
	*type = token->type;
	return (token->name);
}

int						ft_autocomplete(char *param)
{
	char				*s_cmp;
	char				*s;
	t_list				*list;
	char				type;

	if (!param)
		return (0);
	list = NULL;
	type = -1;
	list = q_lexer(param);
	if(!(s = l_get_token(list, &type)))
			return (0);
	if (type == Q_LINK)
	{
		if (!ft_auto_dir(NULL, s_cmp))
		{
			ft_putendl("no result\n");
			return (0);
		}
	}
	else if(type == Q_ARG || type == Q_FILE)
	{
		s_cmp = ft_get_string(&s);
		if (!ft_auto_dir(s, s_cmp))
		{
			ft_putendl("no result\n");
			return (0);
		}
	}
	else
		ft_putendl("Commande ou Control pute negre");
	return (1);
}
