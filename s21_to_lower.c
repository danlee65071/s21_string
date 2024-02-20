#include "s21_string.h"

// Возвращает копию строки (str), преобразованной в нижний регистр.
// В случае какой-либо ошибки следует вернуть значение NULL.

void *s21_to_lower(const char *str) {
    char* lowerStr = s21_NULL;
    if ((lowerStr = malloc((s21_strlen(str)+ 1) * sizeof(char)))) {
        int i = 0;
        while (*(str + i) != '\0') {
            if (*(str + i) > 64 && *(str + i) < 91) {
                *(lowerStr + i) = *(str + i) + 32;
            } else {
                *(lowerStr + i) = *(str + i);
            }
            i++;
        }
        *(lowerStr + i) = '\0';
    }
    return lowerStr;
}         