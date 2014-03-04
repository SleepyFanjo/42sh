/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_autoC.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:57:23 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/03 18:43:22 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int					main(void)
{
	char			*line;

	line = NULL;
	ft_putendl("Welcome in the testing program");
	while (get_next_line(0, &line))
	{
		if (!ft_strcmp(line, "exit"))
			return (0);
		ft_autocomplete(line);
	}
	return (0);
}