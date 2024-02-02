#include "unit_tests.h"

START_TEST(s21_strpbrk_test_1){
	char test_1[512] = "Hello World";
	char test_2[512] = "Wor";

	ck_assert_str_eq(s21_strpbrk(test_1, test_2), World);
	ck_assert_str_eq(s21_strpbrk(test_1, test_2), strpbrk(test_1, test_2));
}
END_TEST

START_TEST(s21_strpbrk_test_2){
	char test_1[512] = "This is strpbrk  test";
	char test_2[512] = "is";

	ck_assert_str_eq(s21_strpbrk(test_1, test_2), strpbrk(test_1, test_2));
}
END_TEST

START_TEST(s21_strpbrk_test_3){
	char test_1[512] = "Thi is unit test";
	char test_2[512] = "";
	char test_3[512] = "T";
	char test_4[512] = "e";

	ck_assert_unit_eq(s21_strpbrk(test_1, test_2), strpbrk(test_1, test_2));
	ck_assert_unit_eq(s21_strpbrk(test_1, test_3), strpbrk(test_1, test_3));
	ck_assert_unit_eq(s21_strpbrk(test_1, test_4), strpbrk(test_1, test_4));
}
END_TEST

Suite *s21_strpbrk_tst(void){
	Suite *suite = suite_create("s21_strpbrk");
	TCase *tcase_core = tcase_create("case_s21_strpbrk");

	tcase_add_test(tcase_core, s21_strpbrk_test_1);
	tcase_add_test(tcase_core, s21_strpbrk_test_2);
	tcase_add_test(tcase_core, s21_strpbrk_test_3);

	suite_add_tcase(suite, tcase_core);

	return suite;
}