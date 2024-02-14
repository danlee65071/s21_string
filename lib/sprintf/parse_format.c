#include "s21_sprintf.h"

int parse_format(char **str, const char *format, va_list arglist) {
  int count = 0;
  int format_len = s21_strlen(format);
  for (int i = 0; i < format_len; i++) {
    t_sprintf sprintf_args = {0};
    init_flags(&sprintf_args);
    if (format[i] == '%')
      process_percent(str, format, arglist, &sprintf_args, &count, &(i));
    else
      (*str)[count++] = format[i];
  }
  return count;
}
