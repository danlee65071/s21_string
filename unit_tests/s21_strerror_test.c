#include "unit_tests.h"

START_TEST(errors) {
  for (int i = -1000; i < 150; i++) {
    char *def = s21_strerror(i);
    char *expect = strerror(i);

    ck_assert_str_eq(def, expect);
  }
}
END_TEST

START_TEST(negativ) {
  char *def = s21_strerror(-1);
  char *expect = strerror(-1);

  ck_assert_str_eq(def, expect);
}
END_TEST

Suite *s21_strerror_test(void) {
  Suite *suite = suite_create("s21_strerror");
  TCase *tcase_core = tcase_create("case_s21_strerror");

  tcase_add_test(tcase_core, errors);
  tcase_add_test(tcase_core, negativ);

  suite_add_tcase(suite, tcase_core);

  return suite;
}