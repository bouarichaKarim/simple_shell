#include "shell.h"
/**
 * _strlen - calculates the length of a string
 *
 * @str: string that we want to know its length
 *
 * Return: string length
 */
int _strlen(char *str)
{
	int len = 0;

	if (str == NULL)
		return (len);

	for (; str[len]; len++)
	;

	return (len);
}
/**
 * concatstr - concatenates two strings
 *
 * @str1: first string
 * @str2: second string
 *
 * Return: the concat string, NULL if it fails
 */
char *concatstr(char *str1, char *str2)
{
	char *fpath = NULL;
	int size = 0, i = 0, j = 0;

	size = _strlen(str1) + _strlen(str2) + 2;
	fpath = malloc(size * sizeof(char));
	if (fpath == NULL)
	{
		perror("Memory allocate");
		return (NULL);
	}
	while (str1[i])
	{
		fpath[i] = str1[i];
		i++;
	}
	fpath[i] = '/';
	i++;
	while (str2[j])
	{
		fpath[i] = str2[j];
		i++;
		j++;
	}
	fpath[i] = '\0';
	return (fpath);
}
/**
 * str_dup - duplicates a given string
 *
 * @str: string that you want to duplicate
 *
 * Return: duplicated string if success, NULL otherwise
 */
char *str_dup(char *str)
{
	char *dup = NULL;
	int i = 0;

	if (str == NULL)
		return (NULL);

	dup = malloc((_strlen(str) + 1) * sizeof(char));
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
