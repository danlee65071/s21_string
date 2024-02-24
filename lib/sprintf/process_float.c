#include "s21_sprintf.h"

void process_float(char **str, va_list arglist, \
    t_sprintf* sprintf_args, int* count)
{
    long double value = 0;
    if (sprintf_args->length == 'L')
        value = va_arg(arglist, long double);
    else
        value = va_arg(arglist, double);
    sprintf_args->precision = sprintf_args->precision < 0 ? 6 : sprintf_args->precision;
    int sign = value < 0 ? -1 : 1;
    
}
