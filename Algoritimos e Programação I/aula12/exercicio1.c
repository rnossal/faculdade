/*
Faça um programa que leia 10 notas e ao final apresente
- a maior nota
- a menor nota
- a media das notas
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define QTD_NOTAS 10

main() {
	setlocale(LC_ALL, "Portuguese");

	int i;
	float nota[QTD_NOTAS],
		maior,
		menor,
		soma = 0;

	for(i = 0; i < QTD_NOTAS; i++) {
		printf("Diga o valor da %iª nota: ", i + 1);
		scanf("%f", &nota[i]);
	}
	for(i = 0; i < QTD_NOTAS; i++) {
		soma += nota[i];
		if(i == 0) {
			maior = menor = nota[i];
		}
		if(nota[i] > maior) {
			maior = nota[i];
		}
		if(nota[i] < menor) {
			menor = nota[i];
		}
	}
	printf("Maior nota: %.2f\n"
			"Menor nota: %.2f\n"
			"Média das notas: %.2f\n", maior, menor, soma / (float)QTD_NOTAS);

	system("pause");
}