/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:51:23 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/10/09 20:14:41 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			check_num(char i)
{
	if (i > '0' && i <= '9')
		return (1);
	else
		return (0);
}

size_t		ft_atoi_pres(const char *s, int i)
{
	int		sign;
	int		res;

	res = 0;
	while (check_num(s[i]) != 1)
		i++;
	while ((s[i] > 8 && s[i] < 20) || s[i] == ' ')
		i++;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while ((s[i] >= '0' && s[i] <= '9') && s[i] != '\0')
		res = res * 10 + (s[i++] - '0');
	return (res * sign);
}
