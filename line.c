#include "shell.h"

/**
 * read_line - read stdin.
 *
 * Return: pointer to sting.
 */
char *read_line(void)
{
	char *read = NULL;
	size_t command_size = 0;
	ssize_t nread = getline(&read, &command_size, stdin);
	/* if getline function has failed*/
	if (nread == -1)
	{
		/**
		* handle if we at the end of the file or the user
		* entered ctrl d
		*/
		if (feof(stdin))
		{
			/*avoid leaking of the memory*/
			free(read);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(read);
			perror("error in reading the input");
			exit(EXIT_SUCCESS);
		}
	}
	return (read);
}


/**
 * read_ag - read the first charcter using getchar
 *
 * Return: pointer to read line
 */

char *read_ag(void)
{
	int command_size = 1024;
	int j = 0;
	char *read = malloc(sizeof(char) * command_size);
	int characters;

	if (read == NULL)
	{
		printf("error allocate form sream");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		characters = getchar(); /* read first char from stream */
		if (characters == EOF)
		{
			free(read);
			exit(EXIT_SUCCESS);
		}
		else if (characters == '\n')
		{
			read[j] = '\0';
			return (read);
		}
		else
		{
			read[j] = characters;
		}
		j++;
		if (j >= command_size)
		{
			command_size += command_size;
			read = realloc(read, command_size);
			if (read == NULL)
			{
				printf("realloc error");
				exit(EXIT_FAILURE);
			}
		}
	}
}


/**
 * split - split the string to read the command
 * @read: the line to be split
 *
 * Return: pointer to array
 */


char **split(char *read)
{
	int command_size = 64;
	/* int will use to store tokenn in tokenns*/
	int j = 0;
	/*primary, dynamically allocate for tokenns */
	char **tokenns = malloc(command_size * sizeof(char *));
	char *tokenn;
	/* if memory allocation failed*/
	if (!tokenns)
	{
		printf("error to allocate tokenn");
		exit(EXIT_FAILURE);
	}
	tokenn = strtok(read, " \n\r\a\t");
	while (tokenn != NULL)
	{
		/* handling if comments */
		if (tokenn[0] == '#')
		{
			break;
		}
		tokenns[j] = tokenn;
		j++;
		if (j >= command_size)
		{
			command_size += command_size;
			tokenns = realloc(tokenns, command_size * sizeof(char *));
			if (!tokenns)
			{
				printf("error in realloc splited command");
				exit(EXIT_FAILURE);
			}
		}
		tokenn = strtok(NULL, " \n\r\t\a");
	}
	tokenns[j] = NULL;
	return (tokenns);
}
