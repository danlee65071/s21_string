#include "s21_sprintf.h"

void process_percent(char **str, const char *format, \
    va_list arglist, t_sprintf* sprintf_args, int* count, int* i)
{
    (*i)++;
    parse_flags(format, sprintf_args, i);
    parse_width(format, arglist, sprintf_args, i);
    parse_precision(format, arglist, sprintf_args, i);
    parse_length(format, arglist, &(sprintf_args->length), i);
    // parse_specifiers();
    // process();
    printf("%s %d", *str, *count);
}
    