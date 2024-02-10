#include "unit_tests.h"

START_TEST(lower_test1) {
  char expect[] = " ";
  char str[] = " ";
  char *lower = s21_to_lower(str);

  ck_assert_str_eq(lower, expect);
  if (lower) free(lower);
}
END_TEST

START_TEST(lower_test2) {
  char expect[] = "";
  char str[] = "";
  char *lower = s21_to_lower(str);

  ck_assert_str_eq(lower, expect);
  if (lower) free(lower);
}
END_TEST

START_TEST(lower_test3) {
  char expect[] = "abra";
  char str[] = "ABRA";
  char *lower = s21_to_lower(str);

  ck_assert_str_eq(lower, expect);
  if (lower) free(lower);
}
END_TEST

START_TEST(lower_test4) {
  char expect[] = "abra kadabra";
  char str[] = "ABRA KADABRA";
  char *lower = s21_to_lower(str);

  ck_assert_str_eq(lower, expect);
  if (lower) free(lower);
}
END_TEST

START_TEST(lower_test5) {
  char expect[] = "5-5*5";
  char str[] = "5-5*5";
  char *lower = s21_to_lower(str);

  ck_assert_str_eq(lower, expect);
  if (lower) free(lower);
}
END_TEST

Suite *s21_to_lower_test(void) {
  Suite *suite = suite_create("s21_to_lower");
  TCase *tcase_core = tcase_create("case_s21_to_lower");

  tcase_add_test(tcase_core, lower_test1);
  tcase_add_test(tcase_core, lower_test2);
  tcase_add_test(tcase_core, lower_test3);
  tcase_add_test(tcase_core, lower_test4);
  tcase_add_test(tcase_core, lower_test5);

  suite_add_tcase(suite, tcase_core);

  return suite;
}