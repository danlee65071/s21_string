#include "s21_string.h"

void parse_specifier(const char *format, t_sprintf* sprintf_args , int* i){
    char spec = '\0';
    for(int j = 0; j < s21_strlen(SPECIFIERS); j++){
        if(format[*i] == SPECIFIERS){
            spec = format[*i];
        }
        (*i)++;
    }

    return spec;
}