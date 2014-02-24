/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 10:36:24 by qchevrin          #+#    #+#             */
/*   Updated: 2013/12/29 18:20:13 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_realloc_cat(char **dest, char *src)
{
	char	*buff;
	int		size;

	size = (int) ft_strlen(*dest) + (int) ft_strlen(src) + 1;
	buff = *dest;
	free(*dest);
	if ((*dest = (char *) malloc(size * sizeof(char))) == NULL)
		return (-1);
	ft_strcpy(*dest, buff);
	ft_strcat(*dest, src);
	return (0);
}

static int	test_ret(char *buff)
{
	if (buff != NULL && *buff != '\0' && *buff != EOF)
	{
		*buff = '\0';
		return (1);
	}
	else
		return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char	old_char[BUFF_SIZE + 1] = "";
	char		buff[BUFF_SIZE + 1];
	char		*pos;
	int			ret;

	if ((*line = (char *) malloc((int) ft_strlen(old_char) + 1)) == NULL)
		return (-1);
	*line = ft_strcpy(*line, old_char);
	while ((pos = ft_strchr(*line, '\n')) == NULL
			&& (ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if (str_realloc_cat(line, buff) == -1)
			return (-1);
	}
	if (pos != NULL)
	{
		pos = ft_strchr(*line, '\n');
		*pos = '\0';
		ft_strcpy(old_char, pos + 1);
		return (1);
	}
	return (test_ret(old_char));
}
