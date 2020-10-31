/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:47:19 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/10/31 14:22:58 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int type_field_selection(t_field f, va_list args)
{
	int n;

	n = 0;
	// if (format.type == '%')
	// 	n = ft_putchar('%');
	// if (format.type == 'd' || format.type == 'i')
	// 	n = type_di(args);
	// if (format.type == 'u')
	// 	n = type_u(args);
	// if (*s == 'f' || 'F')
	// 	;
	// if (*s == 'e' || 'E')
	// 	;
	// if (*s == 'g' || 'G')
	// 	;
	// if (format.type == 'x' || format.type == 'X')
	// 	n = type_x(args, s);
	// if (format.type == 'o')
	// 	n = type_o(args);
	if (f.type == 's')
		n = type_s(f, args);
	// if (format.type == 'c')
	// 	n = ft_putchar(va_arg(args, int));
	// if (*s == 'p')
	// 	;
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
	int n;

	n = 0;
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
	// printf("%d", format.minus);
	// printf("%d", format.plus);
	// printf("%d", format.space);
	// printf("%d", format.sharp);
	// printf("%d", format.zero);
	// printf("%d", format.width);
	// printf("%d", format.point);
	// printf("%d", format.precision);
	// printf("%c%c", format.size[0], format.size[1]);
	// printf("%c", format.type);

	type_field_selection(f, args);
	return (n);
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

