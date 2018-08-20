/*
Escreva um programa que leia um número n que indica quantos valores devem ser lidos a seguir. Para cada número lido, mostre uma tabela contendo o valor lido e o fatorial deste valor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");

	int cont,
		qtd,
		valor,
		contFatorial,
		fatorial = 1;

	printf("Digite a quantidade de números a serem lidos: ");
	scanf("%i", &qtd);
	for(cont = 0; cont < qtd; cont++) {
		printf("Digite o valor: ");
		scanf("%i", &valor);

		for(contFatorial = valor; contFatorial > 0; contFatorial--) {
			fatorial *= contFatorial;
		}

		printf("%i - %i\n", valor, fatorial);
		fatorial = 1;
	}

	system("pause");
}