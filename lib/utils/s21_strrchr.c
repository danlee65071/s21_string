#include "s21_string.h"

//  char *strrchr (const char *str, int ch);
//  Функция strchr ищет последнее вхождения символа, код которого указан в
//  аргументе ch, в строке, на которую указывает аргумент str. Возвращаемое
//  значение: Указатель на искомый символ, если он найден в строке str, иначе
//  NULL.

char *s21_strrchr(const char *str, int c) {
  const char *ptr = str;
  int simbol = 0;

  while (*str) {
    str++;
  }
  while (str >= ptr) {
    if (*str == (char)c) {
      simbol = 1;
      break;
    }
    str--;
  }
  return simbol ? (char *)str : NULL;
}
