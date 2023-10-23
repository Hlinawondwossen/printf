#include "main.h"

/**
 * _printf -This  print project prinstring 
 * @format: points string and charater 
 * Return: it print null byte and string
 */

int _printf(const char *format, ...)
{
	int x;
	int count_char = 0;
	va_list args;
	char *str;
	void *ptr;

	va_start(args, format);

	for (x = 0; format[x] != '\0'; x++)
	{
		if (format[x] == '%')
		{
			x++; /* Move to next char '%' */
			if (format[x] == 's')
			{
				str = va_arg(args, char *);
				if (str != NULL)
					count_char += printstr(str);
				else
					count_char += printstr("(null)");
			}
			else if (format[x] == 'p')
			{
				ptr = va_arg(args, void *);
				if (ptr != NULL)
					count_char += putaddress(ptr);
				else
					count_char += printstr("(null)");
			}
			else
				count_char += print_format(format[x], args);
		}
		else /* Print char*/
			count_char += printchar(format[x]);
	}
	va_end(args);
	return (count_char);
}
