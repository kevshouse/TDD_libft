#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include "ft_printf.h"

/**
 * @brief Formatted output conversion.
 * @param format The format string.
 * @param ... Variadic arguments.
 * @return The number of characters printed.
 */
int     ft_printf(const char *format, ...);

/**
 * @brief Returns the maximum of two size_t values.
 * @param ref First value.
 * @param numb Second value.
 * @return The larger of the two values.
 */
int     ft_max(size_t ref, size_t numb);

/**
 * @brief Converts the initial portion of a string to a long integer.
 * @param str The string to convert.
 * @return The converted value.
 */
long	ft_atoi(const char *str);

/**
 * @brief Converts a string to a long integer with overflow protection.
 * @param str The string to convert.
 * @return The converted long integer, or LONG_MAX/LONG_MIN on overflow.
 */
long	ft_atol(const char *str);

/**
 * @brief Computes the absolute value of an integer.
 * @param n The integer.
 * @return The absolute value.
 */
int     ft_abs(int n);

/**
 * @brief Splits a string into an array of strings using a delimiter.
 * @param s The string to split.
 * @param c The delimiter character.
 * @return An array of new strings, NULL-terminated.
 */
char	**ft_split(char const *s, char c);

/**
 * @brief Copies n bytes from memory area src to memory area dst.
 * @param dst Destination pointer.
 * @param src Source pointer.
 * @param n Number of bytes to copy.
 * @return A pointer to dst.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n);

/**
 * @brief Checks for a digit (0 through 9).
 * @param c Character to check.
 * @return 1 if digit, 0 otherwise.
 */
int		ft_isdigit(int c);

/**
 * @brief Outputs a character to the given file descriptor.
 * @param c Character to output.
 * @param fd File descriptor.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs a string to the given file descriptor.
 * @param str String to output.
 * @param fd File descriptor.
 */
void	ft_putstr_fd(char *str, int fd);

/**
 * @brief Outputs a string to a file descriptor followed by a newline.
 * @param s String to output.
 * @param fd File descriptor.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Swaps the values of two integers.
 * @param a Pointer to first integer.
 * @param b Pointer to second integer.
 */
void	ft_swap(int *a, int *b);

/**
 * @brief Frees an array of strings (typically from ft_split).
 * @param split The NULL-terminated array to free.
 */
void	ft_free_split(char **split);

/**
 * @brief Validates if a string represents a valid integer.
 * @param str The string to check.
 * @return 1 if valid, 0 otherwise.
 */
int		ft_isvalidnum(const char *str);

/**
 * @brief Sets the first n bytes of the area pointed to by s to zero.
 * @param s Pointer to memory.
 * @param n Number of bytes.
 */
void    ft_bzero(void* s, size_t n);

/**
 * @brief Allocates memory for an array and initializes it to zero.
 * @param count Number of elements.
 * @param size Size of each element.
 * @return Pointer to allocated memory.
 */
void    *ft_calloc(size_t count, size_t size);

#endif
