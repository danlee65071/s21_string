#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) { // ... - дополнительные параметры
  va_list arglist;
  int count = 0;

  va_start(arglist, format);
  count = parse_format(&str, format, arglist);
  va_end(arglist);

  return count;
}

t_flags init_flags(t_flags *flags) {
  flags->specifier = 0;
  flags->minus = false;
  flags->sign = false;
  flags->hashtag = false;
  flags->zero = false;
  flags->width = 0;
  flags->precision = 0;
  flags->length = 0;
  flags->star = false;

  return *flags;
}

int parserFormatStr(char **str, const char* format, va_list arglist) {
    int count = 0;
    t_flags flags;
    for (int i = 0; i < s21_strlen(format), i++) {
        flags = init_flags(&flags);
        if (*(format + i) == '%') {
            
        }
    return count;
    }
}