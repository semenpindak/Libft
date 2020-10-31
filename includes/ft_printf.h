/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:54:54 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/10/31 14:22:48 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define NUMBER(c) (c >= '0' && c <= '9')
# define SIZE(c) (c == 'l' || c == 'h' || c == 'j' || c == 'z' || c == 'L')

typedef struct		s_field
{
	int				minus;
	int				plus;
	int				space;
	int				sharp;
	int				zero;
	int				width;
	int				dot;
	size_t			precision;
	char			size[2];
	char			type;
}					t_field;

int					ft_printf(const char *format, ...);

int					type_di(va_list args);
int					type_u(va_list args);
int					type_x(va_list args, char **s);
int					type_o(va_list args);
int					type_s(t_field format, va_list args);
#endif
