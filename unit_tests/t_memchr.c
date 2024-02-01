#include "tests.h"

START_TEST(empty_test) {
  char str[10] = "";
  int find_byte = '\0';
  size_t num_byte = 0;

  ck_assert_ptr_eq(my_memchr(str, find_byte, num_byte),
                   memchr(str, find_byte, num_byte));
}
END_TEST

// тестовый набор Suite, который может содержать несколько групп тестов TCase.
Suite *memset_suite(void) {
  Suite *suite = suite_create("memchr_suite");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("tc_memchr");

  // Добавление теста в группу тестов.
  tcase_add_test(tcase_core, empty_test);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}