#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#define SPECIFIERS "cdfsugGeExXop%%"
#define NUM_FLAGS 5
#define FLAGS "-+ #0"

#include <stdarg.h>
#include <ctype.h>
#include "s21_utils.h"
#include "s21_strerror.h"

typedef struct s_flags {
  char flag;
  bool is;
} t_flags;

typedef struct s_sprintf {
  char specifier;
  t_flags flags[5];
  int width;
  int precision;
  char length;
} t_sprintf;

int parse_format(char **str, const char *format, va_list arglist);
void init_flags(t_sprintf* sprintf_args);
void process_percent(char **str, const char *format, \
    va_list arglist, t_sprintf* sprintf_args, int* count, int* i);
bool is_in_str(const char c, const char* str);
void parse_flags(const char *format, t_sprintf* sprintf_args, int* i);

#endif
