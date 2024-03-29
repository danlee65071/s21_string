#include "s21_string.h"

//Функция принимает на вход 2 строки и количество байтов этих строк
//возвращая результат сравнивнения первые n байтов строк.

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    if ((str1 && str2) && n) {
        for (s21_size_t i = 0; i < n; i++) {
            if (*((char*) (str1 + i)) != *((char*) (str2 + i))) {
                return *((char*) (str1 + i)) - *((char*) (str2 + i));
            }
        }
    }
    return 0;
}
