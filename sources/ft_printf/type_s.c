/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:02:01 by oem               #+#    #+#             */
/*   Updated: 2020/10/31 14:10:16 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	type_s(t_field f, va_list args)
{
	char *arg;
	int n;
	int i;

	n = 0;
	arg = va_arg(args, char *);
	if (f.minus == 0 && f.width == 0 && f.point == 0 && f.precision == 0)
		n = ft_putstr(arg);
	if (f.minus == 0 && f.width == 0 && f.point == 1 && f.precision == 0)
		return (n);
	if ((f.minus == 0 || f.minus == 1) && f.width == 0 && f.point == 1 && f.precision != 0)
		n = ft_putnstr(arg, f.precision);
	if (f.minus == 0 && f.width != 0 && f.point == 1 && f.precision != 0)
	{
		i = f.precision == 0 ? ft_strlen(arg) : f.precision;
		i -= f.width;
		i = i < 0 ? -(i) : i;
		while (i--)
			n += write(1, " ", 1);
		n = ft_putnstr(arg, f.precision);
	}
	if (f.minus == 1 && f.width != 0 && f.point == 1 && f.precision != 0)
	{
		i = f.precision == 0 ? ft_strlen(arg) : f.precision;
		n = ft_putnstr(arg, i);
		i -= f.width;
		i = i < 0 ? -(i) : i;
		while (i--)
			n += write(1, " ", 1);
	}
	if ((f.minus == 0 || f.minus == 1) && f.width != 0 && f.point == 1 && f.precision == 0)
	{
		while (f.width--)
			n += write(1, " ", 1);
	}
	if (f.minus == 0 && f.width != 0 && f.point == 0 && f.precision == 0)
		n = ft_putstr(arg);
	if (f.minus == 1 && f.width != 0 && f.point == 0 && f.precision == 0)
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
