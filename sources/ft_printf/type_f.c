/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:40:28 by oem               #+#    #+#             */
/*   Updated: 2020/11/29 23:58:37 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	type_f(t_field f, va_list args)
{
    int n = 0;
    union 
    {
        int64_t int_64;
        double d;
    } value;
    value.d = va_arg(args, double);

    
    

    
    printf("%d\n", f.width);
    printf("%.20f\n", value.d);
    return (n);
}