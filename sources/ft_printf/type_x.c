/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 22:45:20 by oem               #+#    #+#             */
/*   Updated: 2020/10/21 23:00:53 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	type_x(va_list args, char **s)
{
	char *str;
	int n;

	n = va_arg(args, int);
	str = ft_lltoa_base(n, 16);
	if (**s == 'x')
		return (ft_putstr(ft_strlowcase(str)));
	return (ft_putstr(str));
}
