#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "utils_v2.h"

volatile sig_atomic_t end = 0;
int main(int argc, char const *argv[])
{
    while (end == 0)
    {
        sleep(1);
    }
    return 0;
}
