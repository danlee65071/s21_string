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
	s21_strtok.c \
	s21_error.c
UTILS_PATHS = $(addprefix $(UTILS_DIR)/, $(UTILS_SRCS))
SRCS = $(UTILS_PATHS)
DIRS = $(UTILS_DIR)
## sprintf
SPRINTF_DIR = sprintf
SPRINTF_SRCS = s21_sprintf.c \
	parse_format.c \
	init_flags.c \
	process_percent.c \
	parse.c \
	process_flags.c \
	process_int.c \
	process_char.c \
	process_float.c \
	utils.c
SPRINTF_PATHS = $(addprefix $(SPRINTF_DIR)/, $(SPRINTF_SRCS))
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

all: $(NAME)

$(NAME): $(OBJS_PATH)
	ar rcs $(NAME) $(OBJS_PATH)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c Makefile $(HEADERS_PATH)
	mkdir -p $(CREATES_DIR)
	$(CC) $(CFLAGS) -I $(HEADERS_DIR) -c $< -o $@

test: $(NAME)
	make -C $(DIR_TESTS)

clean:
	rm -rf $(OBJS_DIR) $(NAME)
	rm -rf .clang-format

rebuild: clean all

.PHONY: all clean rebuild
