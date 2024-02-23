#include "s21_sprintf.h"

void fill_sign(char** str, int sign, t_sprintf* sprintf_args, int* count)
{
    if (sign < 0)
    {
        (*str)[(*count)++] = '-';
        sprintf_args->width--;
    }
    else if (get_flag_value(sprintf_args->flags, '+'))
    {
        (*str)[(*count)++] = '+';
        sprintf_args->width--;
    }
    else if (get_flag_value(sprintf_args->flags, ' '))
    {
        (*str)[(*count)++] = ' ';
        sprintf_args->width--;
    }
}

void fill_space(char** str, int num, char c, int* count)
{
    for (; num > 0; num--)
        (*str)[(*count)++] = c;
}

void fill_str(char** str, char* str_value, int str_value_len, int* count)
{
    for (int j = 0; j < str_value_len; j++)
        (*str)[(*count)++] = str_value[j];
}
