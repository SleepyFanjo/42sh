/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:49:57 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/17 16:00:01 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOCOMPLETE_H
# define AUTOCOMPLETE_H

# include <dirent.h>
# include "../libft/libft.h"
# include "parser.h"
# include "select_cmd.h"

int			ft_autocomplete(t_param *param);

typedef struct	s_dummy
{
	char		*s;
	char		*s_cmp;
}				t_dummy;

/*
**   l_search.c
*/
int			l_search_file(char type, char *s, t_list **begin, t_param *param);
int			l_search_cmd(char type, char *s, t_list **begin, t_param *param);
int			l_search_exe(char type, char *s, t_list **begin, t_param *param);
int			l_search_link(char type, char *s, t_list **begin, t_param *param);

char		*ft_get_string(char **s1);

typedef int	(*t_tok_func)(char type, char *s, t_list **begin, t_param *param);

static const t_tok_func	tok_tab[] =
{
			&l_search_file,
			&l_search_exe,
			&l_search_link,
			&l_search_cmd,
			NULL
};

/*
**   l_to_check.c
*/
int			l_is_exe(char *s, struct dirent *ent, char *s_cmp);
int			l_is_dir(char *s, struct dirent *ent, char *s_cmp);
int			l_is_file(char *s, struct dirent *ent, char *s_cmp);

typedef int	(*t_check)(char *s, struct dirent *ent, char *s_cmp);

static const t_check	to_check[] =
{
						&l_is_exe,
						&l_is_dir,
						&l_is_file
};

int			ft_auto_dir(t_dummy *s, t_check c, t_list **b, t_param *p);

/*
**   l_path.c
*/
int			ft_checkpath(char *s, t_list **begin, t_param *param);

/*
**   l_tok_game.c
*/
char		*l_get_token(t_list *list, char *type);
void		l_check_token(char type, char *s, t_param *param);

/*
**   l_list.c
*/
t_list		*l_add_to_list(t_list *list, char *data);
void		l_del_list(t_list **list);

/*
**   l_edit_word.c
*/
void		insert_word(char *s, t_param *param, char **old);
void		del_word(char *s, t_param *param, char **old);

/*
**  move_dir.c
*/
char		*get_env(char **envp, char *env);
#endif
