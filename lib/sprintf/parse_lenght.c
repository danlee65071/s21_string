#include "s21_string.h"

void parse_length(const char *format, va_list arglist, t_sprintf* sprintf_args, int* i) {
    const char* modifiers = "lLh";
    int buf_size = 1800;
    char *buf = calloc(buf_size, sizeof(char));

    if (buf == NULL) {
        return;
    }
    int idx = 0;
    while (format[*i]) {
        if (strchr(modifiers, format[*i])) {
            buf[idx] = format[*i];
            break;
        }
        i++;
        idx++;
    }
    free(buf);
}