/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 12:38:15 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/27 16:22:23 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdio.h>

static void	print_list(t_list *list)
{
	t_token		*token;

	while (list != NULL)
	{
		token = list->elem;
		printf("Name : %s, type : %d\n", token->name, token->type);
		list = list->next;
	}
}

int		main(int ac, char **av)
{
	t_list		*list;

	list = NULL;
	if (ac == 2)
		list = q_lexer(ft_strdup(av[1]));
	print_list(list);
	return (0);
}
