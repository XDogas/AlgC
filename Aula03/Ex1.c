#include <stdio.h>
#include <assert.h>

void printResult(int*, int);
int difElemCount(int*, int);

int nOper;	// numero de Operacoes/Comparacoes
int i = 0;

int main(void) {

	int array1[10] = {3,3,3,3,3,3,3,3,3,3};
	int array2[10] = {4,3,3,3,3,3,3,3,3,3};
	int array3[10] = {4,5,3,3,3,3,3,3,3,3};
	int array4[10] = {4,5,1,3,3,3,3,3,3,3};
	int array5[10] = {4,5,1,2,3,3,3,3,3,3};
	int array6[10] = {4,5,1,2,6,3,3,3,3,3};
	int array7[10] = {4,5,1,2,6,8,3,3,3,3};
	int array8[10] = {4,5,1,2,6,8,7,3,3,3};
	int array9[10] = {4,5,1,2,6,8,7,9,3,3};
	int array0[10] = {4,5,1,2,6,8,7,9,3,0};

	int arraySize = sizeof (array1) / sizeof (int); // arraySize = 10
	
	printResult(array1, arraySize);
	printResult(array2, arraySize);
	printResult(array3, arraySize);
	printResult(array4, arraySize);
	printResult(array5, arraySize);
	printResult(array6, arraySize);
	printResult(array7, arraySize);
	printResult(array8, arraySize);
	printResult(array9, arraySize);
	printResult(array0, arraySize);
}

void printResult(int* array, int n) {

	i++;
	nOper = 0;
	int result;
	result = difElemCount(array, n);
	printf("Array %2d -> Resultado: %d | Numero de Operacoes: %d\n", i, result, nOper);
}

int difElemCount(int* array, int n) {

	//assert(n > 1);	//assert without message
	assert(("O numero de elementos do array tem de ser superior a 1", n > 1));
	int result = 0;

	for(int i=1; i<n; i++) {
		nOper++;
		if(array[i] != array[i-1]) result++;
	}

	return result;
}