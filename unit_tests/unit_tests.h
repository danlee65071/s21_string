#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include <check.h>
#include <stdlib.h>

#include "s21_string.h"

Suite *s21_memcmp_test(void);
Suite *s21_memchr_test(void);
Suite *s21_memset_test(void);
Suite *s21_strlen_test(void);
Suite *s21_strncat_test(void);
Suite *s21_strncmp_test(void);
Suite *s21_strncpy_test(void);

#endif