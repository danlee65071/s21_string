#include "s21_string.h"

// char *strncpy(char *dest, const char *src, s21_size_t n)	
// принимает нп вход адреса на 2 строки и количество символов которое будем копировать
// Копирует до n символов из строки, на которую указывает src, в dest.

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    s21_size_t sizeDest = s21_strlen(dest);
    // s21_size_t sizeSrc = s21_strlen(src);
    if (sizeDest < n) {
        n = sizeDest;
    }
    if (src) {
        for (s21_size_t i = 0; i < n; i++) {
            *(dest + i) = *(src + i);
        }
    }
    return dest;
}