#include "unit_tests.h"

START_TEST(empty_test) {
  char str1[] = "";
  char str2[] = "";
  s21_size_t num_byte = 0;

  int def = s21_strncmp(str1, str2, num_byte);
  int expect = strncmp(str1, str2, num_byte);

  if (def > 1) def = 1;
  if (expect > 1) expect = 1;

  if (def < -1) def = -1;
  if (expect < -1) expect = -1;

  ck_assert_int_eq(def, expect);
}
END_TEST

START_TEST(first_abra) {
  char str1[] = "abra";
  char str2[] = "";
  s21_size_t num_byte = 0;

  int def = s21_strncmp(str1, str2, num_byte);
  int expect = strncmp(str1, str2, num_byte);

  if (def > 1) def = 1;
  if (expect > 1) expect = 1;

  if (def < -1) def = -1;
  if (expect < -1) expect = -1;

  ck_assert_int_eq(def, expect);
}
END_TEST

START_TEST(second_abra) {
  char str1[] = "";
  char str2[] = "abra";
  s21_size_t num_byte = 0;

  int def = s21_strncmp(str1, str2, num_byte);
  int expect = strncmp(str1, str2, num_byte);

  if (def > 1) def = 1;
  if (expect > 1) expect = 1;

  if (def < -1) def = -1;
  if (expect < -1) expect = -1;

  ck_assert_int_eq(def, expect);
}
END_TEST

START_TEST(abra_twice) {
  char str1[] = "abra";
  char str2[] = "abra";
  s21_size_t num_byte = 4;

  int def = s21_strncmp(str1, str2, num_byte);
  int expect = strncmp(str1, str2, num_byte);

  if (def > 1) def = 1;
  if (expect > 1) expect = 1;

  if (def < -1) def = -1;
  if (expect < -1) expect = -1;

  ck_assert_int_eq(def, expect);
}
END_TEST

START_TEST(one_byte) {
  char str1[] = "abra";
  char str2[] = "abra";
  s21_size_t num_byte = 1;

  int def = s21_strncmp(str1, str2, num_byte);
  int expect = strncmp(str1, str2, num_byte);

  if (def > 1) def = 1;
  if (expect > 1) expect = 1;

  if (def < -1) def = -1;
  if (expect < -1) expect = -1;

  ck_assert_int_eq(def, expect);
}
END_TEST

START_TEST(first_five) {
  char str1[] = "abrakadabra";
  char str2[] = "abra";
  s21_size_t num_byte = 5;

  int def = s21_strncmp(str1, str2, num_byte);
  int expect = strncmp(str1, str2, num_byte);

  if (def > 1) def = 1;
  if (expect > 1) expect = 1;

  if (def < -1) def = -1;
  if (expect < -1) expect = -1;

  ck_assert_int_eq(def, expect);
}
END_TEST

Suite *s21_strncmp_test(void) {
  Suite *suite = suite_create("s21_strncmp");

  TCase *tcase_core = tcase_create("case_s21_strncmp");

  tcase_add_test(tcase_core, empty_test);
  tcase_add_test(tcase_core, first_abra);
  tcase_add_test(tcase_core, second_abra);
  tcase_add_test(tcase_core, abra_twice);
  tcase_add_test(tcase_core, one_byte);
  tcase_add_test(tcase_core, first_five);

  suite_add_tcase(suite, tcase_core);
  return suite;
}