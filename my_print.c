#include "main.h"

/**
 * my_print - prints output
 * @string: string
 * Return: Always 0
 */

void my_print(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}
