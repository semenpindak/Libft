/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_procent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:47:58 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/10/09 20:10:39 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_init_procent(char *str, int i, va_list args, t_flag *flags)
{
	int		len;

	len = 0;
	if (ft_strchr(str, 'f') != 0)
		flags->precision = 100;
	len += ft_analazer_flags(str, i, flags, args);
	return (len);
}
