#include "s21_string.h"

// парсер модификатора точности

void parse_precision(const char *format, va_list arglist,
                     t_sprintf *sprintf_args, int *i) {
  if (*(format + *i) == '.') {
    parse_precision_width(*format, arglist, &(sprintf_args->precision), *i);
  }
}