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
    char* str_value = s21_ftoa(value * sign, sprintf_args->precision);
    s21_size_t str_value_len = s21_strlen(str_value);
    sprintf_args->width -= str_value_len;
    if (get_flag_value(sprintf_args->flags, '-'))
    {
        fill_sign(str, sign, sprintf_args, count);
        fill_str(str, str_value, str_value_len, count);
        fill_space(str, sprintf_args->width, ' ', count);
    }
    else
    {
        if (get_flag_value(sprintf_args->flags, '0'))
        {
            fill_sign(str, sign, sprintf_args, count);
            fill_space(str, sprintf_args->width, '0', count);
        }
        else
        {
            if (sign < 0 || get_flag_value(sprintf_args->flags, '+'))
                sprintf_args->width--;
            fill_space(str, sprintf_args->width, ' ', count);
            fill_sign(str, sign, sprintf_args, count);
        }
        fill_str(str, str_value, str_value_len, count);
    }
    free(str_value);
}
