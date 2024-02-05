#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdio.h>
#include <stdlib.h>

void *s21_memchr(const void *str, int c, size_t n);
void *s21_memset(void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
char *s21_strncat(char *dest, const char *src, size_t n);
size_t s21_strlen(const char *str);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strncpy(char *dest, const char *src, size_t n);
<<<<<<< HEAD
void *s21_trim(const char *src, const char *trim_chars);
=======
char *s21_strrchr(const char* str, int c);
>>>>>>> 326e2642062fdc77d187bb6d8aaa0e6a95a37744

#endif