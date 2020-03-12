#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isArmstrong(int);

int main(void) {

	for(int i=100; i<=999; i++){
		if(isArmstrong(i)) printf("%d is an Armstrong number.\n", i);
	}
}

bool isArmstrong(int number) {
																			// Exemplo (153)
	int numTmp;		// resultado inteiro da divisão							(153 % 10 = (int)15,3 = 15 | 15 % 10 = (int)1,5 = 1 | 1 % 10 = (int)0,1 = 0)
	int resto;		// cada um dos algarismos, começando pelo último		(3 | 5 | 1)
	int result = 0;	// resultado da soma de cada um dos algarismos ao cubo	(3^3 + 5^3 + 1^3 = 153, logo e um número de Armstrong)

	numTmp = number;
	while(numTmp != 0) {
		resto = numTmp % 10;
		result += pow(resto,3);
		numTmp /= 10;
	}
	if(result == number) return true;
	else return false;
}