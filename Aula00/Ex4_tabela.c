#include<stdio.h>
#include<stdlib.h> //atoi, strtol
#include<math.h>
#include<assert.h>

#define PI 3.14159265359

int main(int argc, char* argv[]) {

	int smaller, bigger, spacing;
	double val = PI / 180;
	FILE *fptr;

	if(argc == 4) {
		smaller = atoi(argv[1]);
		bigger = atoi(argv[2]);
		assert(smaller < bigger && "Smaller value must be less than the bigger value");
		spacing = atoi(argv[3]);
		assert(spacing > 0 && "Spacing value must be greater than 0");

	} else if(argc == 1) {
		do {
			printf("Smaller value: ");
			scanf("%d", &smaller);
			printf("Bigger value: ");
			scanf("%d", &bigger);
			if(smaller >= bigger) printf("\nSmaller value must be less than the bigger value\nTry again\n\n");
		} while(smaller >= bigger);

		do {
			printf("Spacing value: ");
			scanf("%d", &spacing);
			if(spacing <= 0) printf("\nSpacing value must be greater than 0\nTry again\n\n");
		} while(spacing <= 0);
		

	} else {
		printf("\nUsage: prog_name\n\n");
		printf("OR: prog_name smaller_value bigger_value spacing_value\n\n");
		exit(1);
	}

	printf("\n%3s %8s %9s\n", "ang", "sin(ang)", "cos(ang)");
	printf("--- --------- ---------\n");

	fptr = fopen("tabela_Ex4.txt","w");
	fprintf(fptr, "\n%3s %8s %9s\n", "ang", "sin(ang)", "cos(ang)");
	fprintf(fptr, "--- --------- ---------\n");

	for(int i=smaller; i<=bigger; i+=spacing){
		printf("%3d  %8.6f  %8.6f\n", i, sin(i*val), cos(i*val));
		fprintf(fptr, "%3d  %8.6f  %8.6f\n", i, sin(i*val), cos(i*val));
	}

	fclose(fptr);

}