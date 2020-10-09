/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_x_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:56:48 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/10/09 20:10:39 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_x_x_seven(int len_str, char *str, t_flag *flags)
{
	int len;
	int p;

	len = 0;
	if (flags->space)
		len += ft_write(flags->space);
	if (flags->hash)
	{
		len += ft_write('0');
		len += ft_write(flags->spec);
	}
	p = 0;
	while (str[p])
		len += ft_write(str[p++]);
	p = 0;
	while (p < flags->width - len_str -
			(flags->space != 0) - check_hesh_x_x(flags))
	{
		len += ft_write(' ');
		p++;
	}
	free(str);
	return (len);
}

int		ft_x_x_six(int len_str, char *str, t_flag *flags)
{
	int len;
	int p;

	len = 0;
	if (flags->space)
		len += ft_write(flags->space);
	if (flags->hash)
	{
		len += ft_write('0');
		len += ft_write(flags->spec);
	}
	p = 0;
	while (p < flags->width - len_str -
	(flags->space != 0) - check_hesh_x_x(flags))
	{
		len += ft_write('0');
		p++;
	}
	p = 0;
	while (str[p])
		len += ft_write(str[p++]);
	free(str);
	return (len);
}

int		ft_x_x_five(int len_str, char *str, t_flag *flags)
{
	int p;
	int len;

	len = 0;
	p = 0;
	while (p < flags->width - len_str -
	check_flags(flags) - check_hesh_x_x(flags))
	{
		len += ft_write(' ');
		p++;
	}
	if (flags->space)
		len += ft_write(flags->space);
	if (flags->hash)
	{
		len += ft_write('0');
		len += ft_write(flags->spec);
	}
	p = 0;
	while (str[p])
		len += ft_write(str[p++]);
	free(str);
	return (len);
}

int		ft_x_x_four(int len_str, char *str, t_flag *flags)
{
	int len;
	int p;

	len = 0;
	if (flags->space)
		len += ft_write(flags->space);
	if (flags->hash)
	{
		len += ft_write('0');
		len += ft_write(flags->spec);
	}
	p = 0;
	while (str[p])
		len += ft_write(str[p++]);
	p = 0;
	while (p < flags->width - len_str -
	(flags->space != 0) - check_hesh_x_x(flags))
	{
		len += ft_write(' ');
		p++;
	}
	free(str);
	return (len);
}

int		ft_x_x_three(int len_str, char *str, t_flag *flags)
{
	int len;
	int p;

	p = 0;
	len = 0;
	while (p < flags->width - len_str -
	(flags->space != 0) - check_hesh_x_x(flags))
	{
		len += ft_write(' ');
		p++;
	}
	if (flags->space)
		len += ft_write(flags->space);
	if (flags->hash)
	{
		len += ft_write('0');
		len += ft_write(flags->spec);
	}
	p = 0;
	while (str[p])
		len += ft_write(str[p++]);
	free(str);
	return (len);
}
