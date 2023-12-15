#include "monty.h"

/**
 * read_line - reads input line splits it into an array containing a command
 * @line - pointer to a line
 */
void read_line(char *line, size_t len_bytes, unsigned int line_no)
{
	int i;
	char *token;
	char **new_line;

	new_line = malloc(sizeof(char *) * len_bytes);
	if (new_line == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free(new_line);
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " ");
	i = 0;
	while (token)
	{
	new_line[i] = malloc(sizeof(char) * (strlen(token) + 1));
	if (new_line[i] == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free(new_line[i]);
		exit(EXIT_FAILURE);
	}
	strcpy(new_line[i], token);
	token = strtok(NULL,  " ");
	i++;
	}
	check_push(new_line, line_no);
}
