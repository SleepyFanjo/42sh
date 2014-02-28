/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_autoC.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:57:23 by lredoban          #+#    #+#             */
/*   Updated: 2014/02/28 17:01:35 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int					main(void)
{
	char			*line;

	while (get_next_line(0, &line))
	{
		if (!ft_strcmp(line, "exit"))
			return (0);
		ft_autocomplete(line);
	}
	return (0);
}
