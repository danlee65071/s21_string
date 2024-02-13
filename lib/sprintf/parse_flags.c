#include "s21_sprintf.h"

void parse_flags(const char *format, t_sprintf *sprintf_args, int *i) {
  while (is_in_str(format[*i], FLAGS)) {
    for (uint8_t j = 0; j < NUM_FLAGS; j++)
      if (sprintf_args->flags[j].flag == format[*i])
        sprintf_args->flags[j].is = true;
    (*i)++;
  }
}
