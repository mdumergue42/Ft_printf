/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:33:42 by madumerg          #+#    #+#             */
/*   Updated: 2023/11/17 15:22:06 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_putchar('-');
		i += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
	{
		i += ft_putchar(n + '0');
		return (i);
	}
	else if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	return (i);
}
