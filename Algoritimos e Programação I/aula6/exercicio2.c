/*
Implemente um Programa em C, que leia 20 valores, todos inteiros e positivos e ao final mostre ao usuário a quantidade de valores pares e a quantidade de valores ímpares digitados. Os valores negativos devem ser desconsiderados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");

	int contador = 0,
		valor = 0,
		pares = 0,
		impares = 0;

	while (contador < 20) {
		printf("Digite um valor inteiro: ");
		scanf("%i", &valor);

		if (valor > 0) {
			if (valor % 2 == 0) {
				pares++;
			} else {
				impares++;
			}
		}
		contador++;
	}

	printf("\nValores pares inseridos: %i\n"
			"Valores ímpares inseridos: %i\n", pares, impares);

	system("pause");
}