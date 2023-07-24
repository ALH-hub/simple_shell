#include "shell.h"

/**
 * _strlen - return string length of a string
 * @s: the string to find the length
 * Return: the string lenth
 */

size_t _strlen(const char *s)
{
	size_t length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * _strcpy - copies a string to another
 * @src: the source string
 * @dest: the buffer to contain the copied string
 * Return: a pointer of type char to the buffer
 */

char *_strcpy(char *dest, const char *src)
{
	int i;
	int len = 0;

	while (src[len] != '\0')
		len++;

	for (i = 0; i <= len; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * _strcat - concatenate two statements
 * @dest: recepient of the output
 * @src: the string to concatenate to dest
 * Return: character pointer
 */

char *_strcat(char *dest, const char *src)
{
	int count = 0, i = 0;

	while (dest[count] != '\0')
	{
		count++;
	}
	while (src[i] != '\0')
	{
		dest[count] = src[i];
		count++;
		i++;
	}
	dest[count] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: one of the strings to compare
 * @s2: another string to compare
 * Return: 0 if succes
 */

int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/**
 * _strncmp - compares two strings
 * @s1: one of the strings to compare
 * @s2: another string to compare
 * @n: the number of bytes to compare
 * Return: 0 if succes
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && i <= n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

