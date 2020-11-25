/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 02:13:46 by oem               #+#    #+#             */
/*   Updated: 2020/11/25 19:31:10 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char hex_digit(int n)
{
	if (n >= 0 && n < 10)
		return (n + '0');
	else
		return (n - 10 + 'a');
}

char *print_address_hex(void *arg, char *s)
{
	unsigned long p;
	int i;
	int j;

	p = (unsigned long)arg;
	i = (sizeof(p) * 8) - 20;
	s = ft_strnew(14);
	s[0] = '0';
	s[1] = 'x';
	j = 2;
	while (i >= 0)
	{
		s[j] = hex_digit((p >> i) & 0xf);
		i -= 4;
		j++;
	}
	return (s);
}

int	type_p(t_field f, va_list args)
{
	void *arg;
	char *s;
	int n;
	int i;

	arg = va_arg(args, void *);
	s = NULL;
	s = print_address_hex(arg, s);
	if (f.minus == 0 && f.width != 0)
	{
		i = ft_strlen(s);
		if (i >= f.width)
			return (ft_putstr(s));
		f.width -= i;
		while (f.width--)
			n += write(1, " ", 1);
		n += ft_putstr(s);
	}
	if (f.minus == 1 && f.width != 0)
	{
		i = ft_strlen(s);
		if (i >= f.width)
			return (ft_putstr(s));
		else
		{
			n += ft_putstr(s);
			f.width -= i;
			while (f.width--)
				n += write(1, " ", 1);
		}
	}
	return (n);
}
