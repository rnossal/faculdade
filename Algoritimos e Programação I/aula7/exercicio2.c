/*
Escreva um programa que lê 30 valores, um de cada vez, e conta quantos deles estão no intervalo [10,20] e quantos deles estão fora do intervalo, escrevendo estas informações.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");

	int contador = 0,
		valor = 0,
		intervalo = 0;

	while (contador < 30) {
		printf("Digite um valor: ");
		scanf("%i", &valor);
		if (valor >= 10 && valor <= 20) {
			intervalo++;
		}
		contador++;
	}
	
	printf("Quantidade de números no intervalo de 10 a 20: %i\n"
			"Quantidade de números fora desse intervalo: %i\n", intervalo, contador - intervalo);

	system("pause");
}