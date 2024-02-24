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

void* extended_realloc(void* ptr, size_t size)
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

int	length_num(long unsign_n, int sign)
{
	int	len;

	len = 0;
	if (unsign_n == 0)
		return (1);
	while (unsign_n != 0)
	{
		unsign_n /= 10;
		len++;
	}
	if (sign == -1)
		len++;
	return (len);
}

void	prepare_to_itoa(int n, long *unsign_n, int *sign)
{
	if (n < 0)
	{
		*unsign_n = (-1) * (long)n;
		*sign = -1;
	}
	else
	{
		*unsign_n = n;
		*sign = 1;
	}
}

char* s21_itoa(int n)
{
	long	unsign_n;
	int		sign;
	int		len_n;
	char	*s;

	unsign_n = 0;
	sign = 0;
	prepare_to_itoa(n, &unsign_n, &sign);
	len_n = length_num(unsign_n, sign);
	s = malloc(sizeof(char) * (len_n + 1));
	if (!s)
		return (NULL);
	s[len_n] = '\0';
	len_n--;
	while (unsign_n != 0)
	{
		s[len_n] = unsign_n % 10 + '0';
		len_n--;
		unsign_n /= 10;
	}
	if (sign == -1)
		s[0] = '-';
	if (n == 0)
		s[0] = '0';
	return (s);
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

char* s21_ftoa(long double num, int precision)
{
	long double integer_part;
	long double fractional_part;

	fractional_part = modfl(num, &integer_part);
	integer_part = precision <= 0 ? roundl(num) : integer_part;
	
}
