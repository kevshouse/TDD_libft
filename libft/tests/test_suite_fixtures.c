#include <criterion/criterion.h>
#include "../includes/libft.h"

static int *g_shared_array;
static size_t g_size = 100;

void global_setup(void)
{
	g_shared_array = malloc(sizeof(int) * g_size);
	for (size_t i = 0; i < g_size; i++)
		g_shared_array[i] = i;
}

void global_teardown(void)
{
	free(g_shared_array);
}

/**
 * All tests in 'shared_data_suite' will now automatically 
 * call global_setup before and global_teardown after execution.
 */
TestSuite(shared_data_suite, .init = global_setup, .fini = global_teardown);

Test(shared_data_suite, test_first_element)
{
	cr_assert_eq(g_shared_array[0], 0);
}

Test(shared_data_suite, test_last_element)
{
	cr_assert_eq(g_shared_array[g_size - 1], 99);
}