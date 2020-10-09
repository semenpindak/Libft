/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 23:20:15 by calpha            #+#    #+#             */
/*   Updated: 2019/10/04 18:13:00 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (n == 0)
		return (1);
	if (s1 && s2)
	{
		while (*s1 - *s2 == 0 && n--)
		{
			if ((*s1 - *s2 == 0 && n == 0) && *s1 - *s2 == '\0')
				return (1);
			s1++;
			s2++;
		}
		return (0);
	}
	return (0);
}