/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 12:16:19 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/27 11:26:09 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launch_cmd.h"

static char	*ft_strjoinpath(char const *s1, char const *s2)
{
	char		*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, "/");
	ft_strcat(str, s2);
	return (str);
}

static void	v_free_tab(char **table)
{
	int		i;

	i = 0;
	while (table[i] != NULL)
	{
		free(table[i]);
		i++;
	}
	free(table);
}

static char	*type_cmd(char *str)
{
	char	*tmp2;

	tmp2 = ft_strtrim(str);
	if (*tmp2 == '/')
	{
		if (access(tmp2, X_OK) == 0)
			return (tmp2);
	}
	if (ft_strncmp("./", tmp2, 2) == 0)
	{
		if (access(tmp2 + 2, X_OK) == 0)
			return (tmp2 + 2);
	}
	free(tmp2);
	return (NULL);
}

static char	*path_join(char **path, char *str)
{
	char		*tmp;
	int			i;

	i = 0;
	while (path[i] != NULL)
	{
		if ((tmp = ft_strjoinpath(path[i++], str)) == NULL)
		{
			v_free_tab(path);
			return (NULL);
		}
		if (access(tmp, X_OK) == 0)
		{
			v_free_tab(path);
			return (tmp);
		}
		free(tmp);
	}
	v_free_tab(path);
	return (NULL);
}

char		*get_path(char *str, char **envp)
{
	int			i;
	char		*tmp;
	char		**path;

	i = 0;
	if (!envp)
		return (NULL);
	if ((tmp = type_cmd(str)) != NULL)
		return (tmp);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (envp[i] == NULL)
		return (NULL);
	path = ft_strsplit(envp[i] + 5, ':');
	return (path_join(path, str));
}
