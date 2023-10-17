#include "main.h"

/**
 * Printf-receives main string
 * Return-number of characters printed
 * @format: A string containing all the desired characters
 * Return: A total count of the characters printed
 */

int _print(const char *format, ...);
int i, printed_chars = 0, buff_ind = 0;
char buffer[BUFF_SIZE];
va_list list;
if (!format) return (-1);
va_start(list, format);
for (i = 0; format[i]; i++)
{
if (format[i] != '%')
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE) print_buffer(buffer, &buff_ind);
printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
int flags = get_flags(format, &i);
int width = get_width(format, &i, list);
int precision = get_precision(format, &i, list);
int size = get_size(format, &i);
i++;
int printed = handle_print(format, &i, list, buffer, flags, width, precision, size);
if (printed == -1) return (-1);
printed_chars += printed;
}
}

print_buffer(buffer, &buff_ind);
va_end(list);
return (printed_chars);
}

void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0) write(1, buffer, *buff_ind);
*buff_ind = 0;
}
