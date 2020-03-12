#include <stdio.h>
#include <stdlib.h>

int f1(int n);
int f2(int n);
int f3(int n);
int f4(int n);

int countf1;
int countf2;
int countf3;
int countf4;

int main(int argc, char* argv[]) {

	int nelem;
	char ni[] = "num iter";

	if(argc > 2) {
		printf("\nUsage: prog_name\n\n");
		printf("OR: prog_name number_of_lines\n\n");
		exit(0);
	} else if(argc == 2) {
		nelem = atoi(argv[1]);
	} else {
		printf("Numero de elementos da tabela: ");
		scanf("%d", &nelem);
		// scanf ("%*[^\n]");
		// scanf ("%*c");
	}

	printf("%3s %4s %7s %4s %7s %4s %7s %4s %7s\n", "n", "f1(n)", ni, "f2(n)", ni, "f3(n)", ni, "f4(n)", ni);
	printf("--- ----- -------- ----- -------- ----- -------- ----- --------\n");

	for(int i=1; i<=nelem; i++) {

		countf1 = 0;
		countf2 = 0;
		countf3 = 0;
		countf4 = 0;

		int resf1 = f1(i);
		int resf2 = f2(i);
		int resf3 = f3(i);
		int resf4 = f4(i);

		printf("%3d %5d %8d %5d %8d %5d %8d %5d %8d\n", i, resf1, countf1, resf2, countf2, resf3, countf3, resf4, countf4);
	}

}

int f1 (int n) {	
	int i, j, r = 0;
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++) {
			r += 1;
			countf1++;
		}
	}
	return r;
}

int f2 (int n) {
	int i, j, r = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			r += 1;
			countf2++;
		}
	}
	return r;
}

int f3 (int n) {
	int i, j, r = 0;
	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j++) {
			r += j;
			countf3++;
		}
	}
	return r;
}

int f4 (int n) {
	int i, j, r = 0;
	for (i = 1; i <= n; i++) {
		for (j = i; j >= 1; j /= 10) {
			r += i;
			countf4++;
		}
	}
	return r;
}