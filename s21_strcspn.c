#include "s21_string.h"

//Функция strcspn определяет наибольшую длину начального участка строки, 
//на которую указывает аргумент str, 
//не содержащего не один из символов строки, 
//на которую указывает аргумент sym. 

s21_size_t s21_strcspn(const char *str1, const char *str2){
    s21_size_t i, len = s21_strlen(str1);
    for(i = 0; i < len; i++){
        if(s21_strchr(str2,str1[i]) != NULL){
            break;
        }
    }
    return i;
}
