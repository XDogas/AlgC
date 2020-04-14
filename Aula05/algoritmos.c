#include <stdio.h>
#include <assert.h>

int T1(int);
int T2(int);
int T3(int);

int count1; // número de chamadas recursivas do primeiro algoritmo
int count2; // número de chamadas recursivas do segundo algoritmo
int count3; // número de chamadas recursivas do terceiro algoritmo

int main(void) {

	char ncr[] = "num chamadas";

	printf("%2s %4s %11s %4s %11s %4s %11s\n", "n", "T1(n)", ncr, "T2(n)", ncr, "T3(n)", ncr);
	printf("-- ----- ------------ ----- ------------ ----- ------------\n");

	for(int i=0; i<=28; i++) {

		count1 = 0;
		count2 = 0;
		count3 = 0;

		int result1 = T1(i);
		int result2 = T2(i);
		int result3 = T3(i);

		printf("%2d %5d %12d %5d %12d %5d %12d\n", i, result1, count1, result2, count2, result3, count3);
	}
}

int T1(int n) {
	assert(n >= 0);
	if(n == 0) return 0;
	count1++;
	return T1((int)(n/3)) + n;
}

int T2(int n) {
	assert(n >= 0);
	if(n >= 0 && n <= 2) return n;
	count2+=2;
	return T2((int)(n/3)) + T2((int)((n+2)/3)) + n;
}

int T3(int n) {
	assert(n >= 0);
	if(n >= 0 && n <= 2) return n;
	if(n % 3 == 0) {
		count3++;
		return 2 * T3(n/3) + n;
	}
	count3+=2;
	return T3((int)(n/3)) + T2((int)((n+2)/3)) + n;
}