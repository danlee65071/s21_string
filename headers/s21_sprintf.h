#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#define NUM_FLAGS 5

#include <stdarg.h>
#include "s21_utils.h"
#include "s21_strerror.h"

typedef struct s_flags {
  char flag;
  uint8_t count;
} t_flags;

typedef struct s_sprintf {
  char specifier;
  t_flags flags[5];
  int width;
  int precision;
  char length;
} t_sprintf;

const char* s21_sprintf_specifiers = "cdfsugGeExXop%%";
const char* s21_sprintf_flags = "-+ #0";

int parse_format(char **str, const char *format, va_list arglist);
void init_flags(t_sprintf* sprintf_args);

#endif
