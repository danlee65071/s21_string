#include "s21_string.h"

// Функция принимает на вход строку и паттерн
// Возвращает новую строку, в которой удаляются все начальные и конечные 
// вхождения набора заданных символов (trim_chars) из данной строки (src).
// В случае какой-либо ошибки следует вернуть значение NULL.

static inline int checkTrimChars(char srcEl, const char* trimChars) {
    int checkRes = 0;
    for (s21_size_t i = 0; i < s21_strlen(trimChars); i++) {
        if (*(trimChars + i) == srcEl) {
            checkRes = 1;
        }
    }
    return checkRes;
}

void *s21_trim(const char *src, const char *trim_chars) {
    char* srcReturn = NULL;
    int idxStart = 0;
    int idxEnd = s21_strlen(src) - 1;
    while (checkTrimChars(*(src + idxStart), trim_chars))
        idxStart++;
    while (checkTrimChars(*(src + idxEnd), trim_chars))
        idxEnd--;
    if (idxEnd - idxStart + 1 > 0)
    {
        srcReturn = (char*)malloc(idxEnd - idxStart + 2);
        if (!srcReturn)
            return NULL;
        for (int i = idxStart; i < idxEnd + 1; i++)
            srcReturn[i-idxStart] = src[i];
        srcReturn[idxEnd - idxStart + 1] = '\0';
    }
    return srcReturn;
}

