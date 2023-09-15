#include "shell.h"
/**
 * ak_strcmp - A function use to compare two strings
 * @s1: The first string
 * @s2: The second string
 * Return: 0, on success
 */
int ak_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
