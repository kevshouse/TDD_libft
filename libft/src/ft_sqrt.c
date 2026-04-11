/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin-anderson <kevin-anderson@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 23:49:25 by kevin-ander       #+#    #+#             */
/*   Updated: 2025/05/16 23:49:29 by kevin-ander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int ft_sqrt(int num)
{
	int root;

	if (num <= 0)
		return (0);
	root = 1;
	while (root * root <= num)
	{
		if (root * root == num)
			return (root);
		root++;
	}
	return (root - 1);
}