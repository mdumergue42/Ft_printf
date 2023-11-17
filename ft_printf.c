/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:38:09 by madumerg          #+#    #+#             */
/*   Updated: 2023/11/17 16:15:35 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversions(va_list args, char c)
{
	int	print;

	print = 0;
	if (c == 'c')
		print += ft_putchar(va_arg(args, int));
	else if (c == 's')
		print += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		print += ft_print_ptr(va_arg(args, void *));
	else if (c == 'd')
		print += ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		print += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		print += ft_putnbr_uns_int(va_arg(args, unsigned int));
	else if (c == 'x')
		print += ft_putnbr_hexa_low(va_arg(args, unsigned int));
	else if (c == 'X')
		print += ft_putnbr_hexa_upp(va_arg(args, unsigned int));
	else if (c == '%')
		print += ft_putchar('%');
	return (print);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print;
	int		i;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	print = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			print += ft_conversions(args, str[i + 1]);
			i++;
		}
		else
			print += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (print);
}
