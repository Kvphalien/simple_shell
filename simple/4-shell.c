#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define CUSTOM_PROMPT "LeviShell$ "
#define CUSTOM_ERROR_MSG "LeviShell: Command not found\n"

/**
 * main - Simple shell program entry point
 * Return: Always 0.
 */
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters;

	while (1)
	{
		printf("%s", CUSTOM_PROMPT);
		characters = getline(&buffer, &bufsize, stdin);
		if (characters == -1)
		{
			printf("\n");
			break;
		}
		buffer[characters - 1] = '\0';

		if (strcmp(buffer, "exit") == 0)
		{
			break;
		}

		char *token;
		char *args[10];
		int i = 0;

		token = strtok(buffer, " ");
		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;

		/* Implement command execution logic here */
	}

	free(buffer);
	return (EXIT_SUCCESS);
}

