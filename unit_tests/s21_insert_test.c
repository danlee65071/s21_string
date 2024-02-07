#include "unit_tests.h"

START_TEST(s21_insert_1) {
  char *res1 = s21_NULL;
  res1 = s21_insert("1263518@#@#@##@", "hwd", 1);
  if (res1) {
    ck_assert_str_eq(res1, "1hwd263518@#@#@##@");
    free(res1);
  }
}
END_TEST

START_TEST(s21_insert_2) {
  char *res1 = s21_NULL;
  res1 = s21_insert("126351865238165ygdUQ", "pq9uhwd", 8);
  if (res1) {
    ck_assert_str_eq(res1, "12635186pq9uhwd5238165ygdUQ");
    free(res1);
  }
}
END_TEST

START_TEST(s21_insert_3) {
  char *res1 = s21_NULL;
  res1 = s21_insert("12635186523816QWDQWDQWDQWD5ygdUQ", "pq9uhwd", 15);
  if (res1) {
    ck_assert_str_eq(res1, "12635186523816Qpq9uhwdWDQWDQWDQWD5ygdUQ");
    free(res1);
  }
}
END_TEST

Suite *s21_insert_test(void) {
  Suite *suite = suite_create("s21_insert");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("case_s21_insert");

  // Добавление теста в группу тестов.
  tcase_add_test(tcase_core, s21_insert_1);
  tcase_add_test(tcase_core, s21_insert_2);
  tcase_add_test(tcase_core, s21_insert_3);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}