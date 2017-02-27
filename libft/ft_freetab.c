/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 12:58:35 by aschafer          #+#    #+#             */
/*   Updated: 2017/01/27 18:07:48 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_freetab(void **arr)
{
	int i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while (arr[i])
	{
		ft_putendl(arr[i]);
		free(arr[i++]);
	}
	free(arr);
}
