/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 17:16:45 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/23 14:42:37 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <libft.h>

static int	len_double_quote(char *cmd, int i)
{
	int		k;

	k = 0;
	while (cmd[i] != '\"' && cmd[i] != '\'' && cmd[i] != '\0')
	{
		if (cmd[i] == '\\' && cmd[i + 1] != '\0')
			i = i + 1;
		k = k + 1;
		i = i + 1;
	}
	return (k);
}

char		*get_double_quote(char *cmd, int *i)
{
	int		k;
	char	*str;

	*i = *i + 1;
	k = len_double_quote(cmd, *i);
	if ((str = (char *)malloc(sizeof(char) * (k + 1))) == NULL)
		ft_error("Error: Can't malloc", NULL, 1);
	k = 0;
	while (cmd[*i] != '\"' && cmd[*i] != '\'' && cmd[*i] != '\0')
	{
		if (cmd[*i] == '\\' && cmd[*i + 1] != '\0')
			*i = *i + 1;
		str[k] = cmd[*i];
		*i = *i + 1;
		k = k + 1;
	}
	if (cmd[*i] != '\0')
		*i = *i + 1;
	str[k] = '\0';
	return (str);
}
