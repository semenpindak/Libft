/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 22:45:20 by oem               #+#    #+#             */
/*   Updated: 2020/11/26 15:18:31 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	type_x(t_field f, va_list args)
{
	char *str;
	int n;

	n = va_arg(args, int);
	str = ft_lltoa_base(n, 16);
	printf("%d\n", f.zero = 0); //ря
	return (ft_putstr(ft_strlowcase(str)));
}
