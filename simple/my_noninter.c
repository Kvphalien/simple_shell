#include "main.h"

/**
 * non_interactive - function for non interactive mode
 * @argc: argument count
 * @argv: argument vector
 * @enva: enviroment variables
 * Return: Always 0
 */

int non_interactive(int argc, char **argv, char **enva)
{
	char **tok, *prompt, *line = NULL;
	ssize_t aread;
	size_t len = 0;

	if (argc)
		/* ok */
	if (argv)
		/* ok */
	{
		my_prompt = "$$ ";
		my_print(my_prompt);
		fflush(stdout);

		aread = getline(&line, &len, stdin);
	if (aread == -1)
	{
		if (feof(stdin))
		{
			free(line);
			my_print("\n");
			exit(0);
		}
			free(line);
			perror("Error: getline");
			my_print("\n");
			exit(EXIT_SUCCESS);
		if (line[aread - 1] == '\n')
			line[aread - 1] = '\0';
		tok = tokenize(line);
		executeoperation(tok, enva, line);
		/*free_vector(tok);*/
	}
	free(line);/* */
	} return (0);
}

