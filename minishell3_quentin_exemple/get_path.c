/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 14:33:00 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/15 18:36:43 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "minishell.h"

static char		*find_path(char **envp)
{
	int		i;
	int		j;
	char	c;
	char	*str;

	i = 0;
	while (envp != NULL && envp[i] != NULL)
	{
		j = 0;
		while (envp[i][j] != '=' && envp[i][j] != '\0')
			j = j + 1;
		c = envp[i][j];
		envp[i][j] = '\0';
		if (ft_strcmp("PATH", envp[i]) == 0)
		{
			if ((str = ft_strdup(envp[i] + j + 1)) == NULL)
				ft_error("Error: Malloc fail", NULL, 1);
			envp[i][j] = '=';
			return (str);
		}
		envp[i][j] = c;
		i = i + 1;
	}
	return (NULL);
}

char			**get_path(char **envp)
{
	char	*path_raw;
	char	**path_clean;

	path_raw = find_path(envp);
	if (path_raw == NULL)
		return (NULL);
	path_clean = ft_strsplit(path_raw, ':');
	free(path_raw);
	return (path_clean);
}
