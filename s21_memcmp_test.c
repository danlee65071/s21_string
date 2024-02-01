#include <check.h>

START_TEST(s21_memcpy_1) {
  size_t n1 = 3;
  char b1[1024] = "";
  char b11[1024] = "";
  char str_1_2[1024] = "TEST TEST TEST";
  ck_assert_str_eq(memcpy(b1, str_1_2, n1), s21_memcpy(b11, str_1_2, n1));
}
END_TEST

START_TEST(s21_memcpy_2) {
  size_t n2 = 5;
  char b2[1024] = "";
  char b22[1024] = "";
  char str_2_2[1024] = "THE OF \0 THE...BEST!!";
  ck_assert_str_eq(memcpy(b2, str_2_2, n2), s21_memcpy(b22, str_2_2, n2));
}
END_TEST

START_TEST(s21_memcpy_3) {
  size_t n3 = 4;
  char b3[1024] = "777 ";
  char b33[1024] = "777 ";
  char str_3_2[1024] = "S!!111231";
  ck_assert_str_eq(memcpy(b3, str_3_2, n3), s21_memcpy(b33, str_3_2, n3));
}
END_TEST

START_TEST(s21_memcpy_4) {
  size_t n4 = 4;
  char b4[1024] = "KU KU KU $! ";
  char b44[1024] = "KU KU KU $! ";
  ck_assert_str_eq(memcpy(b4, b4 + 7, n4), s21_memcpy(b44, b44 + 7, n4));
}
END_TEST