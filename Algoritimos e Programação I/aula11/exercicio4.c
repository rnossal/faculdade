/*
Escreva um programa que leia um número não determinado de valores e calcule a média aritmética dos valores lidos, a quantidade de valores positivos, a quantidade de valores negativos e o percentual de valores negativos e positivos. Mostre os resultados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");

	int positivo = 0,
		negativo = 0,
		cont,
		deter;
	float valor = 0,
		soma = 0;

	printf("Ditermine o número da valores a serem lidos: ");
	scanf("%i", &deter);
	
	for(cont = 0; cont < deter; cont++) {
		printf("Digite um valor: ");
		scanf("%f", &valor);

		if(valor > 0) {
			positivo++;
		} else if(valor < 0) {
			negativo++;
		}

		soma += valor;
	}
	printf("Média dos valores: %.2f\n",  soma / (negativo + positivo));
	printf("Quantidade de valores positivos: %i\n", positivo);
	printf("Quantidade de valores negativos: %i\n", negativo);
	printf("Percentutal de valores positivos: %.2d%%\n", (positivo * 100) / cont);
	printf("Percentutal de valores negativos: %.2d%%\n", (negativo * 100) / cont);

	system("pause");
}