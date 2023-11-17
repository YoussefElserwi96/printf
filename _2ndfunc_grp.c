#include "main.h"


/**
 * print_unsigned - a func to print an unsigned number
 * @types: the arguments
 * @buffer: array buffers
 * @flags:  to calc the active flags in the file
 * @width: Width size
 * @precision: Precision specs
 * @size: Size specs
 * Return: chars that were printed
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}


/**
 * print_octal - a func to Print unsigned numb in octal
 * @types: the arguments
 * @buffer: array buffers
 * @flags:  to calc the active flags in the file
 * @width: Width size
 * @precision: Precision specs
 * @size: Size specs
 * Return: chars that were printed
 */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}


/**
 * print_hexadecimal - a func to Prints unsigned number in hexadecimal
 * @types: the arguments
 * @buffer: array buffers
 * @flags:  to calc the active flags in the file
 * @width: Width size
 * @precision: Precision specs
 * @size: Size specs
 * Return: chars that were printed
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}


/**
 * print_hexa_upper - a func to Print unsigned number in upper hexadecimal
 * @types: the arguments
 * @buffer: array buffers
 * @flags:  to calc the active flags in the file
 * @width: Width size
 * @precision: Precision specs
 * @size: Size specs
 * Return: chars that were printed
 */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}


/**
 * print_hexa - a func to Print hexadecimal number in lower/upper
 * @types: the arguments
 * @map_to: the array that has values
 * @buffer: the buffer array to prnt
 * @flags:  for active flags
 * @flag_ch: for more active flags
 * @width: to get width
 * @precision: Precision spec
 * @size: Size spec
 * @size: Size spec again
 * Return: printed chars
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
