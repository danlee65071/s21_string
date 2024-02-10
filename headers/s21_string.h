#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdarg.h>
#include "s21_utils.h"
#include "s21_strerror.h"

typedef struct s_flags {
  char specifier;
  bool minus;
  bool sign;
  bool hashtag;
  bool zero;
  int width;
  int precision;
  char length;
  bool star;
} t_flags;

#define s21_NULL (void *)0

#endif