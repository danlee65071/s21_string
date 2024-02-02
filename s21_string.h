#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdio.h>
#include <stdlib.h>

int s21_memcmp(const void *str1, const void *str2, size_t n);
char *s21_strncat(char *dest, const char *src, size_t n);	
size_t s21_strlen(const char *str);
char *s21_strncpy(char *dest, const char *src, size_t n);

#endif