/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:33:49 by calpha            #+#    #+#             */
/*   Updated: 2020/10/15 21:51:21 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
**Converting decimal numbers to numbers with a base from 2 to 36.
**A number with a base equal to ten can be either positive or negative.
**A number with a different base can only be positive.
*/

static int	digit_capacity(int value, int base)
{
	int i;

	i = 0;
	while (value != 0)
	{
		value = value / base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(int value, int base)
{
	char	*number;
	char	*s;
	size_t	i;
	int		r;

	number = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (base < 2 || base > 36)
		return ("ERROR. Enter the base from 2 to 36");
	i = digit_capacity(value, base);
	if (!(s = base == 10 && value < 0 ? ft_strnew(++i) : ft_strnew(i)))
		return (NULL);
	s[0] = base == 10 && value < 0 ? '-' : '0';
	while (value != 0)
	{
		r = value < 0 ? -(value % base) : value % base;
		s[--i] = number[r];
		value = value / base;
	}
	return (s);
}
