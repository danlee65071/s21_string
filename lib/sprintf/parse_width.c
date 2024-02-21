#include "s21_sprintf.h"

void parse_width(const char *format, va_list arglist, t_sprintf *sprintf_args,
                 int *i) {
    parse_precision_width(*format, arglist, &(sprintf_args->precision), *i);
}