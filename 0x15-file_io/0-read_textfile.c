#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t folder;
	ssize_t writee;
	ssize_t text;

	folder = open(filename, O_RDONLY);
	if (folder == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	text = read(folder, buf, letters);
	writee = write(STDOUT_FILENO, buf, text);

	free(buf);
	close(folder);
	return (writee);
}

