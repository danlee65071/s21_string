#include "s21_string.h"

// парсер модификатора точности

void parse_precision(const char *format, va_list arglist, t_sprintf* sprintf_args, int* i) {
    if (*(format + *i) == '.') {
        if (*(format + *i) == "*") {
            sprintf_args->width = va_arg(arglist, int);
            (*i)++;
        int buf_size = 1024;
        char *buf = calloc(1024 * sizeof(char));

        if (buf == NULL) {
            return;
        }
        int idx = 0;
        while ((isdigit(*(format + *i))) || (*(format + *i) == '\0')) {
            buf[idx] = (int)(*(format + *i) - 48);
            (*i)++;
            idx++;
            if (index >= buf_size) {
                buf = realloc(buf, buf_size * 2);
                if (buf == NULL) {
                    free(buf);
                    return;
                }
                buf_size *= 2;
            }
            sprintf_args->width = s21_atoi(buf);
            free(buf);
        }
    }   
}