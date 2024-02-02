#include "s21_string.h"

// char *strncat(char *dest, const char *src, size_t n)
// принимает нп вход адреса на 2 строки и количество символов которое будем добалять
// добавляет строку, на которую указывает src, к концу строки, на которую указывает dest, длиной до n символов.

char *s21_strncat(char *dest, const char *src, size_t n) {
    if (n > 0 && src) {
        size_t sizeDest = s21_strlen(dest);
        for (size_t i = 0; i < n; i++) {
            *(dest + sizeDest + i) = *(src + i);
        }
    }
    return dest;
}