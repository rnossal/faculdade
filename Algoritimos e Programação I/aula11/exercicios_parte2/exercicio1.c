/*
Escreva um programa que leia 20 valores para uma variável n e, para cada um deles, calcule a tabuada de 1 até n. Mostre a tabuada na forma: 
1 x n = n 
2 x n = 2n 
3 x n = 3n 
....... 
n x n = n2
*/

#include <stdio.h>
#include <stdlib.h>

main() {
	int cont,
		valor,
		fator;

	for(cont = 0; cont < 20; cont++) {
		printf("Digite o valor: ");
		scanf("%i", &valor);

		for(fator = 1; fator <= valor; fator++) {
			printf("%i x %i = %i\n", fator, valor, fator * valor);
		}
	}

	system("pause");
}