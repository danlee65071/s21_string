#include "s21_string.h"

void parse_precision(const char *format, va_list arglist, t_sprintf* sprintf_args, int* i) {
    while ((isdigit(*(format + i))) || (*(format + i) == '*') || (*(format + i) == '\0')) {
        if (isdigit(*(format + i))) {
            arglist->precision = sprintf_args[0];
            (*i)++;
            break;
        }
        arglist->precision = (int)(*(format + i) - 48);
        (*i)++;
    }   
}