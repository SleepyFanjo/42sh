/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:52:03 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/14 16:03:40 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch_cmd.h"
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

int		ft_exit(t_cmd *cmd, int fd)
{
	if ((cmd->arg)[1] == NULL)
	{
		ft_putendl_fd("Bye, nice to meet you", fd);
		exit(0);
	}
	else if (is_number((cmd->arg)[1]))
	{
		ft_putendl_fd("Bye, nice to meet you :)", fd);
		exit(ft_atoi((cmd->arg)[1]));
	}
	else
		ft_putendl_fd("Badly formed number bi*** !", 1);
	return (1);
}
