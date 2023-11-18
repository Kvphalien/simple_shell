#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * mainCode - Entry point
 *
 * Description: A beautiful code that passes betty checks
 *
 * Return: Always 0 (Success)
 */
int mainCode(void);

/**
 * levishellEntryPoint - Entry point for the Levishell program
 *
 * Return: Always 0 (Success)
 */
int levishellEntryPoint(void);

/**
 * leviUnixCommandInterpreter - Levi UNIX command interpreter.
 *
 * Return: Always 0.
 */
int leviUnixCommandInterpreter(void);

/**
 * simpleUnixCommandInterpreter - Simple UNIX command interpreter.
 *
 * Return: Always 0.
 */
int simpleUnixCommandInterpreter(void);

/**
 * simpleShellProgram - Simple shell program entry point
 * Return: Always 0.
 */
int simpleShellProgram(void);

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

#endif /* MAIN_H */

