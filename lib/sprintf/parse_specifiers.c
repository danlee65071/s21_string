#include "s21_string.h"

void parse_specifier(const char *format, t_sprintf* sprintf_args , int* i){
    for(int j = 0; j < s21_strlen(SPECIFIERS); j++){
        if(sprintf_args -> specifier == format[*i]){
            sprintf_args->specifier = true;
            if(sprintf_args -> specifier == "n"){
                break;
                (*i)--;
            }
        }
        (*i)++;
    }
}