#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) {

	//v1
	printf("V1:\n");

	char name1[10];
	puts("What is your name?");
	gets(name1);	//é perigoso
	printf("Hello %s\n", name1);

	//v2
	printf("\nV2:\n");

	char name2[10];
	puts("What is your name?");
	fgets(name2, 10, stdin);
	printf("Hello %s\n", name2);

	//v3 ???
	printf("\nV3:\n");

	char name3[10];
	puts("What is your name?");
	scanf("%s", name3);
	printf("Hello %s\n", name3);


	//v4 														???????????????????????????
	//adicionar int main(int agrc, char* argv[])
	printf("\nV4:\n");

	if((argc == 1) || (argc > 3)) {
		printf("\nUsage: prog_name first_name\n\n");
		printf("OR: prog_name first_name family_name\n\n");
	}
	if(argc == 2) {
		printf("Hello %s !!\n", argv[1]);
	} else {
		printf("Hello %s !!\n", argv[1], argv[2]);
	}



    //Ex3
    //adicionar #include <math.h>
    // int i;
    // printf(" n n*n sqrt(n)\n");


    return 0;
}
