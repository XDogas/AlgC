#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isFatoriao(int);
int fatorial(int);

int main(void) {

	for(int i=1; i<=10^6; i++){
		if(isFatoriao(i)) printf("%d is an Factorion number.\n", i);
	}
}

bool isFatoriao(int number) {
																			// Exemplo (145)
	int numTmp;		// resultado inteiro da divisão							(145 % 10 = (int)14.5 = 14 | 154 % 10 = (int)1,4 = 1 | 1 % 10 = (int)0,1 = 0)
	int resto;		// cada um dos algarismos, começando pelo último		(5 | 4 | 1)
	int result = 0;	// resultado da soma de cada um dos algarismos ao cubo	(5! + 4! + 1! = 145, logo e um Fatorião)

	numTmp = number;
	while(numTmp != 0) {
		resto = numTmp % 10;
		result += fatorial(resto);
		numTmp /= 10;
	}
	if(result == number) return true;
	else return false;
}

int fatorial(int n) {
    if ( n <= 1 ) return (1);
    else return n * fatorial(n - 1);
}