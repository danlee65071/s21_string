#include "s21_sprintf.h"

void process_exp(char **str, va_list arglist, \
    t_sprintf* sprintf_args, int* count)
{
    long double value = 0;
    if (sprintf_args->length == 'L')
        value = va_arg(arglist, long double);
    else
        value = va_arg(arglist, double);
}
