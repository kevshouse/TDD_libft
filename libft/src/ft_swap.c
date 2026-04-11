/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin-anderson <kevin-anderson@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 00:40:26 by kevin-ander       #+#    #+#             */
/*   Updated: 2026/04/11 18:53:02 by kevin-ander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void ft_swap(int *a, int *b)
{
	int temp;

	if (!a || !b)
		return;
	temp = *a;
	*a = *b;
	*b = temp;
}