/*
Implemente um programa em C, que a partir da opção do usuário, calcula e escreve a média aritmética ou a média ponderada de três valores quaisquer. Considere os pesos 2, 3 e 5 para a média ponderada.
*/

#include <stdio.h>
#include <stdlib.h>

main() {
	float val1, val2, val3, media, ponderada;
	int op;

	printf("Digite o primeiro valor: ");
	scanf("%f", &val1);
	printf("Digite o segundo valor: ");
	scanf("%f", &val2);
	printf("Digite o terceiro valor: ");
	scanf("%f", &val3);
	printf("Digite o tipo de media a calcular com base nas opcoes abaixo:\n\n"
		"1: Media aritmatica\n"
		"2: Media ponderada\n");
	scanf("%i", &op);

	switch(op) {
		case 1:
			printf("Media aritmetica: %.2f\n", (val1 + val2 + val3) / 3);
			break;
		case 2:
			printf("Media ponderada: %.2f\n", (val1 * 2 + val2 * 3 + val3 * 5) / (2 + 3 + 5));
			break;
		default:
			printf("Tipo de peracao invalida.\n");
	}

	system("pause");
}