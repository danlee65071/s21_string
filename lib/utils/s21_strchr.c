#include "s21_string.h"

// Функция strchr ищет первое вхождения символа,
// код которого указан в аргументе ch,
// в строке, на которую указывает аргумент str.

char *s21_strchr(const char *str, int c) {
  char *pos = s21_NULL;
  while ((*str != '\0') && (*str != c)) {
    str++;
  }
  if (*str == c) {
    pos = (char *)str;
  }
  return pos;
}