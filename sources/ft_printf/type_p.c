/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 02:13:46 by oem               #+#    #+#             */
/*   Updated: 2020/11/01 02:20:00 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	type_p(t_field f, va_list args)
{
	void *arg;
	int n;

	n = 0;
	arg = va_arg(args, void *);
	printf("%p", arg);
	printf("%d", f.minus);
	return (n);
}