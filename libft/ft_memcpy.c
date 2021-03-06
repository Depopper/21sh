/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:28 by aschafer          #+#    #+#             */
/*   Updated: 2015/11/29 23:16:57 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*from;
	unsigned char	*to;

	from = (unsigned char *)src;
	to = (unsigned char *)dest;
	i = 0;
	while (i++ < n)
		*(to++) = *(from++);
	return (dest);
}
