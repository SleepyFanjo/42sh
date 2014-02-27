/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 16:02:14 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/27 16:16:14 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# define Q_STR		(-1)
# define Q_CMD		(1)
# define Q_ARG		(2)
# define Q_FILE		(3)
# define Q_BUILTIN	(4)
# define Q_LINK		(5)
# define Q_CTRL		(6)

# define Q_SPACE	(0)

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
