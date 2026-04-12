/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin-anderson <kevin-anderson@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 23:50:23 by kevin-ander       #+#    #+#             */
/*   Updated: 2026/04/11 20:53:43 by kevin-ander      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Internal helper to count words in a string based on a delimiter.
 * @param s The string to evaluate.
 * @param c The delimiter character.
 * @return The number of words found.
 * @internal
 */
static size_t count_words(char const *s, char c)
{
	size_t count;
	int in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

/**
 * @brief Internal helper to free the array if a malloc failure occurs.
 * @param arr The array of strings.
 * @param i The current index to free back from.
 * @return Always returns NULL.
 * @internal
 */
static char **free_array(char **arr, size_t i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
	return (NULL);
}

/**
 * @brief Splits a string into an array of strings using 'c' as a delimiter.
 * @param s The string to split.
 * @param c The delimiter character.
 * @return A NULL-terminated array of strings, or NULL on allocation failure.
 * @todo Refactor the double-malloc logic to potentially reduce string traversals.
 */
char **ft_split(char const *s, char c)
{
	char **result;
	size_t start;
	size_t end;
	size_t i;
	size_t words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	start = 0;
	while (i < words)
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		result[i] = malloc((end - start) + 1);
		if (!result[i])
			return (free_array(result, i));
		ft_memcpy(result[i], s + start, end - start);
		result[i][end - start] = '\0';
		start = end;
		i++;
	}
	result[i] = NULL;
	return (result);
}
