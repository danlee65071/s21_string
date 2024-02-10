NAME = s21_string.a 
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -std=c11

# Sources
## Utils
UTILS_DIR = utils
UTILS_SRCS = s21_memcmp.c \
	s21_memchr.c \
	s21_memset.c \
	s21_strlen.c \
	s21_strncat.c \
	s21_strncmp.c \
	s21_strncpy.c \
	s21_memcpy.c \
	s21_strrchr.c \
	s21_strchr.c \
	s21_strpbrk.c \
	s21_strerror.c \
	s21_to_upper.c \
	s21_trim.c \
	s21_to_lower.c \
	s21_strstr.c \
	s21_strcspn.c \
	s21_strtok.c
UTILS_PATHS = $(addprefix $(UTILS_DIR)/, $(UTILS_SRCS))
SRCS = $(UTILS_PATHS)
DIRS = $(UTILS_DIR)
## sprintf
SPRINTF_DIR = sprintf
SPRINTF_SRCS = s21_sprintf.c \
	parse_format.c \
	init_flags.c \
	process_percent.c \
	parse_flags.c \
	utils.c
SPRINTF_PATHS = $(addprefix $(UTILS_DIR)/, $(UTILS_SRCS))
SRCS += $(SPRINTF_PATHS)
DIRS += $(SPRINTF_DIR)
## SRCS_PATH
SRCS_DIR = lib
SRCS_PATH = $(addprefix $(SRCS_DIR)/, $(SRCS))

# Headers
HEADERS_DIR = headers
HEADERS = s21_string.h \
	s21_utils.h \
	s21_strerror.h \
	s21_sprintf.h
HEADERS_PATH = $(addprefix $(HEADERS_DIR)/, $(HEADERS))

# objs
OBJS_DIR = objs
OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJS_PATH = $(addprefix $(OBJS_DIR)/, $(OBJS))
CREATES_DIR = $(addprefix $(OBJS_DIR)/, $(DIRS))

# Tests
DIR_TESTS = unit_tests
SRC_TESTS = unit_tests.c
## Utils
UTILS_TESTS_DIR = utils
UTILS_TESTS = s21_memcmp_test.c \
	s21_memchr_test.c \
	s21_memset_test.c \
	s21_strlen_test.c \
	s21_strncat_test.c \
	s21_strncmp_test.c \
	s21_strncpy_test.c \
	s21_memcpy_test.c \
	s21_strrchr_test.c \
	s21_strchr_test.c \
	s21_strpbrk_test.c \
	s21_strerror_test.c \
	s21_to_upper_test.c \
	s21_to_lower_test.c \
	s21_trim_test.c \
	s21_strstr_test.c \
	s21_strcspn_test.c \
	s21_strtok_test.c
UTILS_TESTS_PATH = $(addprefix $(UTILS_TESTS_DIR)/, $(UTILS_TESTS))
SRC_TESTS += $(UTILS_TESTS_PATH)
## PATH_SRC_TESTS
PATH_SRC_TESTS = $(addprefix $(DIR_TESTS)/, $(SRC_TESTS))
NAME_TEST = s21_string_test

# Check platform
ifeq ($(shell uname -s), Linux)
	LIBS= $(CFLAGS) -lcheck -lsubunit -lm -lrt -lpthread -lgcov
	LEAKS=valgrind --tool=memcheck --leak-check=yes
endif
ifeq ($(shell uname -s), Darwin)
	LIBS = $(CFLAGS) $(shell pkg-config --cflags check) $(shell pkg-config --libs check)
	LEAKS=leaks -atExit --
endif

all: $(NAME)

$(NAME): $(OBJS_PATH)
	ar rcs $(NAME) $(OBJS_PATH)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c Makefile $(HEADERS_PATH)
	mkdir -p $(CREATES_DIR)
	$(CC) $(CFLAGS) -I $(HEADERS_DIR) -c $< -o $@

test: $(NAME) $(PATH_SRC_TESTS)
	$(CC) $(CFLAGS) -I $(HEADERS_DIR) -I $(DIR_TESTS) $(PATH_SRC_TESTS) $(LIBS) $(NAME) -o $(NAME_TEST)
	$(LEAKS) ./$(NAME_TEST)
	rm -f $(NAME_TEST)

clean:
	rm -rf $(OBJS_DIR) $(NAME)
	rm -rf .clang-format

rebuild: clean all

.PHONY: all clean rebuild
