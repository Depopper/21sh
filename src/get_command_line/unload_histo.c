/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unload_histo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:31:37 by aschafer          #+#    #+#             */
/*   Updated: 2016/11/14 19:31:41 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"

void	unload_histo(t_histo **histo)
{
	if (!histo || !*histo)
		return ;
	if ((*histo)->prev)
		unload_histo(&(*histo)->prev);
	free((*histo)->value);
	ft_memdel((void **)histo);
}
