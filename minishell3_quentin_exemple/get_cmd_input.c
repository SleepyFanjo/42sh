/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 16:03:48 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/28 19:07:02 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <libft.h>

static int	check_right(char *str)
{
	if (access(str, X_OK) == -1)
		return (0);
	return (1);
}

static int	is_slash(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '/')
			return (1);
		i = i + 1;
	}
	return (0);
}

static char	*make_path(char *path, char *cmd)
{
	char	*str;

	if (check_right(cmd) && is_slash(cmd))
		return (cmd);
	if ((str = ft_strdup(path)) == NULL)
		ft_error("Error : Can't malloc", NULL, 1);
	if (ft_str_realloc_cat(&str, "/") == NULL)
		ft_error("Error : Can't malloc", NULL, 1);
	if (ft_str_realloc_cat(&str, cmd) == NULL)
		ft_error("Error : Can't malloc", NULL, 1);
	return (str);
}

char		*get_cmd_input(char **path_list, char *cmd)
{
	int		i;
	char	*str;

	i = 0;
	while (path_list != NULL && path_list[i] != NULL)
	{
		str = make_path(path_list[i], cmd);
		if (check_right(str))
			return (str);
		i = i + 1;
	}
	ft_error("Error: Command not found ", cmd, 1);
	return (NULL);
}
