/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 11:16:46 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/27 18:07:17 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <libft.h>
# include <struct.h>

int			q_is_special_char(char *str, int i, int *end);
int			q_count_normal(char *str, int *beg, int *end);
int			q_count_token_len(char *str, int *beg, int *end, int *inh);
int			q_is_whitespace(char c);
char		*q_strndup(char *str, int n, int inh);
void		q_error(char *s1, char *s2, int mode);
t_list		*q_create_obj(void *elem);
int			q_add_in_list(t_list **list, void *elem);
t_token		*q_create_token(char *str, int *i);
t_token		*q_white_token(char *str, int *i);
t_token		*q_utility_token(char *name);
t_list		*q_lexer(char *str);
t_list		*q_rolex(t_list *list);
void		q_free_list(t_list **list);


/* ***** */
char		*tmp_prompt(void);

#endif
