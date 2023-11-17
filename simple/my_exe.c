#include "main.h"
/**
 * exec_operation - executes an operation
 * @argv: argument vector
 * @enva: enviromental variables
 * @line: inpute line
 * Return: Always 0
 */
int exe_operation(char **argv, char **enva, char *line)
{
	char *a_operation;
	unsigned long hashvall;
	int i = 0, retv = 0;

	retv = _getppid(argv, line);
	if (retv > 1)
	{
		retv = retv + 1;
		free_vector(argv);
		return (1);	}
	a_operation = argv[i];
	if (argv[0] == NULL)
	{
		free_vector(argv);
		free(line);
		perror("Error argv");
		return (0);	}
	hashvall = hash(a_operation);
		switch (hashvall)
		{
		case CD:
			cd_dir(argv, enva);
			break;
		case SETENV:
			set_env_var(argv);
			break;
		case UNSETENV:
			un_set_env_var(argv);
			break;
		case EXIT:
			exitshell(argv, line);
			break;
		case ENV:
			print_env(argv, enva);
			break;
		default: {
				process(argv, enva);
				return (0);	}
	}
	} return (0);
}

