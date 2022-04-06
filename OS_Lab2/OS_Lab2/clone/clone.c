#include <stdio.h> // printf()
#include <unistd.h> // sleep(), getpid(), getppid()
#include <signal.h> // SIGCHLD flag
#include <linux/sched.h> // CLONE flags

void printids(void) {
  printf("TGID: %d\n", getpid()); // Print the TGID of the current process
  printf("PPID: %d\n", getppid()); // Print the PPID of the current process  
  printf("\n\n");
  sleep(1);
}

int child(void *arg) 
{
  printids();
}


int main(void)
{
  printids(); // IDs of the main process

  // TODO Implement:

 // 1 clone() that creates a new proces
  void *stack;
  stack = malloc(5000);//having stack for child process
  printf("This is a child process created by clone().\n");
  clone(child, stack+2000, SIGCHLD, 0);
  
  sleep(2);  

  //getchar(); // Press a key to continue




  // 1 clone() that creates a new thread
  printf("This is a thread created by clone().\n");
  clone(child, stack+5000, CLONE_VM, CLONE_FS, CLONE_FILES, CLONE_SIGHAND | CLONE_THREAD, 0);
  sleep(2);

  free(stack);
  //getchar();

  // 1 fork()
// 1 fork()
  pid_t fpid;
  fpid = fork(); //child process created by main process
  if(fpid == 0)
  {
  printf("This is a child process created by forking.\n");
  printids(); //Ids of the child process 
  exit(1); //exit the chid process to reduce the process created by clone
  }

  sleep(2); //to see the output 

  //getchar();

  return 0;
}
