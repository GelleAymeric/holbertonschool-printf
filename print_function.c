#include<stdio.h>
#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * print_c - function print a single character
 *
 * @arg: list of argument
 * Return: 1, always print one character
 */

int print_c(va_list arg)
{

	char c = va_arg(arg, int);

	_putchar(c);
	return (1);
}

/**
 * print_s - function print a string
 *
 * @arg: list of argument
 *
 * Return: the count of printed characters
 */


int print_s(va_list arg)
{
	char *str = va_arg(arg, char *);
	int i = 0;

	if (str == NULL)
	{
		str = "(null)";
	}
	while (str[i])
	{
		i += write(1, &str[i], 1);
	}
	return (i);
}

/**
 * print_percent - function to handle the printing of a "%" characte
 *
 * @arg: list of argument
 *
 * Return: the count of printed characters
 */

int print_percent(va_list arg)
{
	(void)arg;
	_putchar(37);
	return (1);
}


/**
 * print_nums - function which print numbers
 *
 * @arg: list of argument
 *
 * Return: count of charactere printed
 */

int print_nums(va_list arg)
{
	long int number = va_arg(arg, int);
	int count = 0;
	long int divise = 1;
	int digit;

	if (number < 0)
	{
		count += _putchar('-');
		number *= -1 ;
	}
	if (number == 0)
	{
		return (count + _putchar('0'));
	}

	while (number / divise >= 10)
	{
		divise = divise * 10;
	}

	while (divise > 0)
	{
		digit = (number / divise) % 10;
		count += _putchar(digit + '0');
		divise = divise / 10;
	}
	return (count);
}
