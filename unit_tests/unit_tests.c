#include "unit_tests.h"

void case_test(Suite *s, int *fail)
{
    SRunner *runner = srunner_create(s);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    *fail = srunner_ntests_failed(runner);
    srunner_free(runner);
}

int main()
{
    Suite* (*utils_tests_funcs[]) () = {s21_memcmp_test, \
                                        s21_memchr_test, \
                                        s21_memset_test, \
                                        s21_strlen_test, \
                                        s21_strncat_test, \
                                        s21_strncmp_test, \
                                        s21_strncpy_test, \
                                        s21_strerror_test, \
                                        s21_trim_test, \
                                        s21_memcpy_test, \
                                        s21_strchr_test, \
                                        s21_strpbrk_test, \
                                        s21_to_upper_test
                                       };
    uint8_t utils_tests_count = sizeof(utils_tests_funcs) / sizeof(*utils_tests_funcs);
    uint8_t fail = 0;
    uint8_t num_test = utils_tests_count;
    int result[num_test];

    for (uint8_t i = 0; i < utils_tests_count; i++)
        case_test(utils_tests_funcs[i](), result);
    for (uint8_t i = 0; i < num_test; i++)
        if (result[i] != 0)
            fail = 1;
    return fail;
}
