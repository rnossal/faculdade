#include <stdio.h>
#define TAM 10

main() {
	int a = 0, b, x, r;
	char c;
	double d;
	int k;
	int v[TAM], i;

	printf("Vou colocar valores no vetor\n");
	for (i = 0; i < TAM; i++) {
		v[i] = TAM - 1;
	}
	i = 0;
	while (i < TAM) {
		printf("v[%d] = %d\n", i, v[i]);
		i++;
	}

	// v[0] = 1;
	// v[1] = 2;
	// v[2] = 3;
	// v[3] = 4;
	// v[4] = 5;
	//
	// printf("Valor do v[3] = %d\n", v[3]);


	// a = 10;
	// b = 6;
	// x = a / b;
	// r = a % b;
	//
	// printf("Olá 123\n");
	// printf("O resto foi %d\n", r);
	// printf("E a divisão foi %d\n", x);
	//
	// if (a > b) {
	// 	r = 0;
	// }
	// if (r == 0 && x >= 1) {
	// 	r = 50;
	// } else {
	// 	r = 100;
	// }
	//
	// printf("Valor de r = %d\n", r);
}
