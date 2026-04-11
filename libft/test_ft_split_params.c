#include <criterion/criterion.h>
#include "../includes/libft.h"

/**
 * @brief Structure to hold parameters for ft_split tests.
 */
struct ft_split_test_params {
	const char	*input;
	char		delimiter;
	const char	*expected[10]; // Array of expected strings, NULL-terminated
};

/**
 * @brief Data provider for the parameterized tests.
 */
ParameterizedTestParameters(ft_split, edge_cases)
{
	static struct ft_split_test_params params[] = {
		{"hello world", ' ', {"hello", "world", NULL}},
		{"   lorem   ipsum  ", ' ', {"lorem", "ipsum", NULL}},
		{"split", 'z', {"split", NULL}},
		{"", ' ', {NULL}},
		{"   ", ' ', {NULL}},
		{"first:second:third", ':', {"first", "second", "third", NULL}},
		{"--a--b--c--", '-', {"a", "b", "c", NULL}}
	};

	return cr_make_param_array(struct ft_split_test_params, params, sizeof(params) / sizeof(struct ft_split_test_params));
}

/**
 * @brief The actual test logic run for every entry in the parameter array.
 */
ParameterizedTest(struct ft_split_test_params *p, ft_split, edge_cases)
{
	char	**result;
	size_t	i;

	result = ft_split(p->input, p->delimiter);

	/* Ensure we actually got an array back */
	cr_assert_not_null(result, "ft_split returned NULL for input: '%s'", p->input);

	if (p->expected[0] == NULL)
	{
		/* Handle cases where no words are expected */
		cr_assert_null(result[0], "Expected an empty array (first element NULL) for input: '%s'", p->input);
	}
	else
	{
		i = 0;
		while (p->expected[i] != NULL)
		{
			cr_assert_not_null(result[i], "Expected word at index %zu, but got NULL for input: '%s'", i, p->input);
			cr_assert_str_eq(result[i], p->expected[i], "Word mismatch at index %zu for input: '%s'. Expected '%s', got '%s'", 
				i, p->input, p->expected[i], result[i]);
			i++;
		}
		/* Ensure the result array is properly NULL-terminated */
		cr_assert_null(result[i], "Result array for input '%s' is not NULL-terminated at index %zu", p->input, i);
	}

	/* Clean up using your existing ft_free_split */
	ft_free_split(result);
}