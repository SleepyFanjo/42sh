/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 15:24:23 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/12 15:39:51 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "../includes/launch_cmd.h"

int					total_len(char **table)
{
	int				i;
	int				j;
	int				n;

	i = 1;
	n = 0;
	while (table[i] != NULL)
	{
		j = 0;
		while (table[i][j++] != '\0')
			n++;
		i++;
	}
	return (n);
}

char				check_esc(char c)
{
	int				i;
	char			*s1;
	char			*s2;

	s1= "abcefnrtv";
	s2 = "\a\bc\e\f\n\r\t\v";
	i = 0;
	while (s1[i] != '\0' && s1[i] != c)
		i++;
	return (s2[i]);
}

char				check_char(char *str, int *i, int opt_E)
{
	char			c;

	if (opt_E == 0 && str[*i] == '\\')
	{
		while (str[*i] == '\\' && str[*i + 1] == '\\')
			*i += 1;
		if ((c = check_esc(str[*i + 1])) != '\0')
		{
			*i += 1;
			if (c == 'c')
				return ('\0');
			return (c);
		}
	}
	return (str[*i]);
}

char				*ft_trans(char **arg, int i, int opt_E)
{
	int				j;
	int				k;
	char			*str;

	k = 0;
	if ((str = (char *)malloc(sizeof(char) * total_len(arg) + 1)) == NULL)
		return (NULL);
	while (arg[i] != NULL)
	{
		j = 0;
		while (arg[i][j] != '\0')
		{
			str[k++] = check_char(arg[i], &j, opt_E);
			j++;
		}
		if (arg[i + 1] != NULL)
			str[k++] = ' ';
		i++;
	}
	str[k] = '\0';
	return (str);
}

void				ft_echo(char **arg, int fd)
{
	int				*opt;
	char			*str;

	opt = check_opt(arg);
	str = ft_trans(arg, opt[0], opt[2]);
	ft_putstr_fd(str, fd);
	if (opt[1] == 0)
		ft_putendl_fd("", fd);
	free(str);
	free(opt);
}
