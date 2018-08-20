/*
Faça um programa em Linguagem C, que leia um número inteiro, verifique se é positivo ou negativo. Se for positivo, emita uma mensagem ao usuário indicando se este número é par, ímpar ou neutro. Se for negativo, imprima a mensagem: “Valor Negativo!”.
*/

#include <stdio.h>
#include <stdlib.h>

main() {
	int num;

	printf("Digite um numero inteiro: ");
	scanf("%i", &num);

	if(num >= 0) {
		if (num == 0) {
			printf("Numero neutro\n");
		} else if(num % 2 == 0) {
			printf("Numero par\n");
		} else {
			printf("Numero impar\n");
		}
	} else {
		printf("Valor negativo\n");
	}

	system("pause");
}