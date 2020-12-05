/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:02:01 by oem               #+#    #+#             */
/*   Updated: 2020/12/05 21:28:46 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pos_two(t_field f, char *arg, size_t i)
{
	if (i < f.width)
	{
		if (f.minus == 0 && i < f.precision)
			return (print_reverse_order(f, arg, i));
		if (f.minus == 0 && i >= f.precision)
			return (print_n_reverse_order(f, arg));
		if (f.minus != 0 && i < f.precision)
			return (print_direct_order(f, arg, i));
		if (f.minus != 0 && i >= f.precision)
			return (print_n_direct_order(f, arg));
	}
	if (i >= f.width)
	{
		if ( i < f.precision)
			return (arg == NULL ? ft_putstr("(null)") : ft_putstr(arg));
		if (i >= f.precision && f.width < f.precision)
			return (arg == NULL ? ft_putnstr("(null)", f.precision) : ft_putnstr(arg, f.precision));
		if (f.minus == 0 && i >= f.precision && f.width >= f.precision)
			return (print_n_reverse_order(f, arg));
		if (f.minus == 1 && i >= f.precision && f.width >= f.precision)
			return (print_n_direct_order(f, arg));
	}
	return (-1);
}

int	type_s(t_field f, va_list args)
{
	char	*arg;
	int		n;
	size_t	i;

	arg = va_arg(args, char *);
	n = 0;
	if (f.minus == 0 && f.width == 0 && f.dot == 0 && f.precision == 0)
		return (arg == NULL ? ft_putstr("(null)") : ft_putstr(arg));
	if (f.minus == 0 && f.width == 0 && f.dot == 1 && f.precision == 0)
		return (n);
	if ((f.minus == 0 || f.minus == 1) && f.width == 0 && f.dot == 1 && f.precision != 0)
	{
		i = arg == NULL ? 6 : ft_strlen(arg);
		if (i >= f.precision)
			return (arg == NULL ? ft_putnstr("(null)", f.precision) : ft_putnstr(arg, f.precision));
		else
			return (arg == NULL ? ft_putnstr("(null)", i) : ft_putnstr(arg, i));
	}
	if ((f.minus == 0 || f.minus == 1) && f.dot == 1 && f.precision != 0)
	{
		i = arg == NULL ? 6 : ft_strlen(arg);
		return (pos_two(f, arg, i));
	}
	if ((f.minus == 0 || f.minus == 1) && f.width != 0 && f.dot == 1 && f.precision == 0)
		return (print_space(f.width));
	if ((f.minus == 0 || f.minus == 1) && f.width != 0 && f.dot == 0 && f.precision == 0)
	{
		i = arg == NULL ? 6 : ft_strlen(arg);
		if (i >= f.width)
			return (arg == NULL ? ft_putstr("(null)") : ft_putstr(arg));
		if (f.minus == 0)
			print_reverse_order(f, arg, i);
		else
			print_direct_order(f, arg, i);
	}
	return (n);
}
