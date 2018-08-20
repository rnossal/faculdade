/*
Implemente um Programa em C que insira em um Vetor V, 20 valores inteiros, e:

a) Imprima apenas os elementos que estão nas posições pares (indexadores) do vetor;
b) Imprima apenas os elementos que estão nas posições múltiplas de 4 (indexadores) do vetor;
c) Imprima o vetor em ordem inversa.
d) Apresente a média aritmética apenas dos valores pares;
e) Apresente a média aritmética apenas dos valores ímpares.

Observação: As impressões devem ser devidamente identificadas para o usuário,
lembre-se que ele (o usuário) deve saber o que está sendo impresso. Um “monte” de números não significa nada!
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define QTD_VET 20

#ifdef _WIN32
	#define IS_WINDOWS 1
#else
	#define IS_WINDOWS 0
#endif

main() {
	setlocale(LC_ALL, "Portuguese");

	int i,
		vet[QTD_VET],
		soma_pares = 0,
		qtd_pares = 0,
		soma_impares = 0,
		qtd_impares = 0;

	printf("Insira 20 números inteiros para ser colocado em um vetor.\n\n");
	for(i = 0; i < QTD_VET; i++) {
		printf("Insira o %iº número inteiro: ", i + 1);
		scanf("%i", &vet[i]);
	}

	if(IS_WINDOWS) {
		system("cls");
	}

	printf("Os elementos que estão em posições pares do vetor são: ");
	for(i = 0; i < QTD_VET; i++) {
		if(i % 2 == 0) {
			printf("%i ", vet[i]);
		}
	}
	printf("\nOs elementos que estão em posições múltiplas de 4 do vetor são: ");
	for(i = 0; i < QTD_VET; i++) {
		if(i % 4 == 0) {
			printf("%i ", vet[i]);
		}
	}
	printf("\nO vetor em ordem inversa se dá por: ");
	for(i = QTD_VET - 1; i >= 0; i--) {
		printf("%i ", vet[i]);
	}
	for(i = 0; i < QTD_VET; i++) {
		if(vet[i] % 2 == 0) {
			qtd_pares++;
			soma_pares += vet[i];
		} else {
			qtd_impares++;
			soma_impares += vet[i];
		}
	}
	printf("\nA média dos valores pares inseridos se dá por: %i", soma_pares / qtd_pares);
	printf("\nA média dos valores ímpares inseridos se dá por: %i\n", soma_impares / qtd_impares);

	if(IS_WINDOWS) {
		system("pause");
	}
}
