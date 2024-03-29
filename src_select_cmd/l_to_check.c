/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_to_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 12:12:37 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/14 19:57:00 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int						l_is_exe(char *s, struct dirent *ent, char *s_cmp)
{
	char				*path;
	char				*tmp;

	tmp = ft_strjoin(s, "/");
	path = ft_strjoin(tmp, ent->d_name);
	free(tmp);
	if ((access(path, X_OK) == 0 || l_is_dir(s, ent, s_cmp))
			&& l_is_file(s, ent, s_cmp))
	{
		free(path);
		return (1);
	}
	free(path);
	return (0);
}

int						l_is_dir(char *s, struct dirent *ent, char *s_cmp)
{
	if (ent->d_type == DT_DIR)
		return (1);
	(void)s;
	(void)s_cmp;
	return (0);
}

int						l_is_file(char *s, struct dirent *ent, char *s_cmp)
{
	if (!(ft_strcmp(ent->d_name, ".")) || !(ft_strcmp(ent->d_name, "..")))
		return (0);
	if (s_cmp != NULL && *s_cmp == '\0' && ent->d_name[0] == '.')
		return (0);
	(void)s;
	(void)s_cmp;
	return (1);
}
