/*
Escrever um programa em Linguagem C, que leia dois valores inteiros. Verifique e emita a mensagem se “são múltiplos” ou “não são múltiplos”. Mostre o resultado fina ao usuário.
*/

#include <stdio.h>
#include <stdlib.h>

main() {
	int val1, val2;

	printf("Digite o primeiro valor: ");
	scanf("%i", &val1);
	printf("Digite o segundo valor: ");
	scanf("%i", &val2);

	if(val1 % val2 == 0) {
		printf("Sao multiplos\n");
	} else {
		printf("Nao sao multiplos\n");
	}

	system("pause");
}