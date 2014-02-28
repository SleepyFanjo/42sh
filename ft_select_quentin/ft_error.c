/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 17:54:51 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/08 15:39:45 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <libft.h>
#include <stdlib.h>

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

void	ft_puterror(char *str)
{
	ft_putendl(str);
}
