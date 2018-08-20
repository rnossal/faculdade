/*
Objetivo deste exercício: aplicar o conceito de funções.

Trata-se do mesmo exercício T11, porém agora com a necessidade de algumas
tarefas serem feitas como função.

Definição:

Faça um programa em C ANSI completo, com todo o esqueleto e bibliotecas
necessárias. O programa deverá realizar as seguintes etapas:

a) Defina duas constantes N1 e N2 com valores inteiros quaisquer.
Defina duas variáveis inteiras. Duas delas deverão receber as
duas constantes. Crie uma função que receba dois números e retorne
(não imprima) o maior deles.

b) Faça uma função que retorne o menor dentre estes dois números.
Use este menor para executar uma outra função que imprime se
aquele número é par ou impar. (a função parimpar não retorna nada,
ela apenas imprime uma mensagem se par ou impar).

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
cada elemento, invoque a função que você criou no item b para imprimir
se é par ou impar.

e) Faça uma função que receba um número inteiro qualquer. A função não
imprime nada, mas retorna:
     0 - O número que foi passado é um número PRIMO.
     > 0 - O número que foi passado não é PRIMO e o valor retornado é do
           próximo primo depois dele.

 Esta função pode fazer uso de outras funções que você ache necessário
 construir.

No main, para cada elemento do vetor criado em c, invoque a função que
você criou, guardando o resultado em uma variável. Se o resultado
retornado for ZERO, imprima a mensagem de que este número é PRIMO.

Se o valor retornado for maior que o valor passado, imprima a mensagem
de que não é primo e qual é o próximo primo.
(observe que é o mesmo que se fez no T11, porém agora com o uso de
função e com a função tendo este comportamento).

Exemplo 1: se o elemento do vetor for 7, então deve imprimir:

"7 é um número primo".

Ao passar 7 para a tua função ela deve retornar ZERO, indicando que o
7 é um número primo.


Exemplo 2: se o elemento for 8, oito não é primo. Então deve imprimir
a mensagem

"8 não é primo. O próximo primo depois do 8 é o 11",

porque 11 realmente é o próximo primo depois do 8.

A função que você criou retornou o valor 11 que. Como não foi ZERO,
não era primo, então o valor retornado é o próximo primo.
*/

#include <stdio.h>

#define N1 4
#define N2 10
#define QTDVET 30

//Etapa a
int maior(int num1, int num2) {
	if (num1 > num2) {
		return num1;
	} else {
		return num2;
	}
}

//Etapa b
int menor(int num1, int num2) {
	if (num1 < num2) {
		return num1;
	} else {
		return num2;
	}
}
parImpar(int x) {
	if (x % 2 == 0) {
		printf("%d eh par\n", x);
	} else {
		printf("%d eh impar\n", x);
	}
}

//Etapa e
int ehPrimo(int num) {
	int i,
		divisivel = 0;

	for (i = num; i > 0; i--) {
		if (num % i == 0) {
			divisivel++;
		}
	}
	if (divisivel == 2) {
		return 0;
	} else {
		return proxPrimo(num);
	}
}
int proxPrimo(int num) {
	int i,
		prox = num,
		divisivel = 0;

	while (divisivel != 2) {
		divisivel = 0;
		prox++;
		for (i = prox; i > 0; i--) {
			if (prox % i == 0) {
				divisivel++;
			}
		}
	}

	return prox;
}

main() {
	//Variáveis loops
	int i;

	//Variáveis etapa a
	int a = N1,
		b = N2;

	//Variáveis etapa c
	int diff,
		vet[QTDVET];

	//Variáveis etapa e
	int primo;

	//Etapa b
	parImpar(menor(a, b));

	//Etapa c
	if (a > b) {
		diff = a - b;
	} else {
		diff = b - a;
	}

	vet[0] = 0;

	for (i = 1; i < QTDVET; i++) {
		if (vet[i - 1] + diff >= 1000 || vet[i - 1] + diff <= -1000) {
			vet[i] = i;
		} else {
			vet[i] = vet[i - 1] + diff;
		}
	}

	//Etapa d
	for (i = 0; i < QTDVET; i++) {
		parImpar(vet[i]);
	}

	//Etapa e
	for (i = 0; i < QTDVET; i++) {
		primo = ehPrimo(vet[i]);
		if (primo == 0) {
			printf("%d eh um numero primo.\n", vet[i]);
		} else {
			printf("%d nao eh primo. O proximo primo depois de %d eh o %d\n", vet[i], vet[i], primo);
		}
	}
}
