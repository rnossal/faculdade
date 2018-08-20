/*
Construa um algoritmo com uma funçãoo que leia a cotação do dólar, leia 3 valores em dólar, converta esses valores para real e mostre o resultado. 
*/
#include <stdio.h>
int main (void) {
	float cotacao, val1, val2, val3;
	printf("Digite a cotacao do dolar:\n");
	scanf("%f", &cotacao);
	printf("Digite o primeiro valor em dolar:\n");
	scanf("%f", &val1);
	printf("Digite o segundo valor em dolar:\n");
	scanf("%f", &val2);
	printf("Digite o terceiro valor em dolar:\n");
	scanf("%f", &val3);

	printf("Primeiro valor: %f\nSegundo valor: %f\nTerceiro valor: %f\n", val1 * cotacao, val2 * cotacao, val3 * cotacao);
	system("pause");
}
