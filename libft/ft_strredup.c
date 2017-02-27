/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strredup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:27:56 by aschafer          #+#    #+#             */
/*   Updated: 2016/11/14 20:40:50 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strredup(char *orig, char *str)
{
	char	*tmp;

	tmp = ft_strdup(str);
	ft_memdel((void **)&orig);
	return (tmp);
}
