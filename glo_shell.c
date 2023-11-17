#include "main.h"

/**
 * read_operation - Function that reads input for operation
 * @operation: Pointer to a character array
 * @size: Size of the character array
 *
 * Return: Always 0
 */
void read_operation(char *operation, size_t size)
{
	if (fgets(operation, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			my_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			my_print("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	operation[strcspn(operation, "\n")] = '\0';
}
