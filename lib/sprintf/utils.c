#include "s21_sprintf.h"

bool is_in_str(const char c, const char* str)
{
    uint8_t len = s21_strlen(str);
    for (uint8_t i = 0; i < len; i++)
        if (c == str[i])
            return true;
    return false;
}

bool is_digit(const char c)
{
    return (c >= '0' && c <= '9') ? true : false;
}

void* extended_realloc(void* ptr, s21_size_t size)
{
    void *result = ptr ? realloc(ptr, size) : malloc(size);
    if (size && !result)
        fatal(0);
    return result;
}

void fatal(int errnum)
{
    write(2, s21_strerror(errnum), s21_strlen(s21_strerror(errnum)));
    exit(errnum);
}

int extract_num_from_format(const char* format, int* i)
{
    int num = 0;

     while (is_digit(format[*i]))
     {
        num = num * 10 + format[*i] - '0';
        (*i)++;
     }
     return num;
}

s21_size_t	s21_strlcpy(char *restrict dst, const char *restrict src, s21_size_t dstsize)
{
	s21_size_t	i;
	s21_size_t	len_src;

	if (!dst || !src)
		return (0);
	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	i = 0;
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len_src);
}

char* s21_strdup(const char *s1)
{
	s21_size_t	len_s1;
	char	*new_str;

	len_s1 = s21_strlen(s1);
	new_str = malloc(sizeof(char) * (len_s1 + 1));
	if (new_str == NULL)
		return (NULL);
	s21_strlcpy(new_str, s1, len_s1 + 1);
	return (new_str);
}

void fill_new_str(char *new_str, char const *s1, char const *s2, \
						s21_size_t len_new_str)
{
	s21_size_t	i;
	s21_size_t	len_s1;

	len_s1 = s21_strlen(s1);
	i = 0;
	while (i < len_s1)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (i < len_new_str)
	{
		new_str[i] = s2[i - len_s1];
		i++;
	}
	new_str[i] = '\0';
}

char* s21_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	s21_size_t	len_s1;
	s21_size_t	len_s2;
	s21_size_t	len_new_str;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = s21_strlen(s1);
	len_s2 = s21_strlen(s2);
	len_new_str = len_s1 + len_s2;
	new_str = malloc(sizeof(char) * (len_new_str + 1));
	if (!new_str)
		return (NULL);
	fill_new_str(new_str, s1, s2, len_new_str);
	return (new_str);
}

bool get_flag_value(t_flags* flags, char flag)
{
    for (uint8_t i = 0; i < NUM_FLAGS; i++)
    {
        if (flags[i].flag == flag)
            return flags[i].is;
    }
    return false;
}

bool get_spec_value(t_specifiers* specifiers, char specifier)
{
    for (uint8_t i = 0; i < NUM_SPECIFIERS; i++)
    {
        if (specifiers[i].specifier == specifier)
            return specifiers[i].is;
    }
    return false;
}

void free_line(char** line)
{
    if (line && *line)
    {
        free(*line);
        *line = NULL;
    }   
}

char* strjoin_with_free(char** s1, char** s2)
{
	char* result = s21_strjoin(*s1, *s2);
	free_line(s1);
	free_line(s2);
	return result;
}

char* char_to_str(char c)
{
	char* res = extended_realloc(s21_NULL, 2);
	res[0] = c;
	res[1] = '\0';
	return res;
}

char* s21_itoa(long long value, int radix)
{
	char* result = s21_NULL;
	if (value == 0)
		result = s21_strdup("0");
	else
	{
		for (; value; value /= radix)
		{
			char* str_digit = char_to_str(DIGITS[value % radix]);
			result = !result ? str_digit : strjoin_with_free(&result, &str_digit);
		}
	}
	return result;
}

char* s21_ftoa(long double num, int precision)
{
	long double integer_part;
	long double fractional_part;
	int sign = num < 0 ? -1 : 1;
	char* result = s21_NULL;
	
	fractional_part = modfl(num, &integer_part) * sign;
	integer_part = precision <= 0 ? roundl(num) : integer_part;
	result = s21_itoa((long long)integer_part, 10);
	if (precision)
	{
		fractional_part = roundl(fractional_part * powl(10, precision));
		char* dot_str = s21_strdup(".");
		char* frac_str = s21_itoa((int)fractional_part, 10);
		result = strjoin_with_free(&result, &dot_str);
		result = strjoin_with_free(&result, &frac_str);
	}
	return result;
}
