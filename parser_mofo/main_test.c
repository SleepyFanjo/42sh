/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 12:38:15 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/04 10:56:08 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdio.h>

static char	*q_get(char c)
{
	if (c == Q_CMD)
		return (ft_strdup("Commande"));
	if (c == Q_EXE)
		return (ft_strdup("Executable"));
	if (c == Q_ARG)
		return (ft_strdup("Arguments"));
	if (c == Q_FILE)
		return (ft_strdup("Fichier"));
	if (c == Q_LINK)
		return (ft_strdup("Redirection"));
	if (c == Q_CTRL)
		return (ft_strdup("Controle"));
	return (ft_strdup("Unknown"));
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

int		main(void)
{
	t_list		*list;
	char		*line;

	list = NULL;
	while (get_next_line(0, &line))
	{
		list = q_lexer(line);
		print_list(list);
		q_free_list(&list);
	}
	return (0);
}
