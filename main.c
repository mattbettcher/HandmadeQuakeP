
#include "types.h"

// globals - I feel this is a bad way to handle this.
i32 argc;
u8 **argv;

i32 Q_strcmp(u8 *s1, u8 *s2)
{
	while (*s1 == *s2)
	{
		if (!*s1) return 0;
		s1++; s2++;
	}
	return ((*s1 < *s2) ? -1 : 1);
}

i32 Q_atoi(u8 *str)
{
	i32 sign;
	i32 val = 0;
	u8 c;

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

i32 CheckParam(u8 *param)
{
	for (i32 i = 0; i < argc; i++)
	{
		if (!Q_strcmp(param, argv[i]))
			return i;
	}
	return 0;
}



i32 q_main()
{
	i32 test = CheckParam("-hello");
	i32 test2 = CheckParam("-alpha");
	i32 num = Q_atoi(argv[2]);

	return 1;
}