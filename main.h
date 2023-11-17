#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>

int main(void);
void my_print(const char *string);
void shell_prompt(void);
void read_operation(char *operation, size_t size);
void execute_operation(const char *operation);

#endif /* MAIN_H */

