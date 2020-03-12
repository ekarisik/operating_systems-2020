#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])	{
	pid_t pid;
	int status;
	
	pid = fork();
	if (pid == 0)	{
		printf("Sleep 1\n");
		sleep(1);
		printf("Wake up 1\n");
		exit(5);
	}
	pid = fork();
	if (pid == 0)	{
		printf("Sleep 2\n");
		sleep(1);
		printf("Wake up 2\n");
		exit(5);
	}
	wait(&status);
	printf("OK: Chiled exited with exit status %d.\n",WIFSIGNALED(status));
	wait(&status);
	printf("OK: Child exited with exit status %d.\n", WEXITSTATUS(status));
}
