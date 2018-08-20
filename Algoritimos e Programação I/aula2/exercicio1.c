/*
Faça um programa que solicita ao usuário 4 valores, calcule o quadrado de cada um, some todos os resultados e mostre o resultado final.
*/
#include <stdio.h>
#include <math.h>
int main (void) {
	float val1, val2, val3, val4;
	printf("Digite o primeiro valor:\n");
	scanf("%f", &val1);
	printf("Digite o segundo valor:\n");
	scanf("%f", &val2);
	printf("Digite o terceiro valor:\n");
	scanf("%f", &val3);
	printf("Digite o quarto valor:\n");
	scanf("%f", &val4);

	float total = pow(val1, 2) + pow(val2, 2) + pow(val3, 2) + pow(val4, 2);

	printf("Total: %f\n", total);
	system("pause");
}
