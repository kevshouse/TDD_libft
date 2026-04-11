#include <criterion/criterion.h>
#include <stddef.h>
#include <unistd.h>

/* 1. Define variables to track the mock state */
static struct {
	int last_fd;
	char last_char;
	int call_count;
} mock_state;

/* 2. Define the Mock Function */
ssize_t mock_write(int fd, const void *buf, size_t count)
{
	mock_state.last_fd = fd;
	mock_state.last_char = *(char *)buf;
	mock_state.call_count++;
	return (ssize_t)count;
}

/* 3. The "Magic": Redefine the function name before including the .c file.
   This replaces all instances of 'write' in ft_putchar_fd.c with 'mock_write'. */
#define write mock_write
#include "/home/kevin-anderson/Documents/code/TDD_libft/libft/src/ft_putchar_fd.c"
#undef write

/* 4. Setup and Test */
void setup_mock(void)
{
	mock_state.last_fd = -1;
	mock_state.last_char = 0;
	mock_state.call_count = 0;
}

Test(ft_putchar_fd, mock_test, .init = setup_mock)
{
	/* Call the function under test */
	ft_putchar_fd('A', 2);

	/* Verify that our mock was called instead of the real 'write' */
	cr_assert_eq(mock_state.call_count, 1, "Expected write to be called once");
	cr_assert_eq(mock_state.last_fd, 2, "Expected write to be called with fd 2");
	cr_assert_eq(mock_state.last_char, 'A', "Expected write to be called with character 'A'");
}