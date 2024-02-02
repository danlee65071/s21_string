#include "tests.h"

START_TEST(empty_test) {
  char str[10] = "";
  int find_byte = '\0';
  size_t num_byte = 0;

  ck_assert_ptr_eq(my_memchr(str, find_byte, num_byte),
                   memchr(str, find_byte, num_byte));
}
END_TEST

START_TEST(zero_test) {
  char str[15] = "endofstring";
  int find_byte = '\0';
  size_t num_byte = 12;

  ck_assert_ptr_eq(my_memchr(str, find_byte, num_byte),
                   memchr(str, find_byte, num_byte));
}
END_TEST

START_TEST(beginning_test) {
  char str[10] = "Start";
  int find_byte = 'S';
  size_t num_byte = 6;

  ck_assert_ptr_eq(my_memchr(str, find_byte, num_byte),
                   memchr(str, find_byte, num_byte));
}
END_TEST

START_TEST(middle_test) {
  char str[15] = "abrakAdabra";
  int find_byte = 'A';
  size_t num_byte = 12;

  ck_assert_ptr_eq(my_memchr(str, find_byte, num_byte),
                   memchr(str, find_byte, num_byte));
}
END_TEST

START_TEST(num_mid_test) {
  char str[15] = "abra217abra";
  int find_byte = '1';
  size_t num_byte = 12;

  ck_assert_ptr_eq(my_memchr(str, find_byte, num_byte),
                   memchr(str, find_byte, num_byte));
}
END_TEST

START_TEST(num_arr_test) {
  char str[] = {1, 3, 5, 8, 99, 7};
  int find_byte = 99;
  size_t num_byte = sizeof(int) * 6;

  ck_assert_ptr_eq(my_memchr(str, find_byte, num_byte),
                   memchr(str, find_byte, num_byte));
}
END_TEST
// тестовый набор Suite, который может содержать несколько групп тестов
// TCase.
Suite *memchr_suite(void) {
  Suite *suite = suite_create("memchr_suite");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("tc_memchr");

  // Добавление теста в группу тестов.
  tcase_add_test(tcase_core, empty_test);
  tcase_add_test(tcase_core, zero_test);
  tcase_add_test(tcase_core, beginning_test);
  tcase_add_test(tcase_core, middle_test);
  tcase_add_test(tcase_core, num_mid_test);
  tcase_add_test(tcase_core, num_arr_test);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}