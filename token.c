#include "holberton.h"

/**
 * token - Splits a string
 * @str: command enter for the user
 * Return: array of each word of the string splited.
 */

char **token(char *str)
{
	char *token, **tokencomplete;
	int i, tokenposition = 0;


	for (i = 0; str[i] != '\n'; i++)
		;
	str[i] = '\0';/*Coloca caracter nulo en la entrada del usuario*/

	tokencomplete = malloc(i * sizeof(char *));
	if (tokencomplete == NULL)
	{
		free(tokencomplete);
		exit(0);
	}

	token = strtok(str, " ");

	while (token != NULL)
	{
		tokencomplete[tokenposition] = token;
		tokenposition++;
		token = strtok(NULL, " ");
	}
	tokencomplete[tokenposition] = NULL;

	return (tokencomplete);
}
