/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:38:09 by madumerg          #+#    #+#             */
/*   Updated: 2023/11/17 11:32:41 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_conversions(const char *str, ...)
{
    va_list args;
    int     i;
    int     print;

    va_start(args, str);
    print = 0;
    if (str == 'c')
        print += ft_putchar(va_arg(args, str[i]));
    else if (str == 's')
        print += ft_putstr(va_arg(args, str[i]));
    else if (str == 'p')
        print += va_arg(args, str[i]);
    else if (str == 'd')
        print += va_arg(args, str[i]);
    else if (str == 'i')
        print += va_arg(args, str[i]);
    else if (str == 'u')
        print += va_arg(args, str[i]);
    else if (str == 'x')
        print += va_arg(args, str[i]);
    else if (str == 'X')
        print += va_arg(args, str[i]);
    else if (str == '%')
        print += va_arg(args, str[i]);
	return (0);
}

int ft_printf(const char *str, ...)
{
    va_list args;
    int     print;
    int     i;
    
    if (!str)
        return (NULL);
    va_start(args, str);
    i = 0;
    print = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            print += ft_conversions(args, str[i]);
            i++;
        }
    }
    va_end(args);
    return (print);
}
