#include <stdio.h>
#include <assert.h>

int Motzkin(int);

int nMults; // Número de multiplicações

int main(void) {

	printf("Versao Recursiva\n");
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

	if(n <= 1) return 1;

	int somatorio = 0;
	for(int k=0; k<=n-2; k++) {
		nMults++;
		somatorio += Motzkin(k) * Motzkin(n-2-k);
	}

	return Motzkin(n-1) + somatorio;
}	