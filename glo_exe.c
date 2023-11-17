#include "main.h"

/**
 * execute_operation - function that executes the operation
 * @operation: string
 * Return: Always 0
 */

void execute_operation(const char *operation)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execlp(operation, operation, (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
