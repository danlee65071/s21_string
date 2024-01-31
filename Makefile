# all
# clean
# test
# s21_string.a
# gcov_report

NAME = s21_string.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -std=c11
SRC = s21_string.c
HEADERS = s21_string.h
DIR_OBJS = objs
OBJC = $(patsubst %.c, %.o, $(SRC))
PATH_OBJS = $(addprefix $(DIR_OBJS)/, $(OBJC))
