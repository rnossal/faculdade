/*
Faça um programa que calcula o estoque médio de uma peça, para isso solicite ao usuário que informade o estoque mínimo e o estoque máximo da mesma.
*/
#include <stdio.h>
int main (void) {
	int minimo, maximo;
	printf("Digite o estoque minimo:\n");
	scanf("%i", &minimo);
	printf("Digite o estoque maximo:\n");
	scanf("%i", &maximo);

	int total = (minimo + maximo) / 2;

	printf("Estoque medio: %i\n", total);
	system("pause");
}
