#include "main.h"

/**
 * printstr - Prints a string.
 * @str: Pointer to a character.
 * Return: Integer.
 */

int printstr(char *str)
{
	int b, count = 0;

	for (b = 0; str[b] != '\0'; b++)
	{
		printchar(str[b]);
		count++;
	}
	return (count);
}
