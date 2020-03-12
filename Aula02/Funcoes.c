#include<stdio.h>
#include<assert.h>

typedef unsigned long long u64;

u64 P1(int);
u64 P2(int);

int main(void) {	// Prestar atenção na alteração do 36 para 37

	printf("Versao Recursiva\n");
	for(int i=0; i<=40; i++) {
		printf("%2d : %20llu\n", i, P1(i));
	}

	printf("\nVersao Iterativa\n");
	for(int i=0; i<=40; i++) {
		printf("%2d : %20llu\n", i, P2(i));
	}
}

u64 P1(int n) {	//Versao Recursiva, demora mais 

	assert(n >= 0);

	if(n <= 1) {
		return n;
	} else {
		return 3*P1(n-1) + 2*P1(n-2);
	}
}

u64 P2(int n) {	//Versao Iterativa, mais rapida

	assert(n >= 0);

	u64 a = 0, b = 1, c = 3;

	if(n <= 1) return n;

	for(int i=2; i<=n; i++) {
		c = 3*b + 2*a;
		a = b;
		b = c;
	}
	return c;
}