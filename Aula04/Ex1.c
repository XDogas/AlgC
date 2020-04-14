#include <stdio.h>
#include <assert.h>

void printResult(int*, int);
int isValid(int*, int);

int nOper;	// numero de Operacoes/Comparacoes
int i = 0;

int main(void) {

	int array1[10] = {1,3,4,5,5,6,7,7,8,9};
	int array2[10] = {1,2,4,5,5,6,7,8,8,9};
	int array3[10] = {1,2,3,6,8,8,8,9,9,9};
	int array4[10] = {1,2,3,4,6,7,7,8,8,9};
	int array5[10] = {1,2,3,4,5,7,7,8,8,9};
	int array6[10] = {1,2,3,4,5,6,8,8,9,9};
	int array7[10] = {1,2,3,4,5,6,7,9,9,9};
	int array8[10] = {1,2,3,4,5,6,7,8,8,9};
	int array9[10] = {1,2,3,4,5,6,7,8,9,9};
	int array0[10] = {1,2,3,4,5,6,7,8,9,10};

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
	result = isValid(array, n);
	printf("Array %2d -> Resultado: %d | Numero de Operacoes: %d\n", i, result, nOper);
}

int isValid(int* a, int n) {

	//assert(n > 1);	//assert without message
	assert(("O numero de elementos do array tem de ser superior a 1", n > 1));
		// OU
	//if(n < 2) return 0;	//se nao houver pelo menos 2 elementos e impossivel verificar a condicao

	for(int i=0; i<n-1; i++) {
		nOper++;
		if(a[i+1] - a[i] != 1) return 0;
	}

	return 1;
}