/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:34:54 by aschafer          #+#    #+#             */
/*   Updated: 2017/01/28 13:07:44 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_builtin	*get_builtins(void)
{
	static const t_builtin builtins[NB_BUILTINS] = {
		{"exit", bi_exit},
		{"alias", bi_alias},
		{"print", bi_print_hash},
		{"env", bi_env},
		{"setenv", bi_setenv},
		{"unsetenv", bi_unsetenv},
		{"exit", bi_exit},
		{"setenv", bi_setenv},
		{"cd", bi_cd},
		{"echo", bi_echo},
		{"history", bi_history},
		{"export", bi_export},
		{"unset", bi_unset},
		{"source", bi_source}
	};

	return ((t_builtin *)builtins);
}
