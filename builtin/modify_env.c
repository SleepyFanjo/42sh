/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 18:13:01 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/18 15:46:16 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <libft.h>

static int	env_comp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && s1[i] != '=')
		i = i + 1;
	if (i >= 1 && s1[i] == '=' && s2[i] == '=')
		return (0);
	return (s1[i] - s2[i]);
}

static void	add_new_entry(char ***envp, char *entry)
{
	char	**buff;
	int		i;

	i = 0;
	while ((*envp) != NULL && (*envp)[i] != NULL)
		i = i + 1;
	if ((buff = (char **) malloc((i + 2) * sizeof(char *))) == NULL)
		ft_error("Error : can't malloc", NULL, 1);
	i = 0;
	while ((*envp) != NULL && (*envp)[i] != NULL)
	{
		buff[i] = ft_strdup((*envp)[i]);
		i = i + 1;
	}
	buff[i] = ft_strdup(entry);
	buff[i + 1] = NULL;
	*envp = buff;
}

void		modify_env(char ***envp, char *env)
{
	int		i;

	i = 0;
	while ((*envp) != NULL && (*envp)[i] != NULL)
	{
		if (!env_comp((*envp)[i], env))
		{
			(*envp)[i] = ft_strdup(env);
			return ;
		}
		i = i + 1;
	}
	add_new_entry(envp, env);
}
