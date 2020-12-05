/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:54:54 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/12/05 20:05:20 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define NUMBER(c) (c >= '0' && c <= '9')
# define SIZE(c) (c == 'l' || c == 'h' || c == 'j' || c == 'z' || c == 'L')
# define MAXDIG 50
# define BASE 10

typedef struct		s_field
{
	//flags
	int				minus;
	int				plus;
	int				space;
	int				sharp;
	int				zero;
	//widht
	size_t			width;
	//pr
	int				dot;
	size_t			precision;
	//size
	char			size[3];
	//type
	char			type;
}					t_field;

typedef union		u_value
{
	int64_t			i;
	double			d;
}					t_value;

int					ft_printf(const char *format, ...);

int					type_pc(t_field f);
int					type_di(t_field f, va_list args);
int					type_u(va_list args);
int					type_f(t_field f, va_list args);
int					type_x(t_field f, va_list args);
int					type_o(va_list args);
int					type_s(t_field format, va_list args);
int					type_c(t_field f, va_list args);
int					type_p(t_field f, va_list args);

int					print_space(int i);
int					print_direct_order(t_field f, char *arg, int i);
int					print_reverse_order(t_field f, char *arg, int i);
int					print_n_direct_order(t_field f, char *arg);
int					print_n_reverse_order(t_field f, char *arg);

#endif
