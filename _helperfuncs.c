#include "main.h"

/**
 * is_printable - a func to check if
 * its printable
 * @c: what needs to be checked
 * Return: 1 if char is printable, 0 if not
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - a func that Appends
 * ascci in hexadecimal code to the buffer
 * @buffer: Array
 * @i: Index
 * @ascii_code: ASSCI
 * Return: Always 3
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - to check if its a digit or not
 * @c: what needs to be checked
 * Return: 1 if it is a number, 0 if its not
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - a func that converts
 * @num: Number
 * @size: type
 * Return: value
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - a func that converts
 * a number to a specified size
 * @num: Number
 * @size: type to be converted to
 * Return: value
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
