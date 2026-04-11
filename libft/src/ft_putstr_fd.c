/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin-anderson <kevin-anderson@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:49:21 by keanders          #+#    #+#             */
/*   Updated: 2026/04/11 18:54:27 by kevin-ander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Outputs a string to the given file descriptor.
 * @param str The string to output.
 * @param fd The file descriptor to write to.
 */
void ft_putstr_fd(char *str, int fd)
{
	size_t len;

	if (!str)
		return ;
	len = 0;
	while (str[len])
		len++;
	write(fd, str, len);
}
