/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 13:40:19 by calpha            #+#    #+#             */
/*   Updated: 2020/12/05 14:17:06 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	type_pc(t_field f)
{
	int n;

	n = 0;
	if ((f.minus == 0 || f.minus == 1) && f.width == 0)
		return (ft_putchar('%'));
	else if (f.minus == 0 && f.width != 0)
	{
		f.width--;
		while (f.width--)
			n += f.zero == 0 ? write(1, " ", 1) : write(1, "0", 1);
		n += ft_putchar('%');
	}
	else if (f.minus == 1 && f.width != 0)
	{
		n += ft_putchar('%');
		f.width--;
		while (f.width--)
			n += write(1, " ", 1);
	}
	return (n);
}
