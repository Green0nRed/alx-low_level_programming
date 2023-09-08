#include "main.h"
#include <stdlib.h>
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
ssize_t op,re,wr;
char *buffers;
if(filename == 0)
return(NULL);
buffers = malloc(sizeof(char) * letters);
if(buffers == 0)
return(NULL);
op = open(filename, O_RDONLY);
re = read(o, buffers, letters);
wr = write(STDOUT_FILENO, buffers, r);
if(op == -1 || re == -1 || wr == -1 || wr != r)
{
free(buffers);
return (NULL);
}
free(buffers);
close(o);
return (wr);
}
