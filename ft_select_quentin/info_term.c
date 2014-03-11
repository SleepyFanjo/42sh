/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 11:41:16 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/11 15:34:31 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <sys/ioctl.h>

struct winsize		get_term_size(void)
{
	struct winsize		size;

	ioctl(0, TIOCGWINSZ, &size);
	return (size);
}
