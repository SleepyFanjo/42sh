/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   really_serious.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 11:58:14 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/27 12:16:25 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REALLY_SERIOUS_H
# define REALLY_SERIOUS_H

typedef int	(*t_tok_func)(char type, char *s, t_list **begin, t_param *param);
typedef int	(*t_check)(char *s, struct dirent *ent, char *s_cmp);
int		l_search_file(char type, char *s, t_list **begin, t_param *p);
int		l_search_cmd(char type, char *s, t_list **begin, t_param *p);
int		l_search_exe(char type, char *s, t_list **begin, t_param *p);
int		l_search_link(char type, char *s, t_list **begin, t_param *p);
int		l_is_exe(char *s, struct dirent *ent, char *s_cmp);
int		l_is_dir(char *s, struct dirent *ent, char *s_cmp);
int		l_is_file(char *s, struct dirent *ent, char *s_cmp);
#endif
