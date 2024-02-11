#include "s21_sprintf.h"

void init_flags(t_sprintf* sprintf_args)
{
    for (uint8_t i = 0; i < NUM_FLAGS; i++)
    {
        sprintf_args->flags[i].flag = FLAGS[i];
        sprintf_args->flags[i].is = false;
    }
}
