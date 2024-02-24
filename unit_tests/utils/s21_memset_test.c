#include "unit_tests.h"

START_TEST(abrakadabra_test) {
  char def[] = "abrakadabra";
  char expect[] = "abrakadabra";
  char repl = 'i';
  s21_size_t num_byte = 11;

  s21_memset(def, repl, num_byte);
  memset(expect, repl, num_byte);

  ck_assert_str_eq(def, expect);
}
END_TEST

START_TEST(empty_test) {
  char def[] = "";
  char expect[] = "";
  char repl = 'i';
  s21_size_t num_byte = 0;

  s21_memset(def, repl, num_byte);
  memset(expect, repl, num_byte);

  ck_assert_str_eq(def, expect);
}
END_TEST

START_TEST(zero_test) {
  char def[] = "abrakadabra";
  char expect[] = "abrakadabra";
  char repl = 'i';
  s21_size_t num_byte = 0;

  s21_memset(def, repl, num_byte);
  memset(expect, repl, num_byte);

  ck_assert_str_eq(def, expect);
}
END_TEST

START_TEST(uppercase_test) {
  char def[] = "abrakadabra";
  char expect[] = "abrakadabra";
  char repl = 'I';
  s21_size_t num_byte = 5;

  s21_memset(def, repl, num_byte);
  memset(expect, repl, num_byte);

  ck_assert_str_eq(def, expect);
}
END_TEST

START_TEST(num_test) {
  char def[] = "abrakadabra";
  char expect[] = "abrakadabra";
  char repl = '4';
  s21_size_t num_byte = 11;

  s21_memset(def, repl, num_byte);
  memset(expect, repl, num_byte);

  ck_assert_str_eq(def, expect);
}
END_TEST
// тестовый набор Suite, который может содержать несколько групп тестов TCase.
Suite *s21_memset_test(void) {
  Suite *suite = suite_create("s21_memset");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("case_s21_memset");

  // Добавление теста в группу тестов.
  tcase_add_test(tcase_core, abrakadabra_test);
  tcase_add_test(tcase_core, empty_test);
  tcase_add_test(tcase_core, zero_test);
  tcase_add_test(tcase_core, uppercase_test);
  tcase_add_test(tcase_core, num_test);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}