/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:40:28 by oem               #+#    #+#             */
/*   Updated: 2020/12/05 17:31:59 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void double_format(int8_t *sign, u_int16_t *e, u_int64_t *f, va_list args)
{
    __int8_t    i;
    u_int16_t   exp;
    u_int64_t   fr;
    u_int64_t   l;
    t_value     u;

    i = 63;
    exp = 1024;
    fr = 2251799813685248;
    l = 9223372036854775808ull;
    u.d = va_arg(args, double);
    while (l)
    {
        if (i == 63)
            if ((u.i & l))
                *sign = -1;
        if (i >= 52 && i <= 62)
        {
            *e += exp * ((u.i & l) != 0 ? 1 : 0);
            exp >>= 1;
        }
        if (i >= 0 && i <= 51)
        {
            *f += fr * ((u.i & l) != 0 ? 1 : 0);
            fr >>= 1;
        }
        // (u.i & l) != 0 ? printf("1") : printf("0");
        l >>= 1;
        --i;
    }
}

int	digit_capacity(int value, int base)
{
	int i;

	i = 0;
	while (value != 0)
	{
		value = value / base;
		++i;
	}
	return (i);
}

u_int32_t *input(u_int64_t fraction, u_int32_t *s)
{
    u_int32_t i;

    i = 0;
    s = (u_int32_t *)malloc(MAXDIG * sizeof(u_int32_t));
    ft_bzero(s, sizeof(s));
    while (fraction != 0)
    {
        s[i] = fraction % BASE;
		fraction /= BASE;
        ++i;
    }
    return (s);
}

void print_array(u_int32_t *s)
{
    u_int32_t i;

    i = 0;
    while (i < MAXDIG)
    {
        printf("%d ", s[i]);
        ++i;
    }
    printf("\n");
}

u_int32_t *addition(u_int32_t *s1, u_int32_t *s2)
{
    __int8_t mind;
    u_int32_t i;
    u_int32_t *s;

    mind = 0;
    i = 0;
    s = (u_int32_t *)malloc(MAXDIG * sizeof(u_int32_t));
    while (i < MAXDIG)
    {
        if (mind == 0)
            s[i] = s1[i] + s2[i];
        else
        {
            s[i] = s1[i] + s2[i] + 1;
            mind = 0;
        }
        if (digit_capacity(s[i], BASE) == 2)
        {
            mind = 1;
            s[i] = s[i] % BASE;
        }
        ++i;
    }
    // printf("\ns=%d\n", (s1[0] + s2[0]) % 10);
    return (s);
}

u_int32_t *subtraction(u_int32_t *s1, u_int32_t *s2)
{
    __int8_t mind;
    u_int32_t i;
    u_int32_t *s;
    __int8_t tmp;

    mind = 0;
    i = 0;
    s = (u_int32_t *)malloc(MAXDIG * sizeof(u_int32_t));
    tmp = 0;
    while (i < MAXDIG)
    {
        if (mind == 0)
        {
            if (((__int32_t)s1[i] - (__int32_t)s2[i]) < 0)
            {
                tmp = s1[i] + 10 - s2[i];
                s[i] = tmp % 10;
                mind = 1;
            }
            else
                s[i] = s1[i] - s2[i];
        }
        else
        {
            if (((__int32_t)s1[i] - (__int32_t)s2[i]) < 0)
            {
                tmp = s1[i] + 10 - 1 - s2[i];
                s[i] = tmp % 10;
                mind = 1;
            }
            else
            {
                s[i] = s1[i] - s2[i] - 1;
                mind = 0;
            }
        }
        ++i;
    }
    // printf("\ns=%d\n", (s1[0] + s2[0]) % 10);
    return (s);
}

u_int32_t *offset(u_int32_t *s1, u_int32_t j)
{
    __int32_t i = MAXDIG - 1;
    while (i)
    {
        if (s1[i] == 0)
            --i;
        else
        {
            ++i;
            break;
        }
    }
    // printf("%d %d\n", i, j);
    // print_array(s1);

    u_int32_t *rr = s1 + j + i;
    u_int32_t *rl = s1 + i;
    i++;
    u_int32_t k = i + j;
    u_int32_t zero = 0;
    while (k)
    {
        if (i)
        {
            *rr = *rl;
            --i;
        }
        else
            *rr = zero;
        if (i)
             --rl;
        --k;
        if (k != 0)
            --rr;
    }
    // print_array(rr);
    return (rr);
}

u_int32_t *multiplication(u_int32_t *s1, u_int32_t *s2)
{
    u_int32_t mind;
    u_int32_t i;
    u_int32_t j;
    u_int32_t tmp;
    u_int32_t *ss;
    u_int32_t *sl;

    mind = 0;
    i = 0;
    j = 0;
    tmp = 0;
    ss = ft_memalloc(MAXDIG * sizeof(u_int32_t));
    sl = ft_memalloc(MAXDIG * sizeof(u_int32_t));
    while (j < MAXDIG)
    {
        i = 0;
        while (i < MAXDIG)
        {
            if (mind == 0)
                ss[i] = s1[i] * s2[j];
            else
            {
                ss[i] = s1[i] * s2[j] + mind;
                mind = 0;
            }
            if (digit_capacity(ss[i], BASE) == 2)
            {
                tmp = ss[i];
                ss[i] = tmp % BASE;
                mind = tmp / BASE;
            }
            ++i;
        }
        ss = offset(ss, j);
        sl = addition(ss, sl);
        ft_bzero(ss, MAXDIG * sizeof(u_int32_t));
        ++j;
    }
    // printf("\ns=%d\n", (s1[0] + s2[0]) % 10);
    return (sl);
}

u_int32_t *division(u_int32_t *s1, u_int32_t *s2)
{
    u_int32_t l1n;
    u_int32_t l2n;
    // u_int32_t j;
    // u_int32_t j;
    // u_int32_t tmp;
    // u_int32_t *ss;
    // u_int32_t *sl;

    l1n = digit_capacity(175444, BASE);
    l2n = digit_capacity(151, BASE);
    printf("\n%d %d\n", l1n, l2n);
    // mind = 0;
    // i = 0;
    // j = 0;
    // tmp = 0;
    // ss = ft_memalloc(MAXDIG * sizeof(u_int32_t));
    // sl = ft_memalloc(MAXDIG * sizeof(u_int32_t));
    // while (j < MAXDIG)
    // {
    //     i = 0;
    //     while (i < MAXDIG)
    //     {
    //         if (mind == 0)
    //             ss[i] = s1[i] * s2[j];
    //         else
    //         {
    //             ss[i] = s1[i] * s2[j] + mind;
    //             mind = 0;
    //         }
    //         if (digit_capacity(ss[i], BASE) == 2)
    //         {
    //             tmp = ss[i];
    //             ss[i] = tmp % BASE;
    //             mind = tmp / BASE;
    //         }
    //         ++i;
    //     }
    //     ss = offset(ss, j);
    //     sl = addition(ss, sl);
    //     ft_bzero(ss, MAXDIG * sizeof(u_int32_t));
    //     ++j;
    // }
    // printf("\ns=%d\n", (s1[0] + s2[0]) % 10);
    printf("%d", s2[0]);
    return (s1);
}

int	type_f(t_field f, va_list args)
{
    __int8_t sign = 1;
    u_int16_t exponent = 0;
    u_int32_t n = 0;
    u_int64_t fraction = 0;
    // u_int64_t a = 4503599627370496; //2 ^ 52
    u_int32_t *s1;
    u_int32_t *s2;
    u_int32_t *s;

    s1 = NULL;
    s2 = NULL;
    double_format(&sign, &exponent, &fraction, args);
    s1 = input(175444, s1);
    print_array(s1);

    s2 = input(151, s2);
    print_array(s2);

    // s = addition(s1, s2);
    // print_array(s);

    // s = subtraction(s1, s2);
    // print_array(s);

    // s = multiplication(s1, s2);
    // print_array(s);

    s = division(s1, s2);
    print_array(s);

    // printf("\n");
    // int q = 15;
    // long long ll = 1024;
    // while (ll)
    // {

    //     (q & ll) != 0 ? printf("1") : printf("0");
    //     ll >>= 1;
    // }
    // 0	10000000010	1000010111011001101001011011101100101101101010000111
    // 0   10000000010 1000010111011001101001011011101100101101101010000111

    // printf("\nsign   = %d\n", sign);
    // printf("exp    = %d\n", exponent);
    // printf("fract  = %ld\n", fraction);
    // printf("2 ^ 52 = %ld\n", a);





    printf("\n%zu\n", f.width);
    // printf("%.20f\n", value.d);
    return (n);
}
