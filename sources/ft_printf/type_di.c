/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:13:21 by oem               #+#    #+#             */
/*   Updated: 2020/11/27 16:09:57 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *type_conversion(t_field f, va_list args)
{
	if (!ft_strcmp(f.size, "\0"))
		return (ft_itoa(va_arg(args, int)));
	if (!ft_strcmp(f.size, "l"))
		return (ft_lltoa_base((va_arg(args, long int)), 10));
	if (!ft_strcmp(f.size, "hh"))
		return (ft_sctoa(va_arg(args, int)));
	if (!ft_strcmp(f.size, "h"))
		return (ft_sitoa(va_arg(args, int)));
	if (!ft_strcmp(f.size, "ll"))
		return (ft_lltoa_base(va_arg(args, long long int), 10));
	if (!ft_strcmp(f.size, "j"))
		return (ft_lltoa_base(va_arg(args, __intmax_t), 10));
	if (!ft_strcmp(f.size, "z"))
		return (ft_lltoa_base(va_arg(args, long long int), 10));
	if (!ft_strcmp(f.size, "L"))
		return (ft_lltoa_base(va_arg(args, __int64_t), 10));
	return (NULL);
}

int	type_di(t_field f, va_list args)
{
	char *s;
	signed long long int n;
	int i;

	s = type_conversion(f, args);

	if ((f.minus == 0 && f.plus == 0 && f.space == 0 && f.zero == 0) && f.width == 0 && (f.dot == 0 && f.precision == 0))
		n = ft_putstr(s);
	if ((f.minus == 1 || f.plus == 1 || f.space == 1 || f.zero == 1) && f.width == 0 && (f.dot == 0 && f.precision == 0))
	{
		if (f.plus == 1)
			n = write(1, "+", 1);
		if (f.space == 1)
			n = write(1, " ", 1);
		n += ft_putstr(s);
	}
	if ((f.minus == 0 && f.plus == 0 && f.space == 0 && f.zero == 0) && f.width != 0 && (f.dot == 0 && f.precision == 0))
	{
		i = ft_strlen(s);
		if (i >= f.width)
			return (ft_putstr(s));
		f.width -= i;
		while (f.width--)
			n += write(1, " ", 1);
		n += ft_putstr(s);
	}
	if ((f.minus == 0 && f.plus == 0 && f.space == 0 && f.zero == 0) && f.width == 0 && (f.dot == 1 || f.precision != 0))
	{
		if (f.dot == 1 && f.precision == 0)
			return(ft_putstr(s));
		if (f.dot == 1 && f.precision != 0)
		{
			i = ft_strlen(s);
			if ((size_t)i >= f.precision)
				return (ft_putstr(s));
			else
			{
				f.precision -= i;
				while (f.precision--)
					n += write(1, "0", 1);
				n += ft_putstr(s);
			}
		}
	}
	if ((f.minus == 1 || f.plus == 1 || f.space == 1 || f.zero == 1) && f.width != 0 && (f.dot == 0 || f.precision == 0))
	{
		i = ft_strlen(s);
		if (i >= f.width)
		{
			if (f.plus == 1)
				n = write(1, "+", 1);
			if (f.space == 1)
				n = write(1, " ", 1);
			n += ft_putstr(s);
		}
		else
		{
			if (f.minus == 1)
			{
				if (f.plus == 1)
					n = write(1, "+", 1);
				if (f.space == 1)
					n = write(1, " ", 1);
				n += ft_putstr(s);
			}
			else
			{
				if (f.plus == 1)
				{
					if (f.zero == 1)
					{
						n += write(1, "+", 1);
						f.width -= i;
						f.width--;
						while (f.width--)
							n += write(1, "0", 1);
						n += ft_putstr(s);
					}
					else
					{
						f.width -= i;
						f.width--;
						while (f.width--)
							n += write(1, " ", 1);
						n += write(1, "+", 1);
						n += ft_putstr(s);
					}
				}
				else
				{
					if (f.zero == 1)
					{
						f.width -= i;
						while (f.width--)
							n += write(1, "0", 1);
						n += ft_putstr(s);
					}
					if (f.space == 1)
					{
						f.width -= i;
						while (f.width--)
							n += write(1, " ", 1);
						n += ft_putstr(s);
					}
				}
			}
		}
	}
	if ((f.minus == 1 || f.plus == 1 || f.space == 1 || f.zero == 1) && f.width == 0 && (f.dot == 1 || f.precision == 1))
	{
		i = ft_strlen(s);
		if ((size_t)i >= f.precision)
		{
			if (f.plus == 1)
				n = write(1, "+", 1);
			if (f.space == 1)
				n = write(1, " ", 1);
			n += ft_putstr(s);
		}
		else
		{
			if (f.minus == 1)
			{
				if (f.plus == 1)
					n = write(1, "+", 1);
				if (f.space == 1)
					n = write(1, " ", 1);
				f.precision -= i;
				while (f.precision--)
					n += write(1, "0", 1);
				n += ft_putstr(s);
			}
			else
			{
				if (f.plus == 1)
					n = write(1, "+", 1);
				if (f.space == 1)
					n = write(1, " ", 1);
				f.precision -= i;
				while (f.precision--)
					n += write(1, "0", 1);
				n += ft_putstr(s);
			}
		}
	}
	if ((f.minus == 0 && f.plus == 0 && f.space == 0 && f.zero == 0) && f.width != 0 && (f.dot == 1 || f.precision != 0))
	{
		i = ft_strlen(s);
		if ((size_t)i > (size_t)f.width && (size_t)i > (size_t)f.precision)
			n += ft_putstr(s);
		if ((size_t)i > (size_t)f.width && (size_t)i < (size_t)f.precision)
		{
			f.precision -= i;
			while (f.precision--)
				n += write(1, "0", 1);
			n += ft_putstr(s);
		}
		if ((size_t)i < (size_t)f.width && (size_t)i > (size_t)f.precision)
		{
			f.width -= i;
			while (f.width--)
				n += write(1, " ", 1);
			n += ft_putstr(s);
		}
		if ((size_t)i < (size_t)f.width && (size_t)f.width > (size_t)f.precision)
		{
			f.width -= f.precision;
			f.width -= i;
			// printf("%ld %d %d", f.precision, i, f.width);
			// while (f.width--)
			// 	n += write(1, " ", 1);
			// while (f.precision--)
			// 	n += write(1, "0", 1);
			n += ft_putstr(s);
		}
	}

	// if ((f.minus == 1 || f.plus == 1 || f.space == 1 || f.zero == 1) && f.width != 0 && (f.dot == 1 || f.precision != 0))

	return (n);
}
