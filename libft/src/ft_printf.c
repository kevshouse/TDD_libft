/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin-anderson <kevin-anderson@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 23:50:37 by kevin-ander       #+#    #+#             */
/*   Updated: 2026/04/11 18:52:57 by kevin-ander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @internal
 */
static int parse_format(const char *format, va_list args)
{
	int count;

	count = 0;
	if (*format == 'c')
		count += handle_char(args);
	else if (*format == 's')
		count += handle_str(args);
	else if (*format == 'd' || *format == 'i')
		count += handle_int(args);
	else if (*format == '%')
		count += write(1, "%", 1);
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int count;
	int i;

	va_start(args, format);
	count = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
			count += parse_format(&format[++i], args);
		else
			count += write(1, &format[i], 1);
	}
	va_end(args);
	return (count);
}
