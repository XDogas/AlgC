#include<stdio.h>

int main(void) {

	printf("sizeof(void *) ...... %lu\n", sizeof(void *));		// arquitetura 32bits : sizeof(void *) = 4; e 
//	printf("sizeof(void) ........ %lu\n", sizeof(void));		// arquitetura 64bits : sizeof(void *) = 8
	printf("sizeof(char) ........ %lu\n", sizeof(char));
	printf("sizeof(short) ....... %lu\n", sizeof(short));
	printf("sizeof(int) ......... %lu\n", sizeof(int));
	printf("sizeof(long) ........ %lu\n", sizeof(long));
	printf("sizeof(long long) ... %lu\n", sizeof(long long));
	printf("sizeof(float) ....... %lu\n", sizeof(float));
	printf("sizeof(double) ...... %lu", sizeof(double));

	return 0;
}