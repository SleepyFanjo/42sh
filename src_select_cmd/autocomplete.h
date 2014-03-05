/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:49:57 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/05 18:39:14 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOCOMPLETE_H
# define AUTOCOMPLETE_H

# include <dirent.h>
# include "../libft/libft.h"
# include "../parser_mofo/parser.h"

char				**lova_envp; // a savoir comment en gere ca

int						ft_autocomplete(char *s);

/*
**   l_search.c
*/
int						l_search_file(char type, char *s);
int						l_search_dir(char type, char *s);
int						l_search_cmd(char type, char *s);
int						l_search_exe(char type, char *s);
int						l_search_link(char type, char *s);

typedef int				(*t_tok_func)(char type, char *s);
char					*ft_get_string(char **s1);

static const t_tok_func	tok_tab[] =
{
						&l_search_file,
						&l_search_dir,
						&l_search_cmd,
						&l_search_exe,
						&l_search_link,
						NULL
};

/*
**   l_to_check.c
*/
int						l_is_exe(char *s, struct dirent *ent, char *s_cmp);
int						l_is_dir(char *s, struct dirent *ent, char *s_cmp);
int						l_is_file(char *s, struct dirent *ent, char *s_cmp);

typedef int				(*t_check)(char *s, struct dirent *ent, char *s_cmp);

static const t_check	to_check[] =
{
						&l_is_exe,
						&l_is_dir,
						&l_is_file
};

int						ft_auto_dir(char *s, char *s_cmp, t_check check_it);

/*
**   l_path.c
*/
int						ft_checkpath(char *s);

#endif
