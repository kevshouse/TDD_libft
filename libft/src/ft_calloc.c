
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keanders <keanders@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:28:49 by keanders          #+#    #+#             */
/*   Updated: 2025/01/02 18:01:35 by keanders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <limits.h>
#include <stddef.h>

void* ft_calloc(size_t count, size_t size)
{
    size_t size_total;
    void* ptr;

    if (size && count > SIZE_MAX / size)
        return (NULL);
    size_total = size * count;
    if (size_total == 0)
        size_total = 1;
    ptr = malloc(size_total);
    if (ptr == NULL)
        return (ptr);
    ft_bzero(ptr, size_total);
    return (ptr);
}
