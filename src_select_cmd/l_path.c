/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_path.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 14:55:25 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/12 11:17:31 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

static void			ft_clear(char **str)
{
	int			i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i += 1;
	}
	free(str);
}

static void			ft_check_builtin(char *s, t_list **begin)
{
	static char		*builtin[7] =
	{
		"cd", "echo", "env", "exit", "setenv", "unsetenv",
		NULL
	};
	int				i;

	i = 0;
	while (builtin[i] != NULL)
	{
		if (!ft_strncmp(builtin[i], s, ft_strlen(s)))
			*begin = l_add_to_list(*begin, builtin[i]);
		i += 1;
	}
}

static void			ft_process(char **tmp, char *s, int i, t_list **begin)
{
	DIR         	*dir;
	struct dirent   *ent;

	while (tmp[i] != NULL)
	{
		if ((dir = opendir(tmp[i])) == NULL)
		{
			i += 1;
			continue ;
		}
		while ((ent = readdir(dir)) != NULL)
		{
			if (!ft_strncmp(s, ent->d_name, ft_strlen(s)))
			{
				if (l_is_exe(tmp[i], ent, NULL))
				{
					*begin = l_add_to_list(*begin, ent->d_name);
				}
			}
		}
		closedir(dir);
		i += 1;
	}
}

int					ft_checkpath(char *s, t_list **begin)
{
	char			*path;
	char			**tmp;
	int				i;

	i = 0;
	ft_check_builtin(s, begin);
	if ((ft_strncmp(lova_envp, "PATH=", 5)) != 0)
		return (0);
	path = ft_strdup(&lova_envp[4]);
	tmp = ft_strsplit(path, ':');
	ft_process(tmp, s, i, begin);
	ft_clear(tmp);
	free(path);
	return (0);
}
