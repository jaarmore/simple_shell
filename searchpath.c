#include "holberton.h"
/**
 * searchpath - take a string(command) for to search its path
 * @str: string to concatenate with a path.
 * Return: nothing.
 */
char *searchpath(char **str)
{
	char *envi, *token, *newpath, *newenvi, *pathtocheck = NULL, *slash;
	/*int position = 0;*/
	struct stat st;

	envi = _getenv("PATH");
	newenvi = malloc(_strlen(envi) + 1);
	if (newenvi == NULL)
	{
		free(newenvi);
		exit(EXIT_FAILURE);
	}

	slash = malloc(_strlen(str[0]) + 2);
	if (slash == NULL)
	{
		free(newenvi);
		free(pathtocheck);
		free(slash);
		exit(EXIT_FAILURE);
	}

	_strcpy(slash, "/"); /*Copy "/" to slash variable*/
	_strcat(slash, str[0]); /*Concatenate the user input to the "/"*/
	_strcpy(newenvi, envi); /*Copy path env value to newenvi*/

	token = strtok(newenvi, ":");

	while (token != NULL)
	{
		pathtocheck = malloc(_strlen(token) + 1 + 300);
		if (pathtocheck == NULL)
		{
			free(newenvi);
			free(pathtocheck);
			exit(EXIT_FAILURE);
		}
		pathtocheck = token;

		newpath = malloc(sizeof(char *) * (_strlen(pathtocheck) + _strlen(slash) + 1));
		if (newpath == NULL)
		{
			free(newenvi);
			free(pathtocheck);
			free(slash);
			free(newpath);
			exit(EXIT_FAILURE);
		}

		_strcpy(newpath, token);
		_strcat(newpath, slash);

		newpath[_strlen(pathtocheck) + _strlen(slash)] = '\0';

		/*If create path in newpath is an executable, return to execute*/
		if (stat(newpath, &st) == 0)
		{
			free(newenvi);
			free(slash);
			return (newpath);
		}
		/*position++;*/
		token = strtok(NULL, ":");

		free(newpath);
	}
	/*pathtocheck[position] = NULL;*/
	pathtocheck = NULL;

	free(pathtocheck);
	free(newenvi);
	free(slash);
	return (str[0]);
}
