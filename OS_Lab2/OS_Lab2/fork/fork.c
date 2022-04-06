#include <stdio.h>
#include <unistd.h>

int main(void)
{
  int mainPID = (int)getpid(); // Get PID actually returns the TGID!!
  printf( "Main process PID: %d\n", mainPID); // Print the PID of the current process

  fork();
  fork();
  //fork();

  int childPID = (int)getpid(); // Get PID actually returns the TGID!!

  if(childPID != mainPID) {
    printf( "Child PID: %d\n", (int)getpid()); // Print the PID of the child process
  } else {
    sleep(1);
    printf("Press ENTER key to Continue\n");    
  }

  sleep(1);

  getchar();
  printf("Process %d ended\n", childPID);    

  return 0;
}

