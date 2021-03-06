/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 13:30:34 by calpha            #+#    #+#             */
/*   Updated: 2020/10/21 16:22:19 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char const *s)
{
	int n;

	n = 0;
	if (s)
	{
		while (*s != '\0')
			n += write(1, s++, 1);
	}
	return (n);
}
