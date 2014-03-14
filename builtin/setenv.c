/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:21:06 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/14 16:01:49 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch_cmd.h"

int		my_setenv(t_cmd *cmd, int *fd_b)
{
	return (add_in_env(cmd, &g_env, fd_b));
}
