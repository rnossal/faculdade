/*
Considere uma sala de cinema com cadeiras numeradas. Cada FILA tem uma
letra do alfabeto e em cada fila tem cadeiras de numeros 1 até N.
Considera-se que qualquer sala, por maior que seja, nunca terá mais
do que 26 filas (A a Z) e 100 cadeiras em cada fila. Porém uma sala pode
ter menos filas e em cada fila podem ter menos cadeiras.

Faça um programa que gerencie esta sala através de uma matriz FILAxCADEIRAS.

As filas na matriz serão numeradas de 0 a 25, como são os índices de
uma matriz, mas você jamais deverá informar ao usuário FILA 0, mas sim
FILA A (A=0, B=1, ... Z=25). Também não diga A0, cadeira 0 da fila A,
mas sim A1, cadeira número 1 da fila A (internamente, na sua matriz,
este assento estará na matriz [0][0]).

Ao iniciar o sistema pergunte ao usuário quantas filas a sala tem,
não permitindo ser maior do que o máximo (26). Depois pergunte quantos
assentos tem a maior fila (tamMaiorFila), não podendo ser maior que 100.

Inicialize a matriz da seguinte forma:

- para cada fila, pergunte quantos assentos tem aquela fila em específico,
não ultrapassando o tamMaiorFila. Coloque 0 em todos os assentos
daquela fila e -1 nos assentos que não fazem parte.

Exemplo: se a fila A tem 20 assentos, as colunas [0] a [19] desta fila
recebem 0 e as colunas de [20] até [tamMaiorFila-1] recebem -1.
-1 indica cadeira inixistente.

O sistema deverá automaticamente ignorar os assentos de [tamMaiorFila] até
[99] porque já foi dito no início que a maior fila tem tamMaiorFila assentos.
*/
#include <stdio.h>

#define TAMFILA 26
#define TAMCADEIRA 100

char getNomeFila(int num) {
	return num + 65;
}
initCadeiras(int vet[][TAMCADEIRA], int qtdFila, int qtdMCadeira) {
	int i, j, qtdAssento;
	for (i = 0; i < qtdFila; i++) {
		printf("Quantos assentos possui a fila %c? ", getNomeFila(i));
		scanf("%i", &qtdAssento);
		while (qtdAssento > qtdMCadeira) {
			printf("O tamanho eh maior que a maior fila. Informe um valor valido: ");
			scanf("%i", &qtdAssento);
		}
		for (j = 0; j < qtdAssento; j++) {
			vet[i][j] = 0;
		}
		for (j=j; j < qtdMCadeira; j++) {
			vet[i][j] = -1;
		}
	}
}

main() {
	int i,
		qtdFila,
		tamMaiorFila,
		sala[TAMFILA][TAMCADEIRA];

	printf("Informe quantas filas havera na sala: ");
	scanf("%i", &qtdFila);
	while(qtdFila > 26 || qtdFila <= 0) {
		printf("Tamanho invalido. Informe novamente: ");
		scanf("%i", &qtdFila);
	}
	printf("Informe quantas cadeiras tem a maior fila: ");
	scanf("%i", &tamMaiorFila);
	while(tamMaiorFila > 100 || tamMaiorFila <= 0) {
		printf("Tamanho invalido. Informe novamente: ");
		scanf("%i", &tamMaiorFila);
	}

	initCadeiras(sala, qtdFila, tamMaiorFila);
}
