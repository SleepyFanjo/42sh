/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:27:25 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/12 18:38:47 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <launch_cmd.h>

static char	*add_tild(char *pwd, int len)
{
	char	*tmp;

	if (!(tmp = ft_strdup("~")))
		exit(0);
	if (!(tmp = ft_str_realloc_cat(&tmp, &pwd[len])))
		exit(0);
	free(pwd);
	return (tmp);
}

static char	*home_sweet_home(char *pwd)
{
	char	**tmp;
	char	*home;
	int		len;
	int		i;

	if (!pwd)
		exit(0);
	i = 0;
	tmp = g_env;
	while (tmp[i] != NULL)
	{
		if (!ft_strncmp("HOME=", tmp[i], 5))
		{
			if (!(home = ft_strdup(&tmp[i][5])))
				exit(0);
			len = ft_strlen(home);
			if (!ft_strncmp(home, pwd, len))
				pwd = add_tild(pwd, len);
			free(home);
			return (pwd);
		}
		i++;
	}
	return (pwd);
}

static char	*get_pwd(void)
{
	int		i;
	char	**tmp;
	char	*pwd;

	i = 0;
	tmp = g_env;
	while (tmp[i] != NULL)
	{
		if (!ft_strncmp("PWD=", tmp[i], 4))
		{
			pwd = home_sweet_home(ft_strdup(&tmp[i][4]));
			return (pwd);
		}
		i++;
	}
	return (NULL);
}

char		*tmp_prompt(void)
{
	char	*line;
	char	*pwd;

	if ((pwd = get_pwd()) != NULL)
	{
		ft_putstr("\033[31m[");
		ft_putstr(pwd);
		ft_putstr("]\n\033[0m");
		free(pwd);
	}
	line = ft_strdup("\033[32mTHE Fuckin' $hell (.)(.) #> \033[0m");
	return (line);
}
