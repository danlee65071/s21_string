#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include <check.h>
#include <stdlib.h>

#include "../s21_string.h"

Suite *s21_memcmp_test(void);
Suite *memchr_suite(void);
Suite *memset_suite(void);

#endif