NAME = s21_string.a 
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -std=c11
SRC = s21_memcmp.c s21_memchr.c s21_memset.c s21_strlen.c s21_strncat.c s21_strncmp.c s21_strncpy.c s21_memcpy.c s21_strrchr.c s21_strchr.c s21_strpbrk.c s21_strerror.c s21_to_upper.c s21_trim.c s21_strstr.c
HEADERS = s21_string.h
DIR_OBJS = objs
OBJS = $(patsubst %.c, %.o, $(SRC)) # s21_string.o
PATH_OBJS = $(addprefix $(DIR_OBJS)/, $(OBJS)) # objs/s21_string.o
DIR_TESTS = unit_tests
SRC_TESTS = unit_tests.c s21_memcmp_test.c s21_memchr_test.c s21_memset_test.c s21_strlen_test.c s21_strncat_test.c s21_strncmp_test.c s21_strncpy_test.c s21_memcpy_test.c s21_strrchr_test.c s21_strchr_test.c s21_strpbrk_test.c s21_strerror_test.c s21_to_upper_test.c s21_trim_test.c s21_strstr_test.c
PATH_SRC_TESTS = $(addprefix $(DIR_TESTS)/, $(SRC_TESTS))
NAME_TEST = s21_string_test

ifeq ($(shell uname -s), Linux)
LIBS= $(CFLAGS) -lcheck -lsubunit -lm -lrt -lpthread -lgcov
LEAKS=valgrind --tool=memcheck --leak-check=yes
endif
ifeq ($(shell uname -s), Darwin) # MacOS
# LIBS=-lcheck -lm -lpthread -lgcov -lsubunit
LIBS = $(CFLAGS) $(shell pkg-config --cflags check) $(shell pkg-config --libs check)
LEAKS=leaks -atExit --
endif

all: $(NAME)

$(NAME): $(PATH_OBJS)
	ar rcs $(NAME) $(PATH_OBJS)

$(DIR_OBJS)/%.o: %.c Makefile $(HEADERS)
	@# -p ишнорирует ошибку 
	@mkdir -p $(DIR_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME)
	$(CC) $(CFLAGS) -I . $(PATH_SRC_TESTS) $(LIBS) $(NAME) -o $(NAME_TEST)
	$(LEAKS) ./$(NAME_TEST)
	rm -f $(NAME_TEST)

clean:
	rm -rf $(DIR_OBJS) $(NAME)
	rm -rf .clang-format

rebuild: clean all

.PHONY: all clean rebuild

