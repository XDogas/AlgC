// Não funciona não sei pq

#include <stdio.h>
#include <math.h>

int main() {
																			// Exemplo
    int num = 100;		// numero inserido										(153)
	int originalNum;	// resultado inteiro da divisão							(153 % 10 = (int)15,3 = 15 | 15 % 10 = (int)1,5 = 1 | 1 % 10 = (int)0,1 = 0)
	int remainder;		// cada um dos algarismos, começando pelo último		(3 | 5 | 1)
	int result = 0;		// resultado da soma de cada um dos algarismos ao cubo	(3^3 + 5^3 + 1^3 = 153, logo e um número de Armstrong)

	while(num!=1000) {

		originalNum = num;

		while (originalNum != 0) {
			remainder = originalNum % 10;
			result += pow(remainder,3);
			originalNum /= 10;
		}
		
		if (result == num) printf("%d is an Armstrong number.\n", num);

		num++;
	}

    return 0;
}
