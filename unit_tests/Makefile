NAME_TEST = s21_string_test

LIB_NAME = s21_string.a
LIB_DIR = ..
LIB_PATH = $(addprefix $(LIB_DIR)/, $(LIB_NAME))
LIB_HEADER_DIR = $(addprefix $(LIB_DIR)/, headers)

CC = clang
CFLAGS = -Wall -Werror -Wextra -g -std=c11

SRC_TESTS = unit_tests.c
HEADER_TEST = unit_tests.h
# Utils
UTILS_TESTS_DIR = utils
DIRS = $(UTILS_TESTS_DIR)
UTILS_TESTS = s21_memchr_test.c \
	s21_memcmp_test.c \
	s21_memcpy_test.c \
	s21_memset_test.c \
	s21_strchr_test.c \
	s21_strcspn_test.c \
	s21_strerror_test.c \
	s21_strlen_test.c \
	s21_strncat_test.c \
	s21_strncmp_test.c \
	s21_strncpy_test.c \
	s21_strpbrk_test.c \
	s21_strrchr_test.c \
	s21_strstr_test.c \
	s21_strtok_test.c \
	s21_to_lower_test.c \
	s21_to_upper_test.c \
	s21_trim_test.c
UTILS_TESTS_PATH = $(addprefix $(UTILS_TESTS_DIR)/, $(UTILS_TESTS))
SRC_TESTS += $(UTILS_TESTS_PATH)

OBJS_TEST_DIR = objs
OBJS_TEST = $(patsubst %.c, %.o, $(SRC_TESTS))
OBJS_TEST_PATH = $(addprefix $(OBJS_TEST_DIR)/, $(OBJS_TEST))
CREATES_DIR = $(addprefix $(OBJS_TEST_DIR)/, $(DIRS))

# Check platform
ifeq ($(shell uname -s), Linux)
	LIBS= -lcheck -lsubunit -lm -lrt -lpthread -lgcov
	LEAKS=valgrind --tool=memcheck --leak-check=yes
endif
ifeq ($(shell uname -s), Darwin)
	LIBS = $(shell pkg-config --cflags check) $(shell pkg-config --libs check)
	LEAKS=leaks -atExit --
endif

all: $(NAME_TEST)
	./$(NAME_TEST)

$(NAME_TEST): $(OBJS_TEST_PATH)
	$(CC) $(CFLAGS) $(LIBS) $(LIB_PATH) $(OBJS_TEST_PATH) -o $(NAME_TEST)

$(OBJS_TEST_DIR)/%.o: ./%.c $(HEADER_TEST) Makefile
	mkdir -p $(OBJS_TEST_DIR) $(CREATES_DIR)
	$(CC) $(CFLAGS) $(LIBS) -I $(LIB_HEADER_DIR) -I. -Qunused-arguments -c $< -o $@

clean:
	rm -rf $(OBJS_TEST_DIR) $(NAME_TEST)
	rm -rf .clang-format

.PHONY: all clean
