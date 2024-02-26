#include "s21_sprintf.h"
#include <stdio.h>

void process_percent(char **str, const char *format, \
    va_list arglist, t_sprintf* sprintf_args, int* count, int* i)
{
    (void)str;
    (void)count;
    void (*sprintf_parse_funcs[]) (const char *format, va_list arglist, \
            t_sprintf* sprintf_args, int* i) = {
        parse_flags, \
        parse_width, \
        parse_precision, \
        parse_length, \
        parse_specifiers, \
        NULL
    };
    (*i)++;
    for (uint8_t j = 0; sprintf_parse_funcs[j] != NULL; j++)
        sprintf_parse_funcs[j](format, arglist, sprintf_args, i);
    for (uint8_t j = 0; j < NUM_SPECIFIERS; j++)
        if (sprintf_args->specifier[j].is && sprintf_args->specifier[j].process_spec)
            sprintf_args->specifier[j].process_spec(str, arglist, sprintf_args, count);
}
