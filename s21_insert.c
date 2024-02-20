#include "s21_string.h"

// Возвращает новую строку, в которой указанная строка (str) вставлена
// в указанную позицию (start_index) в данной строке (src). 
// В случае какой-либо ошибки следует вернуть значение NULL.

void additionFunc(const char* fstStr, const char* secStr, size_t idx, char** resultStr)
{
    size_t i = 0;
    size_t j = 0;
    while (fstStr[j] != '\0')
    {
        if (j == idx) {
            for (size_t k = 0; k < s21_strlen(secStr); k++)
                (*resultStr)[i++] = secStr[k];
        }
        (*resultStr)[i++] = fstStr[j++];
    }
    (*resultStr)[i] = '\0';
}


void *s21_insert(const char *src, const char *str, size_t start_index)
{
    char* resultStr = s21_NULL;
    if (src && (resultStr = malloc((s21_strlen(src) + s21_strlen(str)) * sizeof(char))))
        additionFunc(src, str, start_index, &resultStr);
    return resultStr;
}
