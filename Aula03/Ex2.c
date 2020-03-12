#include <stdio.h>
#include <assert.h>

void printResult(int*, int);
int indexFinder(int*, int);

int nComp;
int i = 0;

int main(void) {

	int array1[] = {1,9,2,8,3,4,5,3,7,2};	// result = 8
	int array2[] = {1,7,4,6,5,2,3,2,1,0};	// result = 3
	int array3[] = {2,2,2,2,2,2,2,2,2,2};	// result = -1

	int arraySize = sizeof (array1) / sizeof (int); // arraySize = 10

	printResult(array1, arraySize);
	printResult(array2, arraySize);
	printResult(array3, arraySize);
}

void printResult(int* array, int n) {

	i++;
	nComp = 0;
	int result;
	result = indexFinder(array, n);
	printf("Array %d -> Resultado: %2d | Numero de Comparacoes: %d\n", i, result, nComp);
}

int indexFinder(int* array, int n) {

	assert(("O numero de elementos do array tem de ser superior a 1", n > 1));
	int index = -1;
	int nSmallers = 0;	

	for(int i=0; i<n; i++) {

		int nSmallersIni = 0;

		for(int j=0; j<i; j++) {
			nComp++;
			if(array[i]>array[j]) nSmallersIni++;
		} 

		if(nSmallersIni>nSmallers) {
			nSmallers = nSmallersIni;
			index = i;
		}
	}
	
	return index;
}