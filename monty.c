#define _GNU_SOURCE
#include "monty.h"
/**
 * main - driver of the entire monty program contains variable declarations
 * and function calls to the appropriate files
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 (on success any other value is an error)
 */
int main(int ac, char **av)
{
	int line_no = 0;
	FILE *byte_file;
	char *buffer;
	size_t len = 0;
	ssize_t read;

	if (ac != 2)
	{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
	}
	byte_file = fopen(av[1], "r");
	if (byte_file == NULL)
	{
	fprintf(stderr, "Error: Can't open file %s\n", av[1]);
	exit(EXIT_FAILURE);
	}
	while ((read = getline(&buffer, &len, byte_file)) != -1)
	{
		line_no++;
		read_line(buffer, len, line_no);
	}
	fclose(byte_file);
	return (0);
}
