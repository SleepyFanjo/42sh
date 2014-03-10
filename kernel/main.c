/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 15:38:46 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/10 17:10:47 by vwatrelo         ###   ########.fr       */
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

int			main(void)
{
	char		*line;
	t_list		*list;
	t_list		*cmd;

	g_env = ft_cpytab(environ);
	while ((line = tmp_prompt()))
	{
		if (!(list = q_lexer(line)))
			continue ;
		if (!(cmd = q_parser(list)))
			continue ;
		launch_cmd(cmd);
		q_free_list(&list);
		q_free_cmd(&cmd);
	}
}
