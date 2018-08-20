/*
TITULO: Definição do Exercício T12
DATA: 11/Março/2016

Disciplina: Algoritmos e Programação II

Pode ser feito no máximo em TRIOS, desde que todos os envolvidos comecem
a sua solução durante a aula do dia 11 de Março de 2016.

Quem não vier na aula ou for embora mais cedo deverá realizar de
forma INDIVIDUAL.

Sua solução deve ser postada até o início da próxima aula no endereço

http://gravatai.ulbra.tche.br/~elgio/corrige.php

AINDA NA AULA DE HOJE os envolvidos devem cadastrar o grupo que irá
realizar o trabalho, precisando do número acadêmico.

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Objetivo deste exercício: uso de funções de entrada e saída e manipulação
de strings (até o visto na aula de hoje, não mais).

O exercício é uma CONTINUAÇÃO do T11, com alterações. Observe atentamente
o seu enunciado e as alterações que são necessárias. Quem não realizou
o T11 ou o realizou insuficiente, pode (deve) trabalhar em cima da resposta
postada pelo professor para o T11

Definição:

Faça um programa em C ANSI completo, com todo o esqueleto e bibliotecas
necessárias. O programa deverá realizar as seguintes etapas:

a) Defina duas constantes N1 e N2 com valores inteiros quaisquer.
Defina três variáveis inteiras. Duas delas deverão receber as
duas constantes. A terceira variável deverá receber o maior número
armazenado nas outras duas variáveis (que vieram das constantes)
(compile várias vezes com valores diferentes para N1 e N2, incluindo
ambas serem iguais, negativos, etc).
Peça que o usuário digite seu nome completo, sem acentos, bem como
o nome de seu pai e de sua mãe. Todos os nomes devem caber em 100 posições
(crie variáveis strings para receber estes nomes).

b) Imprima mensagens completas para estes números, dizendo qual o
valor de N1, qual o valor de N2, qual é o menor e qual é o maior entre
eles. Se forem iguais, imprima que são iguais. Diga se o menor entre
eles é PAR ou IMPAR (ou para ambas, se forem iguais).

c) Defina um vetor com 53 números inteiros. Peça que o usuário digite
os três primeiros elementos (vet[0], vet[1] e vet[2]) e não permita
que ele digite números negativos e nem duas entradas iguais.
Se ele digitar isso, peça que digite novamente e leia novamente.
Pegue a diferença entre o maior e o menor valor digitado para vet[0] e
vet[1] e use este valor para alimentar as demais posições
(vet[3] em diante).

Cada posição seguinte (a partir do vet[3]) será a soma do anterior com
esta diferença.

Exemplo: digamos que o usuário digite 33 para vet[0], 19 para vet[1] e
5 para vet[2] (que serão aceitos, pois não são negativos e nem iguais).
A diferença entre eles é 14 (33 - 19, maior - menor).

Os vetores ficarão assim:
vet[0] = 33 (o que o usuário digitou)
vet[1] = 19 (o que o usuário digitou)
vet[2] = 5  (o que o usuário digitou)
vet[3] = 19 (vet[2] + 14, ou seja, 5+14= 19)
vet[4] = 33 (vet[3] + 14, ou seja, 19+14= 33)

E assim por diante até o vet[52]. vet[4] ter dado igual ao que o usuário
digitou para vet[0] foi apenas uma coincidência aqui.


d) Após a geração do vetor, e somente após, percorra o vetor e, para
cada elemento, verifique se o número é PAR ou IMPAR.
Imprima a palavra PAR ou IMPAR para cada número do elemento.
Informe também se aquele número é um número PRIMO (se não for PRIMO,
imprima o próximo PRIMO depois dele.

Exemplo: se o elemento for 8, oito não é primo. Então deve imprimir
a mensagem

"8 não é primo. O próximo primo depois do 8 é o 11",

porque 11 realmente é o próximo primo depois do 8.

(O ITEM D ACIMA NÃO SOFREU NENHUMA ALTERAÇÃO, EXCETO QUE O TAMANHO
DO VETOR É 53 agora)

E) Imprima na tela o nome digitado (no item A), junto com a
quantidade de letras que ele possui. Idem para o nome do pai e da mãe.
*/

#include <stdio.h>
#include <string.h>

#define N1 5
#define N2 4
#define TAMNOME 100
#define VETTAM 53

main() {
	//Variáveis loops
	int i, j;

	//Variáveis etapa a e e
	char nome[TAMNOME],
		nomePai[TAMNOME],
		nomeMae[TAMNOME];

	//Variáveis etapa b
	int a = N1,
		b = N2,
		c;

	//Variáveis etapa c e d
	int vet[VETTAM],
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

	printf("Digite o seu nome completo: ");
	fgets(nome, TAMNOME, stdin);
	printf("Digite o nome do seu pai: ");
	fgets(nomePai, TAMNOME, stdin);
	printf("Digite o nome da sua mãe: ");
	fgets(nomeMae, TAMNOME, stdin);

	//Etapa b
	printf("\nO valor de N1 eh: %d\n", a);
	printf("O valor de N2 eh: %d\n", b);

	if (a == b) {
		printf("O valor dos dois numeros sao iguais ");
		if (a % 2 == 0) {
			printf("e eles sao pares.\n");
		} else {
			printf("e eles sao impares.\n");
		}
	} else if (a > b) {
		printf("O valor de N1 eh o maior e N2 o menor entre eles. ");
		if (b % 2 == 0) {
			printf("O menor entre eles tambem eh par.\n");
		} else {
			printf("O menor entre eles tambem eh impar.\n");
		}
	} else {
		printf("O valor de N2 eh o maior e N1 o menor entre eles. ");
		if (a % 2 == 0) {
			printf("O menor entre eles tambem eh par.\n");
		} else {
			printf("O menor entre eles tambem eh impar.\n");
		}
	}

	//Etapa c
	printf("\nDigite tres elementos inteiros. (nao podem ser negativos e nem iguais uns aos outros)\n");
	printf("Digite o primeiro elemento: ");
	scanf("%i", &vet[0]);
	while (vet[0] < 0) {
		printf("Numero invalido. Digite novamente o primeiro elemento: ");
		scanf("%i", &vet[0]);
	}
	printf("Digite o segundo elemento: ");
	scanf("%i", &vet[1]);
	while (vet[1] < 0 || vet[1] == vet[0]) {
		printf("Numero invalido. Digite novamente o segundo elemento: ");
		scanf("%i", &vet[1]);
	}
	printf("Digite o terceiro elemento: ");
	scanf("%i", &vet[2]);
	while (vet[2] < 0 || vet[2] == vet[1] || vet[2] == vet[0]) {
		printf("Numero invalido. Digite novamente o terceiro elemento: ");
		scanf("%i", &vet[2]);
	}

	if (vet[0] > vet[1]) {
		diff = vet[0] - vet[1];
	} else {
		diff = vet[1] - vet[0];
	}

	for (i = 3; i < VETTAM; i++) {
		vet[i] = vet[i - 1] + diff;
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

	//Etapa e
	printf("\nNome digitado: %sPossui %d letras\n", nome, strlen(nome) - 1);
	printf("\nNome do pai digitado: %sPossui %d letras\n", nomePai, strlen(nomePai) - 1);
	printf("\nNome da mae digitado: %sPossui %d letras\n", nomeMae, strlen(nomeMae) - 1);
}
