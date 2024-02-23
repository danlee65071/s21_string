#include "s21_string.h"

void parse_length(const char *format, va_list arglist, char* val, int* i) {
    const char* modifiers = "lLh";
    int buf_size = 1800;
    char *buf = calloc(buf_size, sizeof(char));

    if (buf == NULL) {
        return;
    }
    int idx = 0;
    while (format[*i]) {
        if (s21_strchr(modifiers, format[*i])) {
            buf[idx] = format[*i];
            break;
        }
        i++;
        idx++;
        if (idx >= buf_size) {
            buf = realloc(buf, buf_size * 2);
            if (buf == s21_NULL) {
                //free(buf);
                return s21_NULL;        
            }
            buf_size *= 2;
        }
        *val = s21_atoi(buf);
        free(buf); 
    }
    free(buf);
}