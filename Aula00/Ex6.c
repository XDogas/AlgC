#include<stdio.h>

void printArray(char*, int*);
void cumSum(int*, int*);

int main(void) {
	int a[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	printArray("a", a);
	int b[12] = {0};
	cumSum(a, b);
	printArray("b", b);
}

void printArray(char* s, int* a) {
	printf("%s:\n", s);
	for(int i=0; i<12; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void cumSum(int* a, int* b) {
	int c = 0;
	for (int i=0; i<12; i++) {
		c += a[i];
		b[i] = c;
	}
}