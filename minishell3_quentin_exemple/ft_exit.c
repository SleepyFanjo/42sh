/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:52:03 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/01 14:05:47 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <libft.h>

static int	is_number(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i = i + 1;
	}
	return (1);
}

void		ft_exit(t_cmd *cmd)
{
	if ((cmd->arg)[1] == NULL)
	{
		ft_putendl("Bye, nice to meet you");
		exit(0);
	}
	else if (is_number((cmd->arg)[1]))
	{
		ft_putendl("Bye, nice to meet you :)");
		exit(ft_atoi((cmd->arg)[1]));
	}
	else
	{
		ft_putendl("Badly formed number bi*** !");
	}
}
