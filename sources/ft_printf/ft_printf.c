/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:47:19 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/12/05 13:43:40 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int type_field_selection(t_field f, va_list args)
{
	int n;

	n = 0;
	if (f.type == '%')
		n = type_pc(f);
	if (f.type == 'd' || f.type == 'i')
		n = type_di(f, args);
	// if (format.type == 'u')
	// 	n = type_u(args);
	if (f.type == 'f' || f.type == 'F')
		n = type_f(f, args);
	// if (*s == 'e' || 'E')
	// 	;
	// if (*s == 'g' || 'G')
	// 	;
	// if (f.type == 'x')
	// 	n = type_x(f, args);
	// if (f.type == 'X')
	// 	n = type_x(f, args);
	// if (format.type == 'o')
	// 	n = type_o(args);
	if (f.type == 's')
		n = type_s(f, args);
	if (f.type == 'c')
		n = type_c(f, args);
	if (f.type == 'p')
		n = type_p(f, args);
	// if (*s == 'a' || 'A')
	// 	;
	// if (*s == 'n')
	// 	;
	return (n);
}

int type_field(char c)
{
	return (c == '%' || c == 'd' || c == 'i' || c == 'u' || c == 'f' || c == 'F' ||
			c == 'e' || c == 'E' || c == 'g' || c == 'G' || c == 'x' || c == 'X' ||
			c == 'o' || c == 's' || c == 'c' || c == 'p' || c == 'a' || c == 'A' || c == 'n');
}

int number(const char **s)
{
	int rezult;

	rezult = 0;
	while (**s >= '0' && **s <= '9')
	{
		rezult = rezult * 10 + (**s - '0');
		(*s)++;
	}
	(*s)--;
	return (rezult);
}

int define_format_specifier(const char **s, va_list args)
{
	t_field f;
	ft_bzero(&f, sizeof(t_field));
	while (type_field(**s) == 0)
	{
		if (**s == '-')
			f.minus = 1;
		if (**s == '+')
			f.plus = 1;
		if (**s == ' ')
			f.space = 1;
		if (**s == '#')
			f.sharp = 1;
		if (**s == '0')
			f.zero = 1;
		if (NUMBER(**s) == 1)
			f.width = number(s);
		if (**s == '.')
		{
			f.dot = 1;
			(*s)++;
			if (NUMBER(**s) == 1)
				f.precision = number(s);
			else
				(*s)--;
		}
		if (SIZE(**s) == 1)
		{
			f.size[0] = **s;
			(*s)++;
			if (SIZE(**s) == 1)
				f.size[1] = **s;
			else
				(*s)--;
		}
		(*s)++;
	}
	f.type = **s;
	// printf("%d", f.minus);
	// printf("%d", f.plus);
	// printf("%d", f.space);
	// printf("%d", f.sharp);
	// printf("%d", f.zero);
	// printf("%d", f.width);
	// printf("%d", f.point);
	// printf("%ld", f.precision);
	// printf("%s", f.size);
	// printf("%c", f.type);

	return (type_field_selection(f, args));
}

int				ft_printf(const char *format, ...)
{
	va_list	args;
	const char	*s;
	int		n;

	va_start(args, format);
	s = (char *)format;
	n = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			n += define_format_specifier(&s, args);
			// n += type_field(&s, args);
		}
		else
			n += write(1, s, 1);
		s++;
		// if (*s == 'd')
		// {
		// 	int i = va_arg(args, int);
		// 	printf( "%d\n", i ) ;
		// }
		// else if (*s == 'c')
		// {
		// 	int c = va_arg(args, int);
		// 	printf( "%c\n", (char)c ) ;
		// }
		// else if (*s == 'f')
		// {
		// 	double d = va_arg(args, double);
		// 	printf( "%f\n", d) ;
		// }
		// // n += write(1, s++, 1);
		// n += printf("%c", *s);
	}
	va_end(args);
	return (n);
}

