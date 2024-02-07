#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list arglist;
  int count = 0;

  va_start(arglist, format);
  count = parse_format(&str, format, arglist);
  va_end(arglist);

  return count;
}

const char s21_sprintf_specifiers[] = "cdfsugGeExXop%";

t_flags init_flags(t_flags *flags) {
  flags->specifier = 0;
  flags->minus = false;
  flags->sign = false;
  flags->hashtag = false;
  flags->zero = false;
  flags->width = 0;
  flags->precision = 0;
  flags->length = 0;
  flags->star = false;

  return *flags;
}

// Спецификатор формата для печатающих функций следует прототипу:
// %[флаги][ширина][.точность][длина]спецификатор.

//
int parse_format(char **str, const char *format, va_list arglist) {
  int count = 0;
  t_flags flags;
  int format_len = s21_strlen(format);
  for (int i = 0; i < format_len; i++) {
    flags = init_flags(&flags);
    if (format[i] == '%') {
      process_percent(str, format, arglist, &flags, &count, &(format[++i]));
    } else {
      (*str)[count++] = format[i];
    }
  }

  return count;
}

// обрабатывает символ % в форматной строке
void process_percent(char **str, char *format, va_list arglist, t_flags *flags,
                     int *count, int *i) {
  if (format[*i] == ' ') {
    (*str)[*count++] = format[(*i)++];
  }
  parse_flags(format, arglist, flags, i);
  if (is_type(format[*i])) {
    process_type(str, format[*i], arglist, flags, i);
  }
}

// проверяет, является ли текущий символ формата допустимым спецификатором типа
char parse_flags(const char *format, va_list arglist, t_flags *flags, int *i) {
  while (*format == '-' || *format == '+' || *format == '#' || *format == '0') {
    switch (*format) {
      case '-':
        flags->minus = true;
        break;
      case '+':
        flags->sign = true;
        break;
      case '#':
        flags->hashtag = true;
        break;
      case '0':
        flags->zero = true;
        break;
    }
    format++;
  }
  return (char *)format;
}

// добавить код, который будет обрабатывать каждый тип данных согласно
// спецификатору %.
void process_type(char **str, char format, va_list arglist, t_flags *flags,
                  int *count) {
  t_flags flags;
  flags->specifier = format;
  handle_specifier(*str + *count, arglist, *flags);
  *count += s21_strlen(*str + *count);
}

void handle_specifier(char *str, va_list arglist, t_flags flags) {
  if (flags.specifier == 'c') {
    handle_char();
  } else if (flags.specifier == 'd' || flags.specifier == 'i') {
    handle_int();
  } else if (flags.specifier == 'e' || flags.specifier == 'E') {
    handle_science_notation();
  } else if (flags.specifier == 'f') {
    handle_float();
  } else if (flags.specifier == 'g' || flags.specifier == 'G') {
    handle_shrotest_float();
  } else if (flags.specifier == 'o') {
    handle_unsigned_eight();
  } else if (flags.specifier == 's') {
    handle_char();
  } else if (flags.specifier == 'u') {
    handle_unsigned_ten();
  } else if (flags.specifier == 'x' || flags.specifier == 'X') {
    handle_unsigned_sixteenth();
  } else if (flags.specifier == 'p') {
    handle_pointer();
  } else if (flags.specifier == 'n') {
    handle_char_before();
  } else if (flags.specifier == '%') {
    str[0] = '%';
  }
}

void handle_char() {}
void handle_int() {}
void handle_science_notation() {}
void handle_float() {}
void handle_shrotest_float() {}
void handle_unsigned_eight() {}
void handle_unsigned_ten() {}
void handle_unsigned_sixteenth() {}
void handle_pointer() {}
void handle_numchar_before() {}

// добавить логику внутри этой функции, чтобы определить, является ли символ
// допустимым спецификатором типа, и возвратить соответствующий результат.
int is_type(char format) {
  int i = 0;
  int found = 0;
  while (s21_sprintf_specifiers[i] != '\0') {
    if (format == s21_sprintf_specifiers[i]) {
      found = 1;
    }
    i++;
  }
  return found;
}