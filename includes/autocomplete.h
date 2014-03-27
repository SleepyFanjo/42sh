/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:49:57 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 12:16:29 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOCOMPLETE_H
# define AUTOCOMPLETE_H

# include <dirent.h>
# include "../libft/libft.h"
# include "parser.h"
# include "select_cmd.h"
# include "norminette_are_you_serious.h"

int				ft_autocomplete(t_param *param);
typedef struct	s_dummy
{
	char		*s;
	char		*s_cmp;
}				t_dummy;
int				l_search_file(char type, char *s, t_list **begin, t_param *p);
int				l_search_cmd(char type, char *s, t_list **begin, t_param *p);
int				l_search_exe(char type, char *s, t_list **begin, t_param *p);
int				l_search_link(char type, char *s, t_list **begin, t_param *p);
char			*ft_get_string(char **s1);
int				l_is_exe(char *s, struct dirent *ent, char *s_cmp);
int				l_is_dir(char *s, struct dirent *ent, char *s_cmp);
int				l_is_file(char *s, struct dirent *ent, char *s_cmp);
int				ft_auto_dir(t_dummy *s, t_check c, t_list **b, t_param *p);
int				ft_checkpath(char *s, t_list **begin, t_param *param);
char			*l_get_token(t_list *list, char *type);
void			l_check_token(char type, char *s, t_param *param);
t_list			*l_add_to_list(t_list *list, char *data);
void			l_del_list(t_list **list);
void			l_sort_list(t_list *begin);
void			insert_word(char *s, t_param *param, char **old);
void			del_word(char *s, t_param *param, char **old);
char			*get_env(char **envp, char *env);

#endif
