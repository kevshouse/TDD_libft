#include <criterion/criterion.h>
#include <unistd.h>
#include <string.h>

/**
 * @addtogroup UnitTests
 * @{
 */

static char g_output_buf[1024];
static int g_buf_idx = 0;

/** @brief Mock write function (static to avoid linker collisions). */
static ssize_t mock_write_endl(int fd, const void *buf, size_t count)
{
	(void)fd;
	if (g_buf_idx + count < 1024)
	{
		memcpy(g_output_buf + g_buf_idx, buf, count);
		g_buf_idx += count;
		g_output_buf[g_buf_idx] = '\0';
	}
	return (ssize_t)count;
}

#define write mock_write_endl
#define ft_putchar_fd ft_putchar_mock
#include "../src/ft_putchar_fd.c"

#define ft_putstr_fd ft_putstr_mock
#include "../src/ft_putstr_fd.c"

#define ft_putendl_fd ft_putendl_mock
#include "../src/ft_putendl_fd.c"

#undef write
#undef ft_putchar_fd
#undef ft_putstr_fd

/** @brief Reset the buffer (static to avoid linker collisions). */
static void setup_endl(void)
{
	memset(g_output_buf, 0, sizeof(g_output_buf));
	g_buf_idx = 0;
}

Test(ft_putendl_fd, basic_test, .init = setup_endl)
{
	ft_putendl_mock("Hello", 1);
	cr_assert_str_eq(g_output_buf, "Hello\n", "Expected 'Hello\\n', got '%s'", g_output_buf);
}

Test(ft_putendl_fd, empty_string, .init = setup_endl)
{
	ft_putendl_mock("", 1);
	cr_assert_str_eq(g_output_buf, "\n", "Expected only a newline");
}

/** @} */