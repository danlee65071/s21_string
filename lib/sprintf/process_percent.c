#include "s21_sprintf.h"

void process_percent(char **str, const char *format, \
    va_list arglist, t_sprintf* sprintf_args, int* count, int* i)
{
    (*i)++;
    parse_flags(format, sprintf_args, i);
}
