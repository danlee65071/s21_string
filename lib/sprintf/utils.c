#include "s21_sprintf.h"


bool is_in_str(const char c, const char* str)
{
    uint8_t len = s21_strlen(str);
    for (uint8_t i = 0; i < len; i++)
        if (c == str[i])
            return true;
    return false;
}
