#include <criterion/criterion.h>

/**
 * @addtogroup UnitTests
 * @{
 */

/** @brief Example setup function run before suite tests. */
static void suite_setup(void) {
	// Logic to run before every test in the suite
}

/** @brief Example teardown function run after suite tests. */
static void suite_teardown(void) {
	// Logic to run after every test in the suite
}

/** @brief Specific setup for a single test. */
static void special_setup(void) {
	// Logic only for 'another_test'
}

/**
 * @brief A simple example suite using .init and .fini.
 */
TestSuite(example_suite, .init = suite_setup, .fini = suite_teardown);

/**
 * @test A dummy test to demonstrate fixture execution.
 */
Test(example_suite, sample_test) {
	int x = 1;
	cr_assert(x == 1, "Math is broken!");
}

/**
 * @test Demonstration of a test-specific initializer.
 */
Test(example_suite, another_test, .init = special_setup) {
	cr_assert(2 + 2 == 4);
}

/** @} */