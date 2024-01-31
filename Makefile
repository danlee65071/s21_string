NAME = s21_string.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -std=c11
SRC = s21_string.c
HEADERS = s21_string.h
DIR_OBJS = objs
OBJC = $(patsubst %.c, %.o, $(SRC))
PATH_OBJS = $(addprefix $(DIR_OBJS)/, $(OBJC))

ifeq ($(shell uname -s), Linux)
LIBS=-lcheck -lsubunit -lm -lrt -lpthread -lgcov
LEAKS=valgrind --tool=memcheck --leak-check=yes
endif
ifeq ($(shell uname -s), Darwin) # MacOS
LIBS=-lcheck -lm -lpthread -lgcov
LEAKS=leaks -atExit --
endif

all: $(NAME)

s21_string.a: $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(DIR_OBJS) $(NAME)
	rm -rf .clang-format

test: $(NAME)
	$(CC) $(CFLAGS)  test/tests.c -L. $(NAME) $(LIBS) -o test_function
	$(LEAKS) ./test_function
	rm -f test_function
	$(CC) $(CFLAGS) test/*.c -L. $(NAME) $(LIBS) -o sprintf
	$(LEAKS) ./sprintf
	rm -f sprintf

rebuild: clean all
