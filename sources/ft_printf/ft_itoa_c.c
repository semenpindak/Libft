/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:21:49 by calpha            #+#    #+#             */
/*   Updated: 2020/10/09 20:10:39 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_c(long long int n, int *a)
{
	int				i;
	long long int	r;
	char			*s;

	i = razradl(n);
	*a = i;
	if (i == 0)
	{
		if (!(s = ft_strnew(1)))
			return (NULL);
	}
	else
	{
		if (!(s = ft_strnew(i)))
			return (NULL);
	}
	if (n == 0)
		s[0] = '0';
	while (n != 0)
	{
		r = n < 0 ? -(n % 10) : n % 10;
		s[--i] = r + '0';
		n = n / 10;
	}
	return (s);
}
