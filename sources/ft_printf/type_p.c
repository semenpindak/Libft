/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 02:13:46 by oem               #+#    #+#             */
/*   Updated: 2020/12/05 17:32:25 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	type_p(t_field f, va_list args)
{
	char *s;
	char *s1;
	unsigned long p;
	int n;
	size_t i;

	p = (unsigned long)va_arg(args, void *);
	s1 = ft_strlowcase(ft_lltoa_base(p, 16));
	s = ft_strjoin("0x", s1);
	free(s1);
	if (f.minus == 0 && f.width == 0)
		n = ft_putstr(s);
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
	free(s);
	return (n);
}
