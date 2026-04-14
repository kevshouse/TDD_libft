#include <criterion/criterion.h>
#include "../includes/libft.h"
#include <stdlib.h>

/**
 * @addtogroup UnitTests
 * @{
 */

/** @brief The actual system malloc, provided by the linker wrap flag. */
extern void *__real_malloc(size_t size);

/** @brief Counter used to trigger a failure after N allocations. */
static int g_malloc_fail_after = -1;

/** @brief Flag to monitor if malloc was called. */
static int g_monitor = 0;

/**
 * @brief Wrapper for malloc that can be told to fail after N calls.
 * * This function intercepts calls to malloc via the linker flag -Wl,--wrap=malloc[cite: 7].
 * @param size The number of bytes to allocate.
 * @return A pointer to the allocated memory, or NULL if triggered to fail.
 */
void *__wrap_malloc(size_t size)
{
	if (g_monitor)
	{
		if (g_malloc_fail_after == 0)
		{
			g_malloc_fail_after = -1;
			g_monitor = 0;
			return (NULL);
		}
		if (g_malloc_fail_after > 0)
			g_malloc_fail_after--;
	}
	return __real_malloc(size);
}

/**
 * @test Ensures ft_split returns NULL and cleans up memory on malloc failure.
 */
Test(ft_split, malloc_failure_at_second_word)
{
	char **res;
	char *input = "hello world libft";
	char sep = ' ';

	/* * In ft_split:
	 * 1st malloc: The array of pointers (size 4)
	 * 2nd malloc: "hello"
	 * 3rd malloc: "world" <-- We want to fail here
	 */
	g_malloc_fail_after = 2; 
	g_monitor = 1;
	
	res = ft_split(input, sep);
	
	g_monitor = 0;

	/* Ensure the function returns NULL on failure */
	cr_assert_null(res, "ft_split should return NULL if a word allocation fails");
	
	/* * If memory is leaked here, the 'make valgrind' rule in CI will 
	 * catch it and fail the build because of the --error-exitcode=1 flag.
	 */
}

/** @} */