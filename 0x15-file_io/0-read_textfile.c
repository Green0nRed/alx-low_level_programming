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
char *buffer;
ssize_t rbytes = 0, wbytes = 0;
int fdx;
if (!filename || letters <= 0)
return (NULL);
fdx = open(filename, O_RDONLY);
if (fdx == -1)
return (NULL);
buffer = malloc(sizeof(char) * letters);
if (buffer == NULL)
return (NULL);
rbytes = read(fdx, buffer, letters);
if (rbytes == -1)
return (NULL);
wbytes = write(STDOUT_FILENO, buffer, rbytes);
if (wbytes == -1 || wbytes < rbytes)
return (NULL);
free(buffer);
close(fdx);
return (wbytes);
}
