/*
Escreva um programa que gera e escreve os 5 primeiros números perfeitos. Um número perfeito é aquele que é igual a soma dos seus divisores.
(Ex.: 6 = 1+2+3; 28= 1+2+4+7+14 etc).
*/

#include <stdio.h>
#include <stdlib.h>

main() {
	int perfeitos = 0,
		soma,
		i,
		j;

	for(i = 1; perfeitos != 5; i++) {
		soma = 0;
		for(j = 1; j < i; j++) {
			if(i % j == 0) {
				soma += j;
			}
		}
		if(soma == i) {
			printf("%i\n", i);
			perfeitos++;
		}
	}

	system("pause");
}