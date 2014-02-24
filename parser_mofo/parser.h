/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 11:16:46 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/24 17:35:38 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <libft.h>
# include <struct.h>

int			q_is_whitespace(char c);
char		*g_strndup(char *str, int n);
void		q_error(char *s1, char *s2, int mode);
t_list		*q_create_obj(void *elem);
void		q_add_in_list(t_list **list, void *elem);
t_token		*q_create_token(char *str, int *i);
t_list		*q_lexer(char *str);

#endif
