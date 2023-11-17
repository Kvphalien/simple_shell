#include "main.h"

/**
 * main - entry point
 *
 * Return: Always 0
 */

int main(void)
{
	char operation[120];

	while (true)
	{
		shell_prompt();
		read_operation(operation, sizeof(operation));
		execute_operation(operation);
	}
	return (0);
}

