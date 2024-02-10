#include "s21_sprintf.h"

inline void init_flags(t_s21_sprintf* sprintf_args)
{
    for (uint8_t i = 0; i < NUM_FLAGS; i++)
    {
        sprintf_args->flags[i].flag = s21_sprintf_flags[i];
        sprintf_args->flags[i].count = 0;
    }
}
