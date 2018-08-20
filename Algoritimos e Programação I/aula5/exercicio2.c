/*
Implemente um Programa em C, que leia a quantidade de pessoas hospedadas em uma Pousada, bem como o tempo (em dias) que eles ficarão na Pousada. O algoritmo deve calcular e escrever o valor total a pagar considerando que a diária por pessoa é de R$ 234,00 e que é cobrado também por pessoa uma taxa de serviço de 5% do valor total.
*/

#include <stdio.h>
#include <stdlib.h>

main() {
	int pessoas, tempo;
	float valorTotal;
	
	printf("Digite a quantidade de pessas hospedadas: ");
	scanf("%i", &pessoas);
	printf("Digite o tempo em que ficarao hospedadas: ");
	scanf("%i", &tempo);

	valorTotal = pessoas * (tempo * 234);
	valorTotal += valorTotal * 0.05;

	printf("Valor total a ser pago: %.2f\n", valorTotal);

	system("pause");
}