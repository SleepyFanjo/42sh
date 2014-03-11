/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 12:05:49 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/11 15:18:01 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch_cmd.h"

char		**table_cpy(char **table)
{
	int		i;
	char	**copy;

	i = 0;
	while (table[i] != NULL)
		i = i + 1;
	if ((copy = (char **)malloc((i + 1) * sizeof(char *))) == NULL)
		q_error("Error: Can't malloc", NULL, 1);
	i = 0;
	while (table[i] != NULL)
	{
		copy[i] = ft_strdup(table[i]);
		i = i + 1;
	}
	copy[i] = NULL;
	return (copy);
}
