#include "s21_string.h"

// Сравнивает не более первых n байтов str1 и str2.

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  for (size_t i = 0; i < n; i++) {
    if (str1[i] != str2[i]) {
      return str1[i] - str2[i];
    }
    if (str1[i] == '\0' || str2[i] == '\0') {
      break;
    }
  }
  return 0;
}