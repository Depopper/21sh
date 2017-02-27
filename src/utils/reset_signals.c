/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 22:05:14 by aschafer          #+#    #+#             */
/*   Updated: 2017/01/27 22:05:16 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	reset_signals(void)
{
	int i;

	i = 0;
	while (i < 35)
		signal(i++, SIG_DFL);
}
