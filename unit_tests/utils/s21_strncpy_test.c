#include "unit_tests.h"

START_TEST(s21_strncpy_1) {
  char str1[100] = "Hello world!";
  char str2[100] = "Rat";
  ck_assert_ptr_eq(strncpy(str1, str2, 5), s21_strncpy(str1, str2, 5));
}
END_TEST

START_TEST(s21_strncpy_2) {
  char str1[100] = "";
  char str2[100] = "Rat";
  ck_assert_ptr_eq(strncpy(str1, str2, 5), s21_strncpy(str1, str2, 5));
}
END_TEST

START_TEST(s21_strncpy_3) {
  char str1[100] = "Hello world!";
  char str2[100] = "";
  ck_assert_ptr_eq(strncpy(str1, str2, 5), s21_strncpy(str1, str2, 5));
}
END_TEST

START_TEST(s21_strncpy_4) {
  char str1[100] = "Rat";
  char str2[100] = "Hello world!";
  ck_assert_ptr_eq(strncpy(str1, str2, 8), s21_strncpy(str1, str2, 8));
}
END_TEST

START_TEST(s21_strncpy_5) {
  char str1[100] = "Rat";
  char str2[100] = "Hell\0o world!";
  ck_assert_ptr_eq(strncpy(str1, str2, 8), s21_strncpy(str1, str2, 8));
}
END_TEST

Suite *s21_strncpy_test(void) {

  Suite *s = suite_create("s21_strncpy");
  TCase *tc = tcase_create("case_s21_strncpy");

  tcase_add_test(tc, s21_strncpy_1);
  tcase_add_test(tc, s21_strncpy_2);
  tcase_add_test(tc, s21_strncpy_3);
  tcase_add_test(tc, s21_strncpy_4);
  tcase_add_test(tc, s21_strncpy_5);

  suite_add_tcase(s, tc);
  return s;
}
