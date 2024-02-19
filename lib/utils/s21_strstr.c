#include "s21_string.h"

//  char *strstr(const char *haystack, const char *needle); 
//  Функция strstr() ищет первое вхождение подстроки needle в строке haystack. Завершающий символ `\0' не сравнивается.
//  Возвращаемое значение: Эта функция возвращает указатель на начало подстроки, или NULL, если подстрока не найдена.

char *s21_strstr(const char *haystack, const char *needle) {
    const char *h, *n;  // указатели
    for (; *haystack != '\0'; haystack++) { //  пока не равен концу строки идём до конца
        h = haystack; //переназначаем указатель
        n = needle;
        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }
        if (*n == '\0') {
            return (char *) haystack; //возвращаем указатель на строку
        }
    }
    return NULL;
}
