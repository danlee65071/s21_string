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

rebuild: clean all

.PHONY: all clean rebuild