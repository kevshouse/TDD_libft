# LIBFT MAKEFILE
NAME = libft.a

# COMPILER SETTINGS
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
COVERAGE_FLAGS = --coverage
INCLUDES = -Iincludes
COVERAGE_THRESHOLD = 20

# SOURCE FILES
SRC_DIR = src
SRC_FILES = ft_abs.c \
            ft_arrdup.c \
            ft_atoi.c \
            ft_atol.c \
            ft_bzero.c \
            ft_calloc.c \
            ft_free_split.c \
            ft_isdigit.c \
            ft_isvalidnum.c \
            ft_max.c \
            ft_memcpy.c \
            ft_printf.c \
            ft_putendl_fd.c \
            ft_putchar_fd.c \
            ft_putstr_fd.c \
            ft_split.c \
            ft_sqrt.c \
            ft_swap.c \
            printft_utils2.c \
            printf_utils.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# OBJECT FILES
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# TEST SETTINGS
TEST_NAME = unit_tests
TEST_MALLOC_NAME = unit_tests_malloc
TEST_DIR = tests
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
TEST_NORMAL_SRCS = $(filter-out $(TEST_DIR)/test_ft_split_malloc.c, $(TEST_SRCS))
TEST_MALLOC_SRCS = $(TEST_DIR)/test_ft_split_malloc.c

# BUILD RULES
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

# CLEAN RULES
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(TEST_NAME) $(TEST_MALLOC_NAME) doxygen_warnings.log
	rm -rf doc coverage_report
	rm -f $(SRC_DIR)/*.gcda $(SRC_DIR)/*.gcno
	rm -f $(TEST_DIR)/*.gcda $(TEST_DIR)/*.gcno

re: fclean all

# TEST RULES
test: $(NAME)
	@echo "\n=== RUNNING STANDARD TESTS ==="
	$(CC) $(CFLAGS) $(INCLUDES) $(TEST_NORMAL_SRCS) -L. -lft -lcriterion -o $(TEST_NAME)
	./$(TEST_NAME)
	@echo "\n=== RUNNING MALLOC FAILURE TESTS ==="
	$(CC) $(CFLAGS) $(INCLUDES) $(TEST_MALLOC_SRCS) -L. -lft -lcriterion -Wl,--wrap=malloc -o $(TEST_MALLOC_NAME)
	./$(TEST_MALLOC_NAME)

coverage: CFLAGS += $(COVERAGE_FLAGS)
coverage: re test
	lcov --capture --directory . --output-file coverage.info --ignore-errors mrc,mismatch
	genhtml coverage.info --output-directory coverage_report
	@TOTAL_COV=$$(lcov --summary coverage.info | grep lines | sed 's/.*: \([0-9.]*\)%.*/\1/' | cut -d. -f1); \
	if [ -z "$$TOTAL_COV" ]; then TOTAL_COV=0; fi; \
	echo "Total Line Coverage: $$TOTAL_COV% (Threshold: $(COVERAGE_THRESHOLD)%)"; \
	if [ $$TOTAL_COV -lt $(COVERAGE_THRESHOLD) ]; then \
		echo "Error: Coverage is below $(COVERAGE_THRESHOLD)% threshold!"; \
		exit 1; \
	fi

valgrind: $(NAME)
	$(CC) $(CFLAGS) $(INCLUDES) $(TEST_SRCS) -L. -lft -lcriterion -Wl,--wrap=malloc -o $(TEST_NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes --error-exitcode=1 ./$(TEST_NAME)

# DOCUMENTATION RULES
doc:
	@if command -v doxygen > /dev/null; then \
		doxygen Doxyfile; \
	else \
		echo "Error: doxygen not found. Please install it to generate documentation."; \
		exit 1; \
	fi

# PHONY TARGETS
.PHONY: all clean fclean re doc test coverage valgrind
