#include <stdio.h>
#include <assert.h>

int Motzkin(int);

int nMults; // Número de multiplicações

int main(void) {

	printf("Versao Programacao Dinamica\n");
	printf("%2s %10s %8s\n", "n", "Mutzkin(n)", "num mult");
	printf("-- ---------- --------\n");

	for(int i=0; i<=15; i++) {
		nMults = 0;
		int result = Motzkin(i);
		printf("%2d %10d %8d\n", i, result, nMults);
	}

	return 0;
}

int Motzkin(int n) {

	assert(n >= 0);

	int A[n - 1];
	A[0] = 1;
	A[1] = 1;

	for(int i=2; i<=n; i++) {
		A[i] = A[i-1];
		for(int k=0; k<=i-2; k++) {
			nMults++;
			A[i] += A[k] * A[i-2-k];
		}
	}

	return A[n];
}