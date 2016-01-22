#include "quakedef.h"

char* Q_strcpy(char *dest, const char *src)
{
	while (*src)
	{
		*dest++ = *src++;
	}
	return dest;
}

char* Q_strncpy(char *dest, const char *src, i32 count)
{
	if (count < 0) 
		return 0;

	while (*src && count)
	{
		*dest++ = *src++;
		--count;
	}

	while (count)
	{
		*dest++ = 0;
		--count;
	}
	return dest;
}

i32 Q_strlen(const char *str)
{
	i32 count = 0;
	while (str[count])
		++count;
	return count;
}

i32 Q_strcmp(const char *str1, const char *str2)
{
	while (*str1 == *str2)
	{
		if (!*str1) return 0;
		str1++; str2++;
	}
	return ((*str1 < *str2) ? -1 : 1);
}

i32 Q_atoi(const char *str)
{
	i32 sign;
	i32 val = 0;
	char c;

	if (!str) return 0;

	// negative
	sign = (*str == '-') ? -1 : 1;

	// hexadecimal
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
	{
		str += 2;
		while (true)
		{
			c = *str;
			str++;
			if (c >= '0' && c <= '9')
				val = val * 16 + c - '0';
			else if (c >= 'a' && c <= 'f')
				val = val * 16 + c - 'a' + 10;
			else if (c >= 'A' && c <= 'F')
				val = val * 16 + c - 'A' + 10;
			else
				return val*sign;
		}
	}
	// decimal
	while (true)
	{
		c = *str;
		str++;
		if (c < '0' || c > '9')
			return sign * val;
		val = val * 10 + c - '0';
	}
}