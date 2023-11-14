#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define CUSTOM_PROMPT "LeviShell$ "
#define CUSTOM_ERROR_MSG "LeviShell: Command not found\n"

/**
 * main - This is Levi UNIX command interpreter.
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

        if (access(args[0], X_OK) == 0)
        {
            pid_t pid = fork();
            if (pid == 0)
            {
                if (execve(args[0], args, NULL) == -1)
                    perror("Error");
                exit(EXIT_FAILURE);
            }
            else if (pid < 0)
            {
                perror("Error");
            }
            else
            {
                wait(NULL);
            }
        }
        else
        {
            printf("%s", CUSTOM_ERROR_MSG);
        }
    }

    free(buffer);
    return (EXIT_SUCCESS);
}

