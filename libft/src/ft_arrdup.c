/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin-anderson <kevin-anderson@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 00:55:43 by kevin-ander       #+#    #+#             */
/*   Updated: 2026/04/11 18:54:36 by kevin-ander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Creates a duplicate of an integer array.
 * @param src The source array.
 * @param size The number of elements to copy.
 * @return A pointer to the new array, or NULL on failure.
 */
int *ft_arrdup(const int *src, int size)
{
	int *dst;
	int i;

	if (!src || size <= 0)
		return (NULL);
	dst = malloc(sizeof(int) * size);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
