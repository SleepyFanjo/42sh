/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 16:43:16 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/11 14:56:24 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch_cmd.h"

void		my_unsetenv(t_cmd *cmd)
{
	delete_in_env(cmd, &g_env);
}