#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#define NUM_SPECIFIERS 14
#define SPECIFIERS "cdfsugGeExXop%%"
#define LENGTH "hlL"
#define NUM_FLAGS 5
#define FLAGS "-+ #0"
#define BUF_SIZE 32

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include "s21_utils.h"
#include "s21_strerror.h"

struct s_sprintf;

typedef struct s_specifiers {
  char specifier;
  void (*process_spec) (char **str, va_list arglist,\
    struct s_sprintf* sprintf_args, int* count);
  char is;
} t_specifiers;

typedef struct s_flags {
  char flag;
  bool is;
} t_flags;

typedef struct s_sprintf {
  t_specifiers specifier[NUM_SPECIFIERS];
  t_flags flags[NUM_FLAGS];
  int width;
  int precision;
  char length;
} t_sprintf;

int s21_sprintf(char *str, const char *format, ...);
int parse_format(char **str, const char *format, va_list arglist);
void init_flags(t_sprintf* sprintf_args);
void process_percent(char **str, const char *format, \
    va_list arglist, t_sprintf* sprintf_args, int* count, int* i);

void parse_flags(const char *format, va_list arglist, t_sprintf* sprintf_args, int* i);
void parse_width(const char* format, va_list arglist, t_sprintf* sprintf_args, int* i);
void parse_precision(const char* format, va_list arglist, t_sprintf* sprintf_args, int* i);
void parse_length(const char *format, va_list arglist, t_sprintf* sprintf_args, int* i);
void parse_specifiers(const char *format, va_list arglist, t_sprintf* sprintf_args, int* i);

void fill_sign(char** str, int sign, t_sprintf* sprintf_args, int* count);
void fill_space(char** str, int num, char c, int* count);
void fill_str(char** str, char* str_value, int str_value_len, int* count);

void process_int(char **str, va_list arglist, \
  t_sprintf* sprintf_args, int* count);
void process_char(char **str, va_list arglist, \
    t_sprintf* sprintf_args, int* count);
void process_float(char **str, va_list arglist, \
    t_sprintf* sprintf_args, int* count);

bool is_in_str(const char c, const char* str);
bool is_digit(const char c);
void* extended_realloc(void* ptr, s21_size_t size);
void fatal(int errnum);
int extract_num_from_format(const char* format, int* i);
char* s21_itoa(int n);
bool get_flag_value(t_flags* flags, char flag);
char* s21_ftoa(long double num, int precision);
char* s21_strdup(const char *s1);
char* s21_strjoin(char const *s1, char const *s2);
void free_line(char** line);
char* strjoin_with_free(char** s1, char** s2);

#endif
