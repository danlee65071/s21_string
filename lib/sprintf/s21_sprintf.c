#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...)
{
  va_list arglist;
  va_start(arglist, format);
  int count = parse_format(&str, format, arglist);
  va_end(arglist);
  return count;
}
