/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin-anderson <kevin-anderson@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:55:54 by keanders          #+#    #+#             */
/*   Updated: 2026/04/11 18:54:31 by kevin-ander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Outputs a character to the given file descriptor.
 * @param c The character to output.
 * @param fd The file descriptor to write to.
 */
void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
