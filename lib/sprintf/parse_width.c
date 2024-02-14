#include "s21_sprintf.h"

void parse_width(const char *format, va_list arglist, t_sprintf *sprintf_args,
                 int *i) {
  if (format[*i] == '*') {
    sprintf_args->width = va_arg(arglist, int);
    (*i)++;
  } else if (is_digit(format[*i])) {
    int buf_size = 1024;
    char *buf = calloc(1024 * sizeof(char));

    if (buf == NULL) {
      printf("Ошибка: не удалось выделить память для buf\n");
      return;
    }
    int index = 0;
    while (is_digit(format[*i])) {
      buf[index] = format[*i];
      (*i)++;
      index++;
      if (index >= buf_size) {
        buf = realloc(buf, buf_size * 2);
        if (buf == NULL) {
          return;
        }
        buf_size *= 2;
      }
    }
    free(buf);
    sprintf_args->width = s21_atoi(buf);
  }
}