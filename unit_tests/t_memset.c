#include "tests.h"

START_TEST(abrakadabra_test) {
  char beg[] = "abrakadabra";
  char expect[] = "abrakadabra";
  char repl = 'i';
  size_t num_byte = 12;

  my_memset(beg, repl, num_byte);
  memset(expect, repl, num_byte);
  ck_assert_ptr_eq(beg, expect);
}
END_TEST

// тестовый набор Suite, который может содержать несколько групп тестов TCase.
Suite *memset_suite(void) {
  Suite *suite = suite_create("memset_suite");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("tc_memset");

  // Добавление теста в группу тестов.
  tcase_add_test(tcase_core, abrakadabra_test);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}