/*
A partir dos enunciados abaixo, implemente os trechos de programa relativo aos três comandos de repetição estudados, declare as variáveis utilizadas.
Para ler 3500 valores quaisquer.

*/
#include <stdio.h>
#include <stdlib.h>

main() {
	int i,
		valor ;

	for(i = 0; i < 3500; i++) {
		printf("Digite um valor: ");
		scanf("%i", &valor);
	}

	system("pause");
}