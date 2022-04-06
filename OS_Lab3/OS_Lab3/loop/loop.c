#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(int argc, char *argv[])
{
	// Check argument count, argument 1 is always the program name, we expect program name and a nice value
	if(argc != 2) {
		printf("Please specify niceness\n");
		return -1;
	}

	// Convert character array to integer to parse nice value
	char *nice = argv[1];
	int new_prio = atoi(nice);

	int which = PRIO_PROCESS;
	pid_t pid = getpid(); // Get process ID of this process

	printf("Process ID: %d\n", pid);
	printf("Requested nice: %d\n", new_prio);

	// Get current nice value
	int curr_prio = getpriority(which, pid);
	printf("Original nice: %d\n", curr_prio);

	// Change to requested nice value
	setpriority(which, pid, new_prio);
	curr_prio = getpriority(which, pid);
	printf("New nice: %d\n\n", curr_prio);

	// Loop forever
	printf("Use CTRL+C (SIGINT) to exit\n\n");
	while(1) {
	     usleep(1);
	}

	// Never reached
	return 0;
}
