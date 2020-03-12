#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])	{
	pid_t pid;
	int status;
	
	pid = fork();
	if (pid != 0)	{
		while (pid != wait(&status));
	}	else	{
			printf("Sleep 1\n");
			sleep(5);
			printf("Wake up 1\n");
			exit(5);
		}
	printf("OK : Child exited with exit status %d.\n", WIFEXITED(status));

	pid = fork();
	if (pid != 0)	{
		while (pid != wait(&status));
	}	else	{
			printf("Sleep 2\n");
			sleep(5);
			printf("Wake up 2\n");
			exit(5);
		}
	printf("OK: Child exited with exit status %d.\n", WEXITSTATUS(status));

}
