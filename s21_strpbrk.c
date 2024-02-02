#include "s21_string.h"

//Функция strpbrk ищет первое вхождение в строку, 
//на которую указывает аргумент str, одного из символов, 
//входящих в строку, на которую указывает аргумент sym. 

char *s21_strpbrk(const char *str1, const char *str2){
    int f = 0;
    const char *result = NULL;

    for (int i = 0; !f && str1[i] != '\0'; i++)
    {
        for(int j = 0; !f && str2[j] != '\0'; j++){
            if(str1[i]==str2[j]){
                result = str1 + i;
                f = 1;
            }
            
        }
    }
    return (char*)result;
}