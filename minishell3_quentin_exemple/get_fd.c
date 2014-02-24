/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 11:03:23 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/23 17:56:41 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "minishell.h"
#include <libft.h>

static int	len_str(char *cmd, int i)
{
	int		k;

	k = 0;
	while (cmd[i] != ' ' && cmd[i] != '\0' && cmd[i] != '\t' && cmd[i] != '<'
			&& cmd[i] != '>' && cmd[i] != '|')
	{
		if (cmd[i] == '\\' && cmd[i + 1] != '\0')
			i = i + 1;
		k = k + 1;
		i = i + 1;
	}
	return (k);
}

char		*get_str(char *cmd, int *i)
{
	int		k;
	char	*str;

	if (cmd[*i] == '\"' || cmd[*i] == '\'')
		return (get_double_quote(cmd, i));
	k = len_str(cmd, *i);
	if ((str = (char *)malloc((k + 1) * sizeof(char))) == NULL)
		ft_error("Error: Can't malloc", NULL, 1);
	k = 0;
	while (cmd[*i] != ' ' && cmd[*i] != '\t' && cmd[*i] != '\0'
			&& cmd[*i] != '<' && cmd[*i] != '>' && cmd[*i] != '|')
	{
		if (cmd[*i] == '\\' && cmd[*i + 1] != '\0')
			*i = *i + 1;
		str[k] = cmd[*i];
		*i = *i + 1;
		k = k + 1;
	}
	str[k] = '\0';
	return (str);
}

t_cmd		*init_elem(void)
{
	t_cmd	*elem;

	if ((elem = (t_cmd *)malloc(sizeof(t_cmd))) == NULL)
		ft_error("Error: Can't malloc", NULL, 1);
	elem->cmd = NULL;
	elem->arg = NULL;
	elem->fd_in = NULL;
	elem->pipe = -1;
	elem->end = NULL;
	elem->fd_out = NULL;
	elem->fd_mode = -1;
	return (elem);
}

void		get_fd_in(t_cmd *elem, char *cmd, int *i)
{
	char	*str;
	int		std;

	*i = *i + 1;
	std = 0;
	if (cmd[*i] == '<' && cmd[*i + 1] != '\0')
	{
		*i = *i + 1;
		std = 1;
	}
	while ((cmd[*i] == ' ' || cmd[*i] == '\t') && cmd[*i] != '\0')
		*i = *i + 1;
	str = get_str(cmd, i);
	if (std == 1)
	{
		elem->fd_in = str;
		elem->end = str;
		return ;
	}
	elem->fd_in = str;
}

void		get_fd_out(t_cmd *elem, char *cmd, int *i)
{
	char	*str;
	int		std;

	*i = *i + 1;
	std = 0;
	if (cmd[*i] == '>' && cmd[*i + 1] != '\0')
	{
		*i = *i + 1;
		std = 1;
	}
	while ((cmd[*i] == ' ' || cmd[*i] == '\t') && cmd[*i] != '\0')
		*i = *i + 1;
	str = get_str(cmd, i);
	if (std == 1)
	{
		elem->fd_out = str;
		elem->fd_mode = 1;
		*i = *i + 1;
		return ;
	}
	elem->fd_out = str;
	elem->fd_mode = 0;
}
