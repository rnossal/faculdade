/*
Faça um programa que lê um número não determinado de valores para m, todos inteiros e positivos, um de cada vez. Se m for par, verificar quantos divisores possui e escrever esta informação. Se m for ímpar e menor do que 10 calcular e escrever o fatorial de m. Se m for ímpar e maior ou igual a 10 calcular e escrever a soma dos inteiros de 1 até m. Se m for negativo encerra o programa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");

	int m,
		i,
		divisores,
		fatorial,
		soma;
	
	while(1) {
		printf("Digite o valor número a ser lido: ");
		scanf("%i", &m);
		
		if(m < 0) {
			break;
		} else if (m % 2 == 0) {
			divisores = 0;
			for(i = 1; i < m; i++) {
				if(m % i == 0) {
					divisores++;
				}
			}
			printf("O número %i possui %i divisores.\n", m, divisores);
		} else {
			if(m < 10) {
				fatorial = 1;
				for(i = m; i > 0; i--) {
					fatorial *= i;
				}
				printf("O fatorial de %i é %i.\n", m, fatorial);
			} else {
				soma = 0;
				for(i = 1; i <= m; i++) {
					soma += i;
				}
				printf("A soma de todos inteiros de 1 até o número %i é %i.\n", m, soma);
			}
		}
	}

	system("pause");
}