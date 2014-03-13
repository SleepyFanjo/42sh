/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_malloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 17:59:55 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/13 14:10:34 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/select_cmd.h"

void				*j_malloc(size_t byte)
{
	void			*ret;

	if ((ret = malloc(byte)) == NULL)
	{
		if ((ret = malloc(byte)) == NULL)
		{
			ft_putendl("Error : can't malloc");
			exit(1);
		}
	}
	return (ret);
}
