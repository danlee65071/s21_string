#include "s21_string.h"

// Возвращает новую строку, в которой указанная строка (str) вставлена
// в указанную позицию (start_index) в данной строке (src). 
// В случае какой-либо ошибки следует вернуть значение NULL.

void additionFunc(char* fstStr, char* secStr, size_t idx, char* resultStr) {
    size_t i = 0;
    size_t j = 0;
    while (*(fstStr + i) != '\0') {
        *(resultStr + i) = *(fstStr + i);
        if (i == idx) {
            while (*(secStr + j) != '\0') {
                *(resultStr + i) = *(secStr + j);
                j++;
            }
            i -= j;
        }
        i++;       
    }
}

void *insert(const char *src, const char *str, size_t start_index) {
    char* resultStr = s21_NULL;
    if (src && str && start_index > -1) {
        resultStr = malloc(s21_strlen(str) + s21_strlen(str) + 1 * sizeof(char));
        if (!start_index) {
            additionFunc(str, src, start_index, resultStr);
        } else {
            additionFunc(str, str, start_index, resultStr);
        }
    }
    return resultStr;
}