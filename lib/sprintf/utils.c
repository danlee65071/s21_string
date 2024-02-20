#include "s21_sprintf.h"

bool is_in_str(const char c, const char *str) {
  uint8_t len = s21_strlen(str);
  for (uint8_t i = 0; i < len; i++)
    if (c == str[i]) return true;
  return false;
}

bool is_digit(int dig) {
  return (dig >= 48 && dig <= 57) || (dig >= 0 && dig <= 9);
}

int s21_atoi(const char *str) {
  int res = 0;
  int sign = 1;
  int overflow = 0;

  while (*str == ' ') str++;

  if (*str == '-') {
    str++;
    sign = -1;
  }

  if (*str == '+') {
    str++;
  }

  while (*str && *str >= '0' && *str <= '9') {
    res = res * 10 + (*str - '0');
    if (res < 0) {
      overflow = 1;
      break;
    }
    str++;
  }
  if (overflow)
    res = sign > 0 ? INT32_MAX : INT32_MIN;
  else
    res *= sign;

  return res;
}

int str_to_int(char *str) {
  int num = 0;
  while (*str != '\0') {
    int dig = (int)*str - 48;  // some char '0' (ASCII 48) to decimal digit
    num = num * 10 + dig;  // перемещение числа на разряд влево
    str++;
  }

  return num;
}

