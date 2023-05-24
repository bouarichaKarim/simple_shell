#include "shell.h"
/**
 * val_of_arg - allocates memory for an array of string
 * and fill it with a given data
 *
 * @head: structure pointer to the head of a linked list
 *
 * Return: pointer to pointer to an array of string
 */
char **val_of_arg(argument_exec *head)
{
	argument_exec *temp = NULL;
	int size = 0, i = 0;
	char **argv = NULL;

	temp = head;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	argv = malloc((size + 1) * sizeof(argument_exec));
	temp = head;
	while (temp->next)
	{
		argv[i] = temp->str;
		temp = temp->next;
		i++;
	}
	argv[i] = NULL;
	return (argv);
}
/**
 * list_of_arg - splits a string into substring and store them into a linked list
 *
 * @buf: The content to be split
 * @delim: delimiters that will split the @buf
 *
 * Return: pointer to the head of a linked list
 */
argument_exec *list_of_arg(char *buf, char *delim)
{

	char *str = NULL;
	argument_exec *head = NULL, *temp = NULL, *new_node = NULL;

	str = strtok(buf, delim);
	head = malloc(sizeof(argument_exec));
	if (head == NULL)
	{
		perror("Memory allocate");
		return (NULL);
	}

	head->str = str;
	head->next = NULL;
	temp = head;
	while (str)
	{
		str = strtok(NULL, delim);
		new_node = malloc(sizeof(argument_exec));
		if (new_node == NULL)
		{
			perror("Memory allocate");
			return (NULL);
		}
		new_node->str = str;
		new_node->next = NULL;
		temp->next = new_node;
		temp = temp->next;
		new_node = new_node->next;
	}
	return (head);
}
/**
 * argv_free - free memory allocate of a linked list
 *
 * @head: pointer to the head of a linked list
 */
void argv_free(argument_exec *head)
{
	argument_exec *temp = NULL;

	temp = head;
	while (head)
	{
		head = head->next;
		free(temp->str);
		free(temp);
		temp = head;
	}
}
