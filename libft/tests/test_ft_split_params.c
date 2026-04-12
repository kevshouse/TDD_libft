#include <criterion/criterion.h>
#include "../includes/libft.h"

/**
 * @addtogroup UnitTests
 * @{
 */

/**
 * @brief Structure to hold parameters for ft_split tests.
 */
struct ft_split_test_params {
	const char	*input;
	char		delimiter;
	const char	*expected[10]; // Array of expected strings, NULL-terminated
};

/**
 * @brief Tests ft_split against multiple edge cases in a single test block.
 * This avoids Criterion's parameterized test shared memory bugs with pointers.
 */
Test(ft_split, edge_cases)
{
	struct ft_split_test_params params[] = {
		{"hello world", ' ', {"hello", "world", NULL}},
		{"   lorem   ipsum  ", ' ', {"lorem", "ipsum", NULL}},
		{"split", 'z', {"split", NULL}},
		{"", ' ', {NULL}},
		{"   ", ' ', {NULL}},
		{"first:second:third", ':', {"first", "second", "third", NULL}},
		{"--a--b--c--", '-', {"a", "b", "c", NULL}}
	};

	size_t num_params = sizeof(params) / sizeof(struct ft_split_test_params);

	for (size_t k = 0; k < num_params; k++)
	{
		struct ft_split_test_params *p = &params[k];
		char **result = ft_split(p->input, p->delimiter);

		/* Ensure we actually got an array back */
		cr_assert_not_null(result, "ft_split returned NULL for input: '%s'", p->input);

		if (p->expected[0] == NULL)
		{
			/* Handle cases where no words are expected */
			cr_assert_null(result[0], "Expected an empty array for input: '%s'", p->input);
		}
		else
		{
			/* Verify each word matches exactly */
			size_t i = 0;
			while (p->expected[i] != NULL)
			{
				cr_assert_not_null(result[i], "Expected word at index %zu, got NULL for input: '%s'", i, p->input);
				cr_assert_str_eq(result[i], p->expected[i], "Mismatch at index %zu for input: '%s'", i, p->input);
				i++;
			}
			/* Ensure the final element is a NULL pointer */
			cr_assert_null(result[i], "Expected array to be NULL-terminated at index %zu for input: '%s'", i, p->input);
		}
        
		/* Clean up memory to keep Valgrind and leak checkers happy */
		ft_free_split(result); 
	}
}

/** @} */