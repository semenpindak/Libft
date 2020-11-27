/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sctoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 05:38:32 by calpha            #+#    #+#             */
/*   Updated: 2020/11/27 12:20:24 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_capacity(signed char n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_sctoa(signed char n)
{
	char	*s;
	int		i;
	int		r;

	i = digit_capacity(n);
	if (!(s = n <= 0 ? ft_strnew(++i) : ft_strnew(i)))
		return (NULL);
	s[0] = n < 0 ? '-' : '0';
	while (n != 0)
	{
		r = n < 0 ? -(n % 10) : n % 10;
		s[--i] = r + '0';
		n = n / 10;
	}
	return (s);
}
