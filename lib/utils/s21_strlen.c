#include "s21_string.h"

// size_t strlen(const char *str)
// принимает на вход адрес строки
// вычисляет длину строки str до завершающего нулевого символа, но не включая
// его.

size_t s21_strlen(const char *str) {
  size_t n = 0;
  int i = 0;
  while (*(str + i++) != '\0') {
    n++;
  }
  return n;
}