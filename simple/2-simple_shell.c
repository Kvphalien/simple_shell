#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - Entry point for the Levishell program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters;

	printf("Levishell!\n");

	while (1)
	{
		printf("Levishell$ ");
		characters = getline(&buffer, &bufsize, stdin);

		if (characters == -1)
		{
			printf("\n");
			break;
		}
		buffer[characters - 1] = '\0';

		if (access(buffer, X_OK) == 0)
		{
			pid_t pid = fork();

			if (pid == 0)
			{
				execve(buffer, (char *[]){buffer, NULL}, NULL);
				perror("execve");
				exit(EXIT_FAILURE);
			}
			else if (pid < 0)
			{
				perror("fork");
			}
			else
			{
				wait(NULL);
			}
		}
		else
		{
			printf("Command not found in Levishell\n");
		}
	}

	free(buffer);
	return (EXIT_SUCCESS);
}

