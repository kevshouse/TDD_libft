/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin-anderson <kevin-anderson@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 23:49:47 by kevin-ander       #+#    #+#             */
/*   Updated: 2025/05/17 12:15:17 by kevin-ander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int handle_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	return (write(1, &c, 1));
}

int handle_str(va_list args)
{
	char *str;
	int len;

	str = va_arg(args, char *);
	if (!str)
		return (write(1, "(null)", 6));
	len = 0;
	while (str[len])
		len++;
	return (write(1, str, len));
}
