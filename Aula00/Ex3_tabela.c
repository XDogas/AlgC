#include<stdio.h>
#include<stdlib.h> //atoi, strtol
#include<math.h>

int main(int argc, char* argv[]) {

	int nlines;

	if(argc > 2) {
		printf("\nUsage: prog_name\n\n");
		printf("OR: prog_name number_of_lines\n\n");
		exit(1);
	} else if(argc == 2) {
		nlines = atoi(argv[1]);
	} else {
		printf("Number of lines: ");
		scanf("%d", &nlines);
	}

	printf(" n   n*n   sqrt(n)\n");
	printf("--- ----- ---------\n");

	for(int i=0; i<nlines; i++){
		printf("%3d  %4d  %f\n", i, i*i, sqrt(i));
	}

}