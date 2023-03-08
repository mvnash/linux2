#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "utils_v2.h"

int main(int argc, char **argv)
{
  int pidEnf = fork();
  checkCond(pidEnf == -1, "Fork failed");

  if (pidEnf != 0)
  {
    printf("1 2 3\n");
    int status;
    int waitId = waitpid(pidEnf, &status, 0);
    checkCond(waitId == -1, "Wait error");
    printf("exitCode => %d", WEXITSTATUS(status));
  }
  else
  {
    printf("4 5 6\n");
    exit(13);
  }
}
