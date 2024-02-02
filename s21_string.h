#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdio.h>
#include <stdlib.h>

void *my_memchr(const void *str, int c, size_t n);
void *my_memset(void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);

#endif