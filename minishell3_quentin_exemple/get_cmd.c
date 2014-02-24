/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 12:19:52 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/28 15:42:20 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "struct.h"
#include <libft.h>

static int	len_table(char **table)
{
	int		i;

	i = 0;
	while (table[i] != NULL)
		i = i + 1;
	return (i + 2);
}

static char	**add_in_table(char **table, char *str)
{
	char	**copy;
	int		i;

	if ((copy = (char **)malloc(sizeof(char *) * len_table(table))) == NULL)
		ft_error("Error: Can't malloc", NULL, 1);
	i = 0;
	while (table[i] != NULL)
	{
		copy[i] = ft_strdup(table[i]);
		i = i + 1;
	}
	copy[i] = ft_strdup(str);
	copy[i + 1] = NULL;
	free_table(&table);
	return (copy);
}

void		get_cmd(t_cmd *elem, char *cmd, int *i)
{
	char	*str;

	str = get_str(cmd, i);
	if (elem->cmd == NULL)
		elem->cmd = ft_strdup(str);
	if (elem->arg == NULL)
	{
		if ((elem->arg = (char **)malloc(sizeof(char *) * 2)) == NULL)
			ft_error("Error: Can't malloc", NULL, 1);
		(elem->arg)[0] = ft_strdup(str);
		(elem->arg)[1] = NULL;
		free(str);
		return ;
	}
	elem->arg = add_in_table(elem->arg, str);
	free(str);
}
