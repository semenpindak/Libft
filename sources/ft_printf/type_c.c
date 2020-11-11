/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:03:55 by oem               #+#    #+#             */
/*   Updated: 2020/10/31 17:17:15 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	type_c(t_field f, va_list args)
{
	char arg;
	int n;

	n = 0;
	arg = va_arg(args, int);
	if ((f.minus == 0 || f.minus == 1) && f.width == 0)
		return (write(1, &arg, 1));
	else if (f.minus == 0 && f.width != 0)
	{
		f.width--;
		while (f.width--)
			n += write(1, " ", 1);
		n += write(1, &arg, 1);
	}
	else if (f.minus == 1 && f.width != 0)
	{
		n += write(1, &arg, 1);
		f.width--;
		while (f.width--)
			n += write(1, " ", 1);
	}
	return (n);
}
