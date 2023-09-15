#include "shell.h"
/**
 * ak_str - A function that checks the length of a string
 * @str: The string whose length is to be returned
 * Return: Length of string
 */
size_t ak_strl(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}
