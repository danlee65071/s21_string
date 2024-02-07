#include "s21_string.h"

// Возвращает новую строку, в которой указанная строка (str) вставлена
// в указанную позицию (start_index) в данной строке (src). 
// В случае какой-либо ошибки следует вернуть значение NULL.

void additionFunc(const char* fstStr, const char* secStr, size_t idx, char* resultStr) {
    size_t i = 0;
    size_t j = 0;
    while (*(fstStr + j) != '\0') {
        *(resultStr + i) = *(fstStr + j);
        if (i == idx) {
            j = 0;
            while (*(secStr + j) != '\0') {
                *(resultStr + i) = *(secStr + j);
                i++;
                j++;
            }
            j = i - j - 1;
            i--;
        }
        i++;
        j++;       
    }
    *(resultStr + i) = '\0';
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
    char* resultStr = s21_NULL;
    if (src && str && (resultStr = malloc(s21_strlen(src) + s21_strlen(str) + 1 * sizeof(char)))) {
        if (start_index > 0) {
            additionFunc(src, str, start_index, resultStr);
        } else {
            additionFunc(str, src, start_index, resultStr);
        }
    }
    return resultStr;
}