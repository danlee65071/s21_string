#include "s21_sprintf.h"

void process_char(char **str, va_list arglist, \
    t_sprintf* sprintf_args, int* count)
{
    char value = va_arg(arglist, char);
    sprintf_args->width--;
    if (get_flag_value(sprintf_args->flags, '-'))
    {
        
    }
}
