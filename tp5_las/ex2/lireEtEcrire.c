#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "utils_v2.h"

#define BUFFERSIZE 80
#define FILENAME "test"

int main(int argc, char **argv)
{

  // Opening file
  int fd = open(FILENAME, O_WRONLY | O_TRUNC | O_CREAT, 0777);
  checkNeg(fd, "Error opening file");

  // Writing
  for (int i = 0; i < NBR_ENTIERS; i++)
  {
    int nbCharWr = write(fd, &i, sizeof(int));
    if (nbCharWr != sizeof(int))
    {
      perror("Error writing file");
    }
  }
}
