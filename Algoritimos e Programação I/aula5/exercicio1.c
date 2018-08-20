/*
Implemente um Programa em Linguagem C, que leia três valores quaisquer, calcule e escreva a média aritmética e harmônica desses valores. Ao final apresente ao usuário as duas médias devidamente identificadas. Para o cálculo da média harmônica utilize a fórmula abaixo:
media=3/(1/v1 + 1/v2 + 1/v3)
*/

#include <stdio.h>
#include <stdlib.h>

main() {
	float val1, val2, val3, media, harmonica;

	printf("Digite o primeiro valor: ");
	scanf("%f", &val1);
	printf("Digite o segundo valor: ");
	scanf("%f", &val2);
	printf("Digite o terceiro valor: ");
	scanf("%f", &val3);

	media = (val1 + val2 + val3) / 3;
	harmonica = 3 / (1 / val1 + 1 / val2 + 1 / val3);
	
	printf("\nMedia aritmetica dos valores: %.2f\n"
		"Media harmonica dos valores: %.2f\n", media, harmonica);

	system("pause");
}