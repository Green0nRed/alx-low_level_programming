#include "main.h"
#include "stdlib.h"
/** xX||read_textfile:Reads a Text File And Prints It To POSIX Stdout.||Xx     
 xX||@filename:A Pointer To The Name Of The File.||Xx
 xX||@letters:The Number Of Letters The Function Should Read And Print.||Xx                   
 xX||Return:If The Function Fails Or Filename Is (NULL) - 0. ||Xx
 xX||O/w:The Actual Number Of Bytes The Function Can Read And Print. ||Xx */
ssize_t read_textfile(const char *filename, size_t letters)
{
ssize_t o, r, w;char *Buff; if (filename == NULL)
return (0);
Buff = malloc(sizeof(char) * letters); if (Buff == NULL)
return (0);
o = open(filename, O_RDONLY); r = read(o, Buff, letters); w = write(STDOUT_FILENO, Buff, r);
if (o == -1 || r == -1 || w == -1 || w != r)
{free(Buff);
return (0);}
free(Buff); close(o);
return (w);
}
