/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:02:01 by oem               #+#    #+#             */
/*   Updated: 2020/11/01 01:45:43 by oem              ###   ########.fr       */
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
		n += ft_putstr(arg);
	else if (f.minus == 0 && f.width == 0 && f.dot == 1 && f.precision == 0)
		return (n);
	else if (f.width == 0 && f.dot == 1 && f.precision != 0)
	{
		i = ft_strlen(arg);
		if ((size_t)i >= f.precision)
			return (ft_putnstr(arg, f.precision));
		else
			return (ft_putnstr(arg, i));
	}
	else if (f.minus == 0 && f.width != 0 && f.dot == 1 && f.precision != 0)
	{
		i = ft_strlen(arg);
		if (i < f.width)
		{
			if ((size_t)i < f.precision)
			{
				f.width -= i;
				while (f.width--)
					n += write(1, " ", 1);
				n += ft_putstr(arg);
			}
			else
			{
				f.width -= f.precision;
				while (f.width--)
					n += write(1, " ", 1);
				n += ft_putnstr(arg, f.precision);
			}
		}
		else
		{
			if ((size_t)i < f.precision)
				n += ft_putstr(arg);
			else if ((size_t)i >= f.precision && (size_t)f.width < f.precision)
			{
				n += ft_putnstr(arg, f.precision);
				return (n);
			}
			else if ((size_t)i >= f.precision && (size_t)f.width >= f.precision)
			{
				f.width -= f.precision;
				f.width = f.width < 0 ? -(f.width) : f.width;
				while (f.width--)
					n += write(1, " ", 1);
				n += ft_putnstr(arg, f.precision);
			}
		}
	}
	else if (f.minus == 1 && f.width != 0 && f.dot == 1 && f.precision != 0)
	{
		i = ft_strlen(arg);
		if (i < f.width)
		{
			if ((size_t)i < f.precision)
			{
				n += ft_putstr(arg);
				f.width -= i;
				while (f.width--)
					n += write(1, " ", 1);
			}
			else
			{
				n += ft_putnstr(arg, f.precision);
				f.width -= f.precision;
				while (f.width--)
					n += write(1, " ", 1);
			}
		}
		else
		{
			if ((size_t)i < f.precision)
				n += ft_putstr(arg);
			else if ((size_t)i >= f.precision && (size_t)f.width < f.precision)
			{
				n += ft_putnstr(arg, f.precision);
				return (n);
			}
			else if ((size_t)i >= f.precision && (size_t)f.width >= f.precision)
			{
				n += ft_putnstr(arg, f.precision);
				f.width -= f.precision;
				f.width = f.width < 0 ? -(f.width) : f.width;
				while (f.width--)
					n += write(1, " ", 1);
			}
		}
	}
	else if ((f.minus == 0 || f.minus == 1) && f.width != 0 && f.dot == 1 && f.precision == 0)
	{
		while (f.width--)
			n += write(1, " ", 1);
	}
	else if (f.minus == 0 && f.width != 0 && f.dot == 0 && f.precision == 0)
	{
		i = ft_strlen(arg);
		if (i >= f.width)
			return (ft_putstr(arg));
		f.width -= i;
		while (f.width--)
			n += write(1, " ", 1);
		n += ft_putstr(arg);
	}
	else if (f.minus == 1 && f.width != 0 && f.dot == 0 && f.precision == 0)
	{
		i = ft_strlen(arg);
		if (i >= f.width)
			return (ft_putstr(arg));
		else
		{
			n += ft_putstr(arg);
			f.width -= i;
			while (f.width--)
				n += write(1, " ", 1);
		}
	}
	return (n);
}
