/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin-anderson <kevin-anderson@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 23:49:38 by kevin-ander       #+#    #+#             */
/*   Updated: 2025/05/16 23:49:39 by kevin-ander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int ft_putnbr(int n)
{
	int count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += write(1, &"0123456789"[n % 10], 1);
	return (count);
}

int handle_int(va_list args)
{
	int n;

	n = va_arg(args, int);
	return (ft_putnbr(n));
}
