#include <stdio.h>
#include <assert.h>

void printResult(int*, int);
void removeDuplicates(int* a, int* n);

int nComp;		// Número de comparações
int nCopias;	// Número de Cópias / Deslocamentos
int i = 0;

int main(void) {

	int array1[] = {1,2,2,2,3,3,4,5,8,8};	// result = {1,2,3,4,5,8} 
	int array2[] = {1,2,2,2,3,3,3,3,8,8};	// result = {1,2,3,8}
	int array3[] = {1,2,3,2,1,3,4};			// result = {1,2,3,4}
	int array4[] = {1,2,5,4,7,0,3,9,6,8};	// result = {1,2,5,4,7,0,3,9,6,8} (permanece inalterada)
	int array5[] = {3,3,3,3,3,3,3,3,3,3};	// Melhor caso com 10 elementos (números todos iguais)
	int array6[] = {3,5,8,9,6,4,1,7,0,2};	// Pior caso com 10 elementos (números todos diferentes)
	// ou {3,5,8,9,6,4,1,7,0,0} os 2 ultimos elementos são iguais

	int arraySize;

	arraySize = sizeof(array1) / sizeof(int); // arraySize = 10
	removeDuplicates(array1, &arraySize);

	arraySize = sizeof(array2) / sizeof(int); // arraySize = 10
	removeDuplicates(array2, &arraySize);

	arraySize = sizeof(array3) / sizeof(int); // arraySize = 7
	removeDuplicates(array3, &arraySize);

	arraySize = sizeof(array4) / sizeof(int); // arraySize = 10
	removeDuplicates(array4, &arraySize);

	arraySize = sizeof(array5) / sizeof(int); // arraySize = 10
	removeDuplicates(array5, &arraySize);

	arraySize = sizeof(array6) / sizeof(int); // arraySize = 10
	removeDuplicates(array6, &arraySize);
}

void removeDuplicates(int* a, int* arraySize) {

	int n = *arraySize;

	assert(("O numero de elementos do array tem de ser superior a 1", n > 1));

	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			nComp++;
			if(a[i] == a[j]) {
				for(int k=j; k<n-1; k++) {
					nCopias++;
					a[k] = a[k+1];					
				}
				j--;
				n--;
			}
		}
	}

	*arraySize = n;

	for(int i=0; i<n; i++) {
		printf("%d ", a[i]);
	}
	printf("\tN. Comparacoes: %d, N.Copias: %d", nComp, nCopias);
	printf("\n");
	nComp = 0;
	nCopias = 0;
}