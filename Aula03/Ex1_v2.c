// tem um erro que não percebo bem

#include<stdio.h>

int difElemCount(int*, int);

int nOper;

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

	difElemCount(array0, arraySize); // sem isto o primeiro nOper é 0 e deveria ser 9

	printf("Array  1 -> Resultado: %d, N.Operacoes: %d\n", difElemCount(array1, arraySize), nOper);	
	printf("Array  2 -> Resultado: %d, N.Operacoes: %d\n", difElemCount(array2, arraySize), nOper);
	printf("Array  3 -> Resultado: %d, N.Operacoes: %d\n", difElemCount(array3, arraySize), nOper);
	printf("Array  4 -> Resultado: %d, N.Operacoes: %d\n", difElemCount(array4, arraySize), nOper);
	printf("Array  5 -> Resultado: %d, N.Operacoes: %d\n", difElemCount(array5, arraySize), nOper);
	printf("Array  6 -> Resultado: %d, N.Operacoes: %d\n", difElemCount(array6, arraySize), nOper);
	printf("Array  7 -> Resultado: %d, N.Operacoes: %d\n", difElemCount(array7, arraySize), nOper);
	printf("Array  8 -> Resultado: %d, N.Operacoes: %d\n", difElemCount(array8, arraySize), nOper);
	printf("Array  9 -> Resultado: %d, N.Operacoes: %d\n", difElemCount(array9, arraySize), nOper);
	printf("Array 10 -> Resultado: %d, N.Operacoes: %d", difElemCount(array0, arraySize), nOper);
}

int difElemCount(int* array, int n) {

	int result = 0;
	nOper = 0;

	for(int i=1; i<n; i++) {
		nOper++;
		if(array[i] != array[i-1]) result++;
	}

	return result;
}