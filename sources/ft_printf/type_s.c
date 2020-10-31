/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:02:01 by oem               #+#    #+#             */
/*   Updated: 2020/10/31 14:32:59 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	type_s(t_field f, va_list args)
{
	char *arg;
	int n;
	int i;

	arg = va_arg(args, char *);
	n = 0;
	i = 0;
	if (f.minus == 0 && f.width == 0 && f.dot == 0 && f.precision == 0)
		n = ft_putstr(arg);
	else if (f.minus == 0 && f.width == 0 && f.dot == 1 && f.precision == 0)
		return (n);
	else if ((f.minus == 0 || f.minus == 1) && f.width == 0 && f.dot == 1 && f.precision != 0)
		n = ft_putnstr(arg, f.precision);
	else if (f.minus == 0 && f.width != 0 && f.dot == 1 && f.precision != 0)
	{
		i = f.precision == 0 ? ft_strlen(arg) : f.precision;
		i -= f.width;
		i = i < 0 ? -(i) : i;
		while (i--)
			n += write(1, " ", 1);
		n = ft_putnstr(arg, f.precision);
	}
	else if (f.minus == 1 && f.width != 0 && f.dot == 1 && f.precision != 0)
	{
		i = f.precision == 0 ? ft_strlen(arg) : f.precision;
		n = ft_putnstr(arg, i);
		i -= f.width;
		i = i < 0 ? -(i) : i;
		while (i--)
			n += write(1, " ", 1);
	}
	else if ((f.minus == 0 || f.minus == 1) && f.width != 0 && f.dot == 1 && f.precision == 0)
	{
		while (f.width--)
			n += write(1, " ", 1);
	}
	else if (f.minus == 0 && f.width != 0 && f.dot == 0 && f.precision == 0)
		n = ft_putstr(arg);
	else if (f.minus == 1 && f.width != 0 && f.dot == 0 && f.precision == 0)
	{
		n = ft_putstr(arg);
		i = f.precision == 0 ? ft_strlen(arg) : f.precision;
		i -= f.width;
		i = i < 0 ? -(i) : i;
		while (i--)
			n += write(1, " ", 1);
	}
	return (n);
}
