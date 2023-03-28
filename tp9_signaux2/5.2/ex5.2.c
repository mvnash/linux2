#include <stdbool.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

#include "utils_v2.h"

#define MAX_XY  5

//***************************************************************************
// CHILD CODE
//***************************************************************************

volatile sig_atomic_t signum;

void handler (int num) {
   signum = num;
}

void run() {
   // CHILD
   int x = 0;
   int y = 0;
   printf("X = %d, Y = %d\n", x, y);

   // Arming of signals SIGUSR1 and SIGUSR2
   ssigaction(SIGUSR1, handler);
   ssigaction(SIGUSR2, handler);

   // Definition of signal mask (all signals except SIGUSR1 & SIGUSR2)
   sigset_t set;
   ssigfillset(&set);
   ssigdelset(&set, SIGUSR1);
   ssigdelset(&set, SIGUSR2);
	    
   while (true) { 
      // Wait for a signal SIGUSR1 or SIGUSR2
      sigsuspend(&set);

      if (signum == SIGUSR1) {
         y++;
         y += MAX_XY;
         y %= MAX_XY;
      } else {  // SIGUSR2
         x++;
         x += MAX_XY;
         x %= MAX_XY;
      }
      printf("X = %d, Y = %d\n", x, y);
   }
}

//***************************************************************************
// PARENT CODE
//***************************************************************************

char readchar() {
   printf(">>> ");
	
   int c = getchar();
   checkCond(c == EOF, "ERROR GETCHAR");
   char res = (char) c;

   c = getchar();  // read newline character
   checkCond(c == EOF, "ERROR GETCHAR");
	
   return res;
}

int main () {
   // Block all signals
   sigset_t set1;
   ssigfillset(&set1);
   ssigprocmask(SIG_BLOCK, &set1, NULL);

   pid_t chid = fork_and_run0(run);

   // PARENT
   // Read a command
   char current = readchar();
   while (current != 'Q') {
      if (current == 'U')
         // Send SIGUSR1 to child
         skill(chid, SIGUSR1);
      else if (current == 'R')
         // Send SIGUSR2 to child
         skill(chid, SIGUSR2);
      else
         printf("Error: unknown command\n");
      
      // Read a command
      current = readchar();
   }
	
   // Kill child process
   skill(chid, SIGKILL);
}

