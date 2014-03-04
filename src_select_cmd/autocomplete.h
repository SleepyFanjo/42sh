/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:49:57 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/04 12:16:50 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOCOMPLETE_H
# define AUTOCOMPLETE_H

# include <dirent.h>
# include "../libft/libft.h"
# include "../parser_mofo/parser.h"

int							ft_autocomplete(char *s);

/*
**
*/
int							l_search_file(char type, char *s);
int							l_search_dir(char type, char *s);
int							l_search_cmd(char type, char *s);

int							ft_auto_dir(char *s, char *s_cmp);

typedef int					(*t_tok_func)(char type, char *s);
char						*ft_get_string(char **s1);

static const t_tok_func		tok_tab[] =
{
							&l_search_file,
							&l_search_dir,
							&l_search_cmd,
							NULL
};

#endif
