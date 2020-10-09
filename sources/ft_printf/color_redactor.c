/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_redactor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:37:41 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/10/09 20:10:39 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BLACK		"\033[0;30m"
#define RED			"\033[0;31m"
#define BOLD_RED	"\033[1;31m"
#define GREEN		"\033[0;32m"
#define BOLD_GREEN	"\033[1;32m"
#define YELLOW		"\033[0;33m"
#define BOLD_YELLOW	"\033[1;33m"
#define BLUE		"\033[0;34m"
#define BOLD_BLUE	"\033[1;34m"
#define MAGENTA		"\033[0;35m"
#define BLD_MAGENTA	"\033[1;35m"
#define CYAN		"\033[0;36m"
#define BOLD_CYAN	"\033[1;36m"
#define EOC			"\033[0m"

static int	color_compare2(char *color)
{
	int i;

	i = 0;
	if (!ft_strcmp("magenta", color))
		i = ft_putstr_int(MAGENTA);
	if (!ft_strcmp("bold_magenta", color))
		i = ft_putstr_int(BLD_MAGENTA);
	else if (!ft_strcmp("cyan", color))
		i = ft_putstr_int(CYAN);
	else if (!ft_strcmp("bold_cyan", color))
		i = ft_putstr_int(BOLD_CYAN);
	else if (!ft_strcmp("black", color))
		i = ft_putstr_int(BLACK);
	else if (!ft_strcmp("eoc", color))
		i = ft_putstr_int(EOC);
	return (i);
}

static int	color_compare(char *color)
{
	int i;

	if (!ft_strcmp("red", color))
		i = ft_putstr_int(RED);
	else if (!ft_strcmp("bold_red", color))
		i = ft_putstr_int(BOLD_RED);
	else if (!ft_strcmp("green", color))
		i = ft_putstr_int(GREEN);
	else if (!ft_strcmp("bold_green", color))
		i = ft_putstr_int(BOLD_GREEN);
	else if (!ft_strcmp("yellow", color))
		i = ft_putstr_int(YELLOW);
	else if (!ft_strcmp("bold_yellow", color))
		i = ft_putstr_int(BOLD_YELLOW);
	else if (!ft_strcmp("blue", color))
		i = ft_putstr_int(BLUE);
	else if (!ft_strcmp("bold_blue", color))
		i = ft_putstr_int(BOLD_BLUE);
	else
		i = color_compare2(color);
	return (i);
}

int			color_redactor(const char *str)
{
	char	*color;
	char	*brace;
	int		i;

	if (!(brace = ft_strchr(str++, '}')))
		return (0);
	color = ft_strsub(str, 0, brace - str);
	i = color_compare(color);
	return (i) ? ft_strlen(color) + 2 : 0;
}
