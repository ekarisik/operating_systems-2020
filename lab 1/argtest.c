#include <stdio.h>

// a test of command-line arguments
int main(int argc, char** argv) {
	printf("program was called with %d arguments\n",argc-1);
	if (argc>1) {
		printf("the first argument is %s\n", argv[1]);
	}
	return 0;
}
