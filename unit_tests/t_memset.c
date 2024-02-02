#include "tests.h"

START_TEST(abrakadabra_test) {
  char def[] = "abrakadabra";
  char expect[] = "abrakadabra";
  char repl = 'i';
  size_t num_byte = 12;

  my_memset(def, repl, num_byte);
  memset(expect, repl, num_byte);

  ck_assert_ptr_eq(def, expect);
}
END_TEST

START_TEST(empty_test) {
  char def[] = "";
  char expect[] = "";
  char repl = 'i';
  size_t num_byte = 0;

  my_memset(def, repl, num_byte);
  memset(expect, repl, num_byte);

  ck_assert_ptr_eq(def, expect);
}
END_TEST

START_TEST(zero_test) {
  char def[] = "abrakadabra";
  char expect[] = "abrakadabra";
  char repl = 'i';
  size_t num_byte = 0;

  my_memset(def, repl, num_byte);
  memset(expect, repl, num_byte);

  ck_assert_ptr_eq(def, expect);
}
END_TEST

START_TEST(uppercase_test) {
  char def[] = "abrakadabra";
  char expect[] = "abrakadabra";
  char repl = 'I';
  size_t num_byte = 5;

  my_memset(def, repl, num_byte);
  memset(expect, repl, num_byte);

  ck_assert_ptr_eq(def, expect);
}
END_TEST

START_TEST(num_test) {
  char def[] = "abrakadabra";
  char expect[] = "abrakadabra";
  char repl = '4';
  size_t num_byte = 12;

  my_memset(def, repl, num_byte);
  memset(expect, repl, num_byte);

  ck_assert_ptr_eq(def, expect);
}
END_TEST
// тестовый набор Suite, который может содержать несколько групп тестов TCase.
Suite *memset_suite(void) {
  Suite *suite = suite_create("memset_suite");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("tc_memset");

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