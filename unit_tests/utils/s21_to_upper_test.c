#include "unit_tests.h"

START_TEST(upper_test1)
{
    char str[] = " ";
    char expect[] = " ";
    char *upper = s21_to_upper(str);

    ck_assert_str_eq(upper, expect);
}
END_TEST

START_TEST(upper_test2)
{
    char str[] = "";
    char expect[] = "";
    char *upper = s21_to_upper(str);

    ck_assert_str_eq(upper, expect);
}
END_TEST

START_TEST(upper_test3)
{
    char str[] = "abra";
    char expect[] = "ABRA";
    char *upper = s21_to_upper(str);

    ck_assert_str_eq(upper, expect);
}
END_TEST

START_TEST(upper_test4)
{
    char str[] = "abra kadabra";
    char expect[] = "ABRA KADABRA";
    char *upper = s21_to_upper(str);

    ck_assert_str_eq(upper, expect);
}
END_TEST

START_TEST(upper_test5)
{
    char str[] = "5-5*5";
    char expect[] = "5-5*5";
    char *upper = s21_to_upper(str);

    ck_assert_str_eq(upper, expect);
}
END_TEST

Suite *s21_to_upper_test(void)
{
    Suite *suite = suite_create("s21_to_upper");
    TCase *tcase_core = tcase_create("case_s21_to_upper");

    tcase_add_test(tcase_core, upper_test1);
    tcase_add_test(tcase_core, upper_test2);
    tcase_add_test(tcase_core, upper_test3);
    tcase_add_test(tcase_core, upper_test4);
    tcase_add_test(tcase_core, upper_test5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}