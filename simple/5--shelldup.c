#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define CUSTOM_PROMPT "LeviShell$ "
#define CUSTOM_ERROR_MSG "LeviShell: Command not found\n"

/**
 * handle_input - Handles the user input
 * @buffer: The buffer containing the user input
 *
 * Return: Returns 1 if the shell should continue, otherwise 0.
 */
int handle_input(char *buffer);

/**
 * execute_command - Executes the provided command
 * @buffer: The buffer containing the command to be executed
 */
void execute_command(char *buffer);

/**
 * print_environment - Prints the current environment
 */
void print_environment(void);

/**
 * main - Simple shell program entry point
 *
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
			break;

		if (strcmp(buffer, "env") == 0)
			print_environment();

		execute_command(buffer);
	}

	free(buffer);
	return (EXIT_SUCCESS);
}

/**
 * execute_command - Executes the provided command
 * @buffer: The buffer containing command to be executed
 */
void execute_command(char *buffer)
{
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

	/* Implement command execution logic */
}

/**
 * print_environment - Prints current environment
 */
void print_environment(void)
{
	char **environ = NULL;
	int i = 0;

	environ = __environ;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

