#include "s21_string.h"
// Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
// указывает аргумент str.
void *my_memset(void *str, int c, size_t n) {
  char *s = (char *)str;
  for (size_t i = 0; i < n; i++) {
    s[i] = c;  // устанавливаем значение c в каждый байт, на который указывает
               // s[i]
  }
  return str;
}