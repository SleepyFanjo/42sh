/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 11:16:46 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/12 15:54:28 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <libft.h>
# include <struct.h>

char		**g_env;

int			q_is_special_char(char *str, int i, int *end);
int			q_count_normal(char *str, int *beg, int *end);
int			q_count_token_len(char *str, int *beg, int *end, int *inh);
void		q_clean_inhib(char *str);
int			q_count_inhib(char *str, int *beg, int *end, int *inh);
int			q_is_whitespace(char c);
char		*q_strndup(char *str, int n, int inh);
void		q_error(char *s1, char *s2, int mode);
int			q_file_error(void);
t_list		*q_create_obj(void *elem);
int			q_add_in_list(t_list **list, void *elem);
t_token		*q_create_token(char *str, int *i, int *error);
t_token		*q_white_token(char *str, int *i);
t_token		*q_utility_token(char *name, int inh);
t_list		*q_lexer(char *str);
t_list		*q_rolex(t_list *list);
t_list		*q_parser(t_list *token_list);
t_cmd		*q_fill_cmd(t_list **token);
t_cmd		*q_init_cmd(void);
t_cmd		*q_check_cmd(t_cmd *cmd);
int			q_is_ctrl(t_token *elem);
int			q_is_slash(char *str);
int			q_add_in_cmd(t_token *elem, t_token *next, t_cmd *cmd);
int			q_add_link(char *link, t_token *file, t_cmd *cmd);
int			q_add_in_arg(char *str, t_cmd *cmd);
int			q_add_ctrl(char *str, t_cmd *cmd);
char		**q_tabjoin(char **tab, char *str);
void		q_free_tab(char **tab);
void		q_free_list(t_list **list);
void		q_free_cmd(t_list **cmd);
void		q_free_elem(t_cmd *elem);
void		q_delete_whitespace(t_list **list);
int			q_is_blank(void *elem);
void		q_free_token(t_list *token);


/* ***** */
char		*tmp_prompt(void);

#endif
