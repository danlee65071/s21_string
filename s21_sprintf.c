#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list arglist;
  int count = 0;
  va_start(arglist, format);
  count = parse_format(&str, format, arglist);
  va_end(arglist);

  return count;
}

char parse_format(char **str, const char *format, va_list arglist) {
  int count = 0;
  t_flags flags;
  int format_len = s21_strlen(format);
  for (int i = 0; i < format_len; i++) {
    if (format[i] == '%') {
      process_percent(str, format, arglist, &flags, &count, ++i);
    } else {
      (*str)[count++] = format[i];
    }
  }
}

void process_percent(char **str, char *format, va_list arglist, t_flags *flags,
                     int *count, int *i) {
  if (format[*i] == '\0') {  // уточнить конкретный спецификатор
    (*str)[*count++] = format[(*i)++];
    parse_flags(format, arglist, flags);
  }
}
