/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 16:12:40 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/11 14:16:16 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch_cmd.h"

void	print_env(char **envp, int fd)
{
	int		i;

	i = 0;
	while (envp != NULL && envp[i] != NULL)
	{
		ft_putendl_fd(envp[i], fd);
		i = i + 1;
	}
}
