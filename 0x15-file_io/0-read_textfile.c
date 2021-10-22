#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - that reads a text file and prints
 * @filename: variable pointer
 * @letters: size letters
 * Description: Write a function that reads a text file and prints it
 * to the POSIX standard output.
 * Return: read and print, 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd, let, w;
	char *text;

	text = malloc(letters);
	if (text == NULL)
		return (0);

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		free(text);
		return (0);
	}

	let = read(fd, text, letters);

	w = write(STDOUT_FILENO, text, let);

	close(fd);

	return (w);
}
