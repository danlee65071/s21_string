#include "s21_sprintf.h"

int get_radix(t_specifiers* specifiers)
{
    int radix = 10;
    if (get_spec_value(specifiers, 'o'))
        radix = 8;
    else if (get_spec_value(specifiers, 'x') || get_spec_value(specifiers, 'X'))
        radix = 16;
    return radix;
}

void fill_prefix(char** str, t_sprintf* sprintf_args, int radix, int* count)
{
    if (get_flag_value(sprintf_args->flags, '#') && (radix == 8 || radix == 16))
    {
        fill_str(str, "0", 1, count);
        sprintf_args->width--;
        if (get_spec_value(sprintf_args->specifier, 'x'))
        {
            fill_str(str, "x", 1, count);
            sprintf_args->width--;
        }
        else if (get_spec_value(sprintf_args->specifier, 'X'))
        {
            fill_str(str, "X", 1, count);
            sprintf_args->width--;
        }
    }
}

void process_uint(char **str, va_list arglist, \
    t_sprintf* sprintf_args, int* count)
{
    unsigned long long value = 0;
    if (sprintf_args->length == 'h')
        value = (short)va_arg(arglist, unsigned int);
    else if (sprintf_args->length == 'l')
        value = va_arg(arglist, unsigned long);
    else if (sprintf_args->length == 'L')
        value = va_arg(arglist, unsigned long long);
    else
        value = va_arg(arglist, int);
    int radix = get_radix(sprintf_args->specifier);
    char* str_value = s21_itoa(value, radix);
    s21_size_t str_value_len = s21_strlen(str_value);
    sprintf_args->width -= str_value_len;
    int orig_precision = sprintf_args->precision;
    sprintf_args->precision -= str_value_len;
    if (get_flag_value(sprintf_args->flags, '-'))
    {
        fill_prefix(str, sprintf_args, radix, count);
        fill_space(str, sprintf_args->precision, '0', count);
        fill_str(str, str_value, str_value_len, count);
        fill_space(str, sprintf_args->width, ' ', count);
    }
    else
    {
        if (orig_precision <= 0)
        {
            if (get_flag_value(sprintf_args->flags, '0'))
            {
                fill_prefix(str, sprintf_args, radix, count);
                fill_space(str, sprintf_args->width, '0', count);
            }
            else
            {
                fill_space(str, sprintf_args->width, ' ', count);
                fill_prefix(str, sprintf_args, radix, count);
            }
            fill_str(str, str_value, str_value_len, count);
        }
        else
        {
            sprintf_args->width -= sprintf_args->precision > (int)str_value_len ? \
                sprintf_args->precision - (int)str_value_len : 0;
            fill_space(str, sprintf_args->width, ' ', count);
            fill_prefix(str, sprintf_args, radix, count);
            fill_space(str, sprintf_args->precision, '0', count);
            fill_str(str, str_value, str_value_len, count);
        }
    }
    free(str_value);
}
