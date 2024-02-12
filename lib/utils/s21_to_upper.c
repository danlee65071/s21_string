#include "s21_string.h"

void *s21_to_upper(const char *str)
{
    char* upper_str = s21_NULL;
    if (str)
    {
        upper_str = (char*) str;
        uint8_t len = s21_strlen(str);
        for (uint8_t i = 0; i < len; i++)
            if (upper_str[i] >= 'a' && upper_str[i] <= 'z')
                upper_str[i] -= 32;
    }
    return upper_str;
}
