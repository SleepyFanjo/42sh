/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 16:02:14 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/26 17:51:15 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# define Q_STR		(-1)
# define Q_CMD		(0)
# define Q_ARG		(1)
# define Q_FILE		(2)
# define Q_LINK		(3)
# define Q_BUILTIN	(6)
# define Q_CTRL		(7)
# define Q_SPACE	(8)

/*
** Q_LINK : Redirection '<' '>' '<<' '>>'
** Q_D_INHIB : Inhibiteur double "" ou ' '
** Q_U_INHIB : Inhibiteur simple /
** Q_CTRL : Separateur de commande '&&' '||' '|' '&'
** Q_SPACE : Whitespace : ' ' '\t' '\n'
*/

typedef struct		s_list
{
	void			*elem;
	struct s_list	*next;
}					t_list;

typedef struct		s_token
{
	char			*name;
	char			type;
}					t_token;

#endif
