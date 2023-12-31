#include "shell.h"

size_t _strspn(const char *str1, const char *str2);
char *_strchr(const char *s, int c);
size_t _strpn(const char *str1, const char *str2);
/**
 * _strcat - concatenate two strings
 * @desk: first string
 * @src: second string
 * Return: combined string
 */

char *_strcat(char *desk, char *src)
{
	int d = 0;
	int s = 0;

	while (desk[d] != '\0')
	{
		d++;
	}
	while (src[s] != '\0')
	{
		desk[d] = src[s];
		d++;
		s++;
	}
	desk[d] = '\0';
	return (desk);
}

/**
 * _strcmp - compare two strings
 * @s1: string1
 * @s2: string2
 * Return: 0 if equal
 */

int _strcmp(char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] != '\0' && s2[a] != '\0'; a++)
	{
		if (s1[a] != s2[a])
			return ((int)s1[a] - s2[a]);
	}
	return (0);
}

/**
 * _strlen - calculate the length of a string
 * @str: string concerned
 * Return: length of the string
 */

int _strlen(char *str)
{
	int len = 0;

	while (*(str + len) != '\0')
	{
		len++;
	}

	return (len);
}

/**
 *_strncmp -  compare two string with first x bytes
 *@s1: string1
 *@s2: string2
 *@x: number of bytes
 * Return: 0 if equal
 */

size_t _strncmp(char *s1, char *s2, size_t x)
{
	size_t i, j;

	for (j = 0; s1[j] != '\0' && j < x; j++)
	{
		i = s1[j] - s2[j];

		if (i != 0)
		{
			return (i);
		}
	}
	return (0);
}

/**
 * _strcpy - copies a string to a destination
 * @desk: destination
 * @src: source of the string
 * Return: pointer to the copy
 */

char *_strcpy(char *desk, char *src)
{
	int i = 0;

	while (*(src + i) != '\0')
	{
		*(desk + i) = *(src + i);
		++i;
	}
	*(desk + i) = *(src + i);

	return (desk);
}

/**
 * _strtok - divides a string into tokens
 * @str: string to tokenize
 * @delim: delimiter of the string
 * Return: pointer to the tokens
 */
char *_strtok(char *str, const char *delim)
{
	static char *s;

	if (str)
		s = str;
	else if (!s)
		return (0);
	str = s + _strspn(s, delim);
	s = str + _strpn(str, delim);
	if (s == str)
		return (s = 0);
	s = *s ? *s = 0, s + 1 : 0;
	return (str);
}

/**
 * _strpn - locate the first occcurence of a string
 * @str1: string2
 * @str2: string1
 * Return: length of the segment
 */

size_t _strpn(const char *str1, const char *str2)
{
	size_t i = 0;

	while (*str1)
	{
		if (_strchr(str2, *str1))
			return (i);
		str1++, i++;
	}
	return (i);
}

/**
 * _strspn - get max length of a segment
 * @str1: string to find the length
 * @str2: string2
 * Return: length of the string
 */

size_t _strspn(const char *str1, const char *str2)
{
	size_t i = 0;

	while (*str1 && _strchr(str2, *str1++))
		i++;
	return (i);
}

/**
 * _strchr - first occurence of a string
 * @str: string to search for occurrence.
 * @c: character to locate
 * Return: pointer to string
 */

char *_strchr(const char *str, int c)
{
	while (*str != (char)c)
		if (!*str++)
			return (0);
	return ((char *)str);
}
