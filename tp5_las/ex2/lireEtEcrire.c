#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "utils_v2.h"

#define BUFFERSIZE 80
#define FILENAME "test"

int main(int argc, char **argv)
{
  if (argc != 3)
  {
    perror("Missing files in argument");
    exit(1);
  }

  char bufferRead[BUFFERSIZE];

  /* Opening the file in write mode */
  int fd1 = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
  checkNeg(fd1, "Error opening file");

  int fd2 = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0644);
  checkNeg(fd2, "Error opening file");

  /* Reading STDIN, then writing file, up to EOF (Ctrl-D) */
  char *msg = "Enter text lines (Ctrl-D to terminate):\n";
  int len = strlen(msg);
  int nbCharWr = write(1, msg, len);
  checkCond(nbCharWr != len, "Error writing on stdout");

  char c;

  int nbCharRd = read(0, bufferRead, BUFFERSIZE);
  while (nbCharRd > 0)
  {
    // +80 char line treatment
    if (nbCharRd == 80 && bufferRead[80] != '\n')
    {
      while (1)
      {
        read(0, &c, 1);
        if (c == '\n') break;
      }
    }

    if (isupper(bufferRead[0]))
    {
      nbCharWr = write(fd1, bufferRead, nbCharRd);
    }
    else if (islower(bufferRead[0]))
    {
      nbCharWr = write(fd2, bufferRead, nbCharRd);
    }
    checkCond(nbCharWr != nbCharRd, "Error writing file");
    nbCharRd = read(0, bufferRead, BUFFERSIZE);
  }

  checkNeg(nbCharRd, "Error reading stdin");
}
