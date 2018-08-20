/*
Faça um programa em C ANSI completo, com todo o esqueleto e bibliotecas
necessárias. O programa deverá realizar as seguintes etapas:

a) Defina duas constantes N1 e N2 com valores inteiros quaisquer.
Defina três variáveis inteiras. Duas delas deverão receber as
duas constantes. A terceira variável deverá receber o maior número
armazenado nas outras duas variáveis (que vieram das constantes)
(compile várias vezes com valores diferentes para N1 e N2, incluindo
ambas serem iguais, negativos, etc)

b) Imprima a mensagem PAR se a menor constante (entre N1 e N2) for PAR e
a mensagem IMPAR se a menor constante for IMPAR. Importante: só use as
constantes para atribuir para tuas variaveis (item A). Qualquer operação
deve ser feita com variáveis.

c) Defina um vetor com 30 números inteiros. Alimente a primeira posição
com o valor 0. Cada posição seguinte será a soma do anterior com a
diferença entre as constantes. Sempre diminuindo a maior da menor.

Exemplo: digamos que N1 seja 4 e N2 seja 10. N2 é maior, então deve-se
diminuir N2 de N1 ficando com 6. Este número, 6, será usado para alimentar
o vetor. Primeira posição receberá 0, segunda receberá 0+6=6, terceira
receberá 6+6=12, quarta 12+6=18 e assim por diante, até a última
posição. Se algum elemento for maior que 1000 ou menor que -1000,
atribua a este elemento o seu indice (exemplo: se vet[20] resultou em
1006, então vet[20] deve receber 20. Para vet[21] segue a soma de antes.

Observe que se N1 fosse 10 e N2 fosse 4, a soma não seria -6, mas
6 mesmo, pois sempre deve diminuir o maior do menor.

d) Após a geração do vetor, e somente após, percorra o vetor e, para
cada elemento, verifique se o número é PAR ou IMPAR.
Imprima a palavra PAR ou IMPAR para cada número do elemento.
Informe também se aquele número é um número PRIMO (se não for PRIMO,
imprima o próximo PRIMO depois dele.

Exemplo: se o elemento for 8, oito não é primo. Então deve imprimir
a mensagem

"8 não é primo. O próximo primo depois do 8 é o 11",

porque 11 realmente é o próximo primo depois do 8.
*/

#include <stdio.h>
#define N1 3
#define N2 8

main() {
	//Variáveis loops
	int i, j;
	//Variáveis etapa a, b e c
	int a = N1,
		b = N2,
		c;
	//Variáveis etapa c
	int vet[30],
		diff;

	//Variáveis etapa d
	int divisivel,
		proxPrimo;

	//Etapa a
	if (a > b) {
		c = a;
	} else {
		c = b;
	}

	//Etapa b
	if (a < b) {
		if (a % 2 == 0) {
			printf("PAR\n");
		} else {
			printf("IMPAR\n");
		}
	} else {
		if (b % 2 == 0) {
			printf("PAR\n");
		} else {
			printf("IMPAR\n");
		}
	}

	//Etapa c
	if (a > b) {
		diff = a - b;
	} else {
		diff = b - a;
	}

	vet[0] = 0;

	for (i = 1; i < 30; i++) {
		if (vet[i - 1] + diff >= 1000 || vet[i - 1] + diff <= -1000) {
			vet[i] = i;
		} else {
			vet[i] = vet[i - 1] + diff;
		}
	}

	//Etapa d
	for (i = 0; i < 30; i++) {
		if (vet[i] % 2 == 0) {
			printf("PAR\n");
		} else {
			printf("IMPAR\n");
		}
		divisivel = 0;
		for (j = vet[i]; j > 0; j--) {
			if (vet[i] % j == 0) {
				divisivel++;
			}
		}
		if (divisivel == 2) {
			printf("%d é primo\n", vet[i]);
		} else {
			proxPrimo = vet[i];
			while (divisivel != 2) {
				divisivel = 0;
				proxPrimo++;
				for (j = proxPrimo; j > 0; j--) {
					if (proxPrimo % j == 0) {
						divisivel++;
					}
				}
			}
			printf("%d não é primo. O proximo primo depois do %d é o %d\n", vet[i], vet[i], proxPrimo);
		}
	}
}
