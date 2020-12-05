/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 20:00:52 by calpha            #+#    #+#             */
/*   Updated: 2020/12/05 20:03:19 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_space(int i)
{
	int n;

	n = 0;
	while (i--)
		n += write(1, " ", 1);
	return (n);
}

int	print_direct_order(t_field f, char *arg, int i)
{
	int n;

	n = 0;
	n += arg == NULL ? ft_putstr("(null)") : ft_putstr(arg);
	n += print_space(f.width -= i);
	return (n);
}

int	print_reverse_order(t_field f, char *arg, int i)
{
	int n;

	n = 0;
	n += print_space(f.width -= i);
	n += arg == NULL ? ft_putstr("(null)") : ft_putstr(arg);
	return (n);
}

int	print_n_direct_order(t_field f, char *arg)
{
	int n;

	n = 0;
	if (arg == NULL)
		n += ft_putnstr("(null)", f.precision);
	else
		n += ft_putnstr(arg, f.precision);
	n += print_space(f.width -= f.precision);
	return (n);
}

int	print_n_reverse_order(t_field f, char *arg)
{
	int n;

	n = 0;
	n += print_space(f.width -= f.precision);
	if (arg == NULL)
		n += ft_putnstr("(null)", f.precision);
	else
		n += ft_putnstr(arg, f.precision);
	return (n);
}
