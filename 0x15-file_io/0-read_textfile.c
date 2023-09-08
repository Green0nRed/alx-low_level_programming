#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * read_textfile = print the POSIX stdout with Reading a text file.
 * @filename = the pointers attribuate the name of the file.
 * @letters = the functions will be read and print 
 * considerin the numbers of the letter .
 * The return = if the functions fail or filenames is NULL or 0 .
 * OP/WR - the actual number of bytes the function can read and print.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, w;
	char *buff;

	if (filename == 0)
		return (0);

	buff = malloc(sizeof(char) * letters);
	if (buff == 0)
		return (NULL);

	o = open(filename, O_RDONLY);
	r = read(o, buff, letters);
	w = write(STDOUT_FILENO, buff, r);

	if (o == -1 || r == -1 || w == -1 || w != r)
	{
		free(buff);
		return (NULL);
	}

	free(buff);
	close(o);

	return (w);
}
