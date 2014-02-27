/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 12:38:15 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/27 18:13:17 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdio.h>

static char	*q_get(char c)
{
	if (c == Q_CMD)
		return (ft_strdup("Commande"));
	if (c == Q_ARG)
		return (ft_strdup("Arguments"));
	if (c == Q_FILE)
		return (ft_strdup("Fichier"));
	if (c == Q_LINK)
		return (ft_strdup("Redirection"));
	if (c == Q_CTRL)
		return (ft_strdup("Controle"));
	return (ft_strdup("Blank"));
}

static void	print_list(t_list *list)
{
	t_token		*token;

	while (list != NULL)
	{
		token = list->elem;
		printf("\033[31m[%s]\033[0m, \033[36m[%s]\033[0m\n", token->name, q_get(token->type));
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
