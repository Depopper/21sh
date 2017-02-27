/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdebug.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:09:34 by aschafer          #+#    #+#             */
/*   Updated: 2016/12/08 16:10:47 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	pdebug(char *str)
{
	static t_shell *sh = NULL;

	if (!sh)
		sh = get_shell();
	if (sh->is_interactive)
		ft_putendl_fd(str, sh->tout);
}
