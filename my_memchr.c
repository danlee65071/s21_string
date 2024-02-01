#include "s21_string.h"
// Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
// байтах строки, на которую указывает аргумент str.
void *my_memchr(const void *str, int c, size_t n) {
  const unsigned char *ptr = (unsigned char *)str;
  for (size_t i = 0; i < n; i++) {
    if (ptr[i] == (unsigned char *)c) {
      return (void *)&ptr[i];
    }
  }
  return NULL;
}