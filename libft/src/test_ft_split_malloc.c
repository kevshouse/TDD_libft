#include <criterion/criterion.h>
#include "../includes/libft.h"
#include <stdlib.h>

/* Prototypes for linker wrapping */
void *__real_malloc(size_t size);

/* Control variables for the mock */
static int g_malloc_fail_after = -1;
static int g_monitor = 0;

/**
 * @brief Wrapper for malloc that can be told to fail after N calls.
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

Test(ft_split, malloc_failure_at_second_word)
{
	char **res;
	char *input = "hello world libft";
	char sep = ' ';

	/* 
	 * In ft_split:
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
	
	/* 
	 * If memory is leaked here, the 'make valgrind' rule in CI will 
	 * catch it and fail the build because of the --error-exitcode=1 flag.
	 */
}