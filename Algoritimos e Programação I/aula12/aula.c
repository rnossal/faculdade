#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 3

main() {
	setlocale(LC_ALL, "Portuguese");

	int i;
	float nota[TAM],
		media,
		soma = 0;

	for(i = 0; i < TAM; i++) {
		printf("Diga o valor para a posição %i: ", i + 1);
		scanf("%f", &nota[i]);
	}
	for (i = 0; i < TAM; i++) {
		soma += nota[i];
	}
	for(i = 0; i < TAM; i++) {
		printf("%f\t", nota[i]);
	}
	media = soma/(float)TAM;
	printf("\n%f\n", media);
}