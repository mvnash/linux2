#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "utils_v2.h"

#define NBR_ENTIERS 10000000
#define FILENAME "test"

#define SYSCALLS 0

// fwrite() est + rapide que write() car fwrite remplit un buffer avant l'appel systeme et donc ne fait pas les appels systemes un par un

int main(int argc, char **argv)
{

  // Opening file
  #if SYSCALLS
  int fd = open(FILENAME, O_WRONLY | O_TRUNC | O_CREAT, 0777);
  checkNeg(fd, "Error opening file");
  #else 
  FILE* fd = fopen(FILENAME, "w");
  if(!fd) {
    perror("fopen problelm");
    exit(1);
  }
  #endif

  // Writing
  for (int i = 0; i < NBR_ENTIERS; i++)
  {
    #if SYSCALLS
    int nbCharWr = write(fd, &i, sizeof(int));
    if (nbCharWr != sizeof(int))
    #else
    int nbCharWr = fwrite(&i, sizeof(int), 1, fd);
    if (nbCharWr != 1)
    #endif
    {
      perror("Error writing file");
    }
  }
}
