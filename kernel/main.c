/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 15:38:46 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/13 20:11:53 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/launch_cmd.h"

static char		**ft_cpytab(char **src)
{
	int		i;
	char	**table;

	i = 0;
	while (src[i] != NULL)
		i++;
	if ((table = (char **)malloc(sizeof(char *) * (i + 10))) == NULL)
		return (NULL);
	i = 0;
	while (src[i] != NULL)
	{
		if ((table[i] = ft_strdup(src[i])) == NULL)
			return (NULL);
		i++;
	}
	table[i] = NULL;
	return (table);
}

static void		sub_shell(char *str)
{
	t_list	*list;
	t_list	*cmd;

	if (!(list = q_lexer(str)))
		exit(1);
	if (!(cmd = q_parser(list)))
		exit(1);
	launch_cmd(cmd);
	q_free_cmd(&cmd);
	exit(0);
}

static void		fucking_fucking_norm(t_history **history, char *line, char *prompt)
{
	t_list		*list;
	t_list		*cmd;

	add_in_history(history, line);
	free(prompt);
	if (!(list = q_lexer(line)))
		return ;
	if (!(cmd = q_parser(list)))
		return ;
	launch_cmd(cmd);
	q_free_cmd(&cmd);
}

int				main(int argc, char **argv)
{
	char		*line;
	t_history	*history;
	char		*prompt;

	g_pid = -1;
	g_env = ft_cpytab(environ);
	history = NULL;
	if (init_sig() < 0)
	{
		ft_printf("%rUnable to manage signal\n");
		return (1);
	}
	if (argc > 1)
		sub_shell(argv[1]);
	while ((line = select_cmd(28, (prompt = tmp_prompt()), history)))
	{
		fucking_fucking_norm(&history, line, prompt);
	}
	return (0);
}
