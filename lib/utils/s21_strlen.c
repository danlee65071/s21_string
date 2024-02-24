#include "s21_string.h"

// s21_size_t strlen(const char *str) 
// принимает на вход адрес строки
// вычисляет длину строки str до завершающего нулевого символа, но не включая его.

s21_size_t s21_strlen(const char *str) {
    return (s21_size_t)(s21_strchr(str, 0) - str);
}