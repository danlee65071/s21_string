#include "s21_string.h"
// Возвращает копию строки (str), преобразованной в верхний регистр. В случае
// какой-либо ошибки следует вернуть значение NULL.
void *s21_to_upper(const char *str) {
  char *upper = s21_NULL;

  if ((upper = malloc(s21_strlen(str) + 1 * sizeof(char)))) {
    int i = 0;
    while (str[i] != '\0') {
      if (str[i] >= 'a' && str[i] <= 'z') {
        upper[i] = str[i] - 32;
      } else {
        upper[i] = str[i];
      }
      i++;
    }
    upper[i] = '\0';
  }
  return upper;
}