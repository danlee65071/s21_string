NAME = s21_string.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -std=c11
SRC = s21_string.c 
HEADERS = s21_string.h
DIR_OBJS = objs
OBJS = $(patsubst %.c, %.o, $(SRC)) # s21_string.o
PATH_OBJS = $(addprefix $(DIR_OBJS)/, $(OBJS)) # objs/s21_string.o

ifeq ($(shell uname -s), Linux)
LIBS=-lcheck -lsubunit -lm -lrt -lpthread -lgcov
LEAKS=valgrind --tool=memcheck --leak-check=yes
endif
ifeq ($(shell uname -s), Darwin) # MacOS
LIBS=-lcheck -lm -lpthread -lgcov
LEAKS=leaks -atExit --
endif

all: $(NAME)

$(NAME): $(PATH_OBJS)
	ar rcs $(NAME) $(PATH_OBJS)

$(DIR_OBJS)/%.o: %.c Makefile $(HEADERS)
	@# -p ишнорирует ошибку 
	@mkdir -p $(DIR_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(DIR_OBJS) $(NAME)
	rm -rf .clang-format

gcov_report: clean $(NAME)
	$(CC) $(CFLAGS) unit_test/unit_tests.c -L. $(NAME) $(LIBS) --coverage -o checks
	./checks
	lcov -t "report" -o report.info -c -d .
	genhtml -o reports report.info
	rm -rf checks

test: $(NAME)
	$(CC) $(CFLAGS)  test/tests.c -L. $(NAME) $(LIBS) -o test_function
	$(LEAKS) ./test_function
	rm -f test_function
	$(CC) $(CFLAGS) test/*.c -L. $(NAME) $(LIBS) -o sprintf
	$(LEAKS) ./sprintf
	rm -f sprintf

rebuild: clean all

