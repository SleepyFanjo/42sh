/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 12:38:15 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/07 17:03:15 by qchevrin         ###   ########.fr       */
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
	if (c == Q_SPACE)
		return (ft_strdup("Whitespace"));
	return (ft_strdup("Unknown"));
}

static void	print_cmd(t_list *list)
{
	t_cmd		*cmd;
	int			i;

	while (list != NULL)
	{
		cmd = list->elem;
		printf("cmd = %s\n", cmd->cmd);
		i = 0;
		if (cmd->arg != NULL)
		{
			printf("args : ");
			while ((cmd->arg)[i] != NULL)
			{
				printf("%s ", (cmd->arg)[i]);
				i = i + 1;
			}
			printf("\n");
		}
		printf("file in : %s, file out : %s\n", cmd->file_in, cmd->file_out);
		printf("in_mode : %d, out_mode :%d\n", cmd->in_mode, cmd->out_mode);
		printf("next_cmd : %d\n", cmd->next_cmd);
		ft_putendl("\n");
		list = list->next;
	}
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
	t_list		*cmd;
	char		*line;

	list = NULL;
	while (get_next_line(0, &line))
	{
		list = q_lexer(line);
		print_list(list);
		cmd = q_parser(list);
		print_cmd(cmd);
		q_free_list(&list);
		q_free_cmd(&cmd);
	}
	return (0);
}
