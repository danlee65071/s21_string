#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include <stdlib.h>
#include "s21_string.h"
#include <check.h>

Suite *s21_memcmp_test(void);
Suite *s21_memchr_test(void);
Suite *s21_memset_test(void);
Suite *s21_strlen_test(void);
Suite *s21_strncat_test(void);
Suite *s21_strncmp_test(void);
Suite *s21_strncpy_test(void);
<<<<<<< HEAD
Suite *s21_trim_test(void);
=======
Suite *s21_strrchr_test(void);
>>>>>>> 326e2642062fdc77d187bb6d8aaa0e6a95a37744

#endif