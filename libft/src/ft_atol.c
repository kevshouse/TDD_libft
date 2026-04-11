/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keanders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:04:17 by keanders          #+#    #+#             */
/*   Updated: 2024/12/20 13:04:25 by keanders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long ft_atol(const char *str)
{
	long result = 0;
	int sign = 1;
	int i = 0;

	// Skip whitespace
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;

	// Handle sign
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	// Convert digits
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign == 1 &&
			(result > LONG_MAX / 10 || (result == LONG_MAX / 10 && (str[i] - '0') > LONG_MAX % 10)))
			return (LONG_MAX);
		if (sign == -1 && (result * sign < LONG_MIN / 10 ||
						   (result * sign == LONG_MIN / 10 && (str[i] - '0') > -(LONG_MIN % 10))))
			return (LONG_MIN);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
