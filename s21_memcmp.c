#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, size_t n) {
    int return_val = 0;
    if (str1 && str2) {
        for (size_t i = 0; i < n; i++) {
            char symb1 = *((char*) (str1 + i));
            char symb2 = *((char*) (str2 + i));
            if (symb1 - symb2) {
                return_val = symb1 - symb2;
                break;
            }
        }
    }
    return return_val;
}

//TESTS

// if (memcmp ("foo", "foobar", 2) == 0) puts("SUCCESS");
// if (memcmp ("foo", "foobar", 3) == 0) puts("SUCCESS");
// if (memcmp ("foo", "foobar", 4) != 0) puts("SUCCESS");
// if (memcmp ("foo", "bar", 1) != 0) puts("SUCCESS");
// if (memcmp ("foo", "bar", 3) != 0) puts("SUCCESS");