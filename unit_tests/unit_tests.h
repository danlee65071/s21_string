#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include <check.h>
#include <stdlib.h>
#include "s21_string.h"

// utils
Suite *s21_memcmp_test(void);
Suite *s21_memchr_test(void);
Suite *s21_memset_test(void);
Suite *s21_strlen_test(void);
Suite *s21_strncat_test(void);
Suite *s21_strncmp_test(void);
Suite *s21_strncpy_test(void);
Suite *s21_strerror_test(void);
Suite *s21_memcpy_test(void);
Suite *s21_trim_test(void);
Suite *s21_strrchr_test(void);
Suite *s21_strchr_test(void);
Suite *s21_strpbrk_test(void);
Suite *s21_to_upper_test(void);
Suite *s21_to_lower_test(void);
Suite *s21_strstr_test(void);
Suite *s21_strcspn_test(void);
Suite *s21_insert_test(void);
Suite *s21_strtok_test(void);

#endif