/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminette_are_you_serious.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 11:49:51 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/27 12:18:15 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMINETTE_ARE_YOU_SERIOUS_H
# define NORMINETTE_ARE_YOU_SERIOUS_H
# include "really_serious.h"
# include "autocomplete.h"

static const t_tok_func		g_tok_tab[] =
{
	&l_search_file,
	&l_search_exe,
	&l_search_link,
	&l_search_cmd,
	NULL
};

static const t_check		g_to_check[] =
{
	&l_is_exe,
	&l_is_dir,
	&l_is_file
};

#endif
