/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:26 by aschafer          #+#    #+#             */
/*   Updated: 2015/11/29 23:16:55 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	isneg;

	result = 0;
	isneg = 0;
	while (*str == ' ' || ft_isescaped(*str))
		str++;
	if (*str == '-' || *str == '+')
		isneg = (*(str++) == '-') ? 1 : 0;
	while (*str && ft_isdigit(*str))
		result = result * 10 + (*(str++) - 48);
	return (isneg ? result * -1 : result);
}
