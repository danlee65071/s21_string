#include "s21_string.h"

// разбивает str[] в соответствии с заданными разделителями и возвращает следующий токен. Его необходимо вызвать в цикле, чтобы получить все токены. Он возвращает NULL, когда токенов больше нет.
// функция возвращает: указатель на следующий токен или NULL, если токенов больше нет.  

char *s21_strtok(char *str, const char *delim) {
  static char *token = NULL; // static делает переменную постоянной, даже если она выходит за пределы области видимости. Он похож на глобальный, но его видимость ограничена блоком, в котором он был определен.

  if (str != NULL) token = str;

  while (token != NULL && *token && s21_strchr(delim, *token)) // Функция strchr ищет первое вхождения символа, код которого указан в аргументе ch, char *s21_strchr(const char *str, int c).
    token++;  // Пропустить ведущие разделители

  char *start = token;
  if (token != NULL) {
    if (*token == '\0') start = NULL;  // Достигнут конец строки

    while (*token && !s21_strchr(delim, *token))  // Найдите конец токена
      token++;

    if (*token != '\0')  // Завершить токен и перейти к следующей позиции
      *token++ = '\0';
  }
  return start;
}