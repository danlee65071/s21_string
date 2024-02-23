#include "s21_sprintf.h"
#include <stdio.h>

void print_flag(t_sprintf* sprintf_args)
{
    printf("specifier: %c\n", sprintf_args->specifier);
    printf("Flags\n");
    for (uint8_t i = 0; i < 5; i++)
    {
        printf("\tflag: %c\n", sprintf_args->flags[i].flag);
        printf("\tis: %d\n", sprintf_args->flags[i].is);
        printf("\n");
    }
    printf("width: %d\n", sprintf_args->width);
    printf("precision: %d\n", sprintf_args->precision);
    printf("length: %c\n", sprintf_args->length);
}

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
    process_int(str, arglist, sprintf_args, count);
    // printf("%d\n", *i);
    // print_flag(sprintf_args);
}
