/*
Implemente um Programa em C, que a partir dos valores positivos inseridos pelo usuário, apresente ao final da leitura:
	A quantidade de valores lidos;
	A soma dos valores;
	A média aritmética dos valores.
A finalização da leitura se dará quando o usuário digitar um valor negativo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");

	int valor = 0,
		soma = 0,
		quantidade = 0;

	while (valor >= 0) {
		printf("Digite em valor: ");
		scanf("%i", &valor);
		if (valor >= 0) {
			soma += valor;
			quantidade++;
		}
	}

	printf("Quantidade de valores lidos: %i\n"
			"Soma dos valores: %i\n"
			"Média aritmética dos valores: %d\n", quantidade, soma, soma / quantidade);

	system("pause");
}