/*
Objetivo deste exercício: questões práticas da prova

Definição:

Refaça as questões práticas da prova. Mesmo que você tenha acertado.
Independente do modelo da prova, faça a seguinte questão:


 7. (3,0) Faça um programa completo, com o main e as funções que julgar
 necessário, que peça para o usuário digitar duas strings. Cada uma delas
 não pode ter mais do que 100 caracteres. O programa deverá:
 a) Imprimir uma mensagem dizendo se elas são iguais ou qual é a maior.
 b) Imprimir cada string juntamente com o seu tamanho.
 c) Criar uma terceira string de até 200 cars que tenha a concatenação
 da maior com a menor. Veja, sempre a maior primeiro. Imprimir esta
 string (ela precisa realmente ser criada, não basta apenas imprimir)
Acompanhe exemplo de uso (linhas que tem o <ENTER> é o que o usuário
digita, como se fosse um teste no prompt do windows):

C:\> questao7<ENTER>
Digite duas strings de até 100 cars cada uma:
Isto eh um teste<ENTER>
Novamente mais um outro teste<ENTER>

As strings que você digitou não são iguais.
"Novamente mais um outro teste" é a maior digitada.
"Isto eh um teste" - 16 cars
"Novamente mais um outro teste" - 29 cars
A string concatenada ficou:
"Novamente mais um outro testeIsto eh um teste"

C:\>

8A) Implemente uma função, apenas a função, que receba dois números
inteiros. Ela deve retornar o somatório do maior número.

8B) Implemente uma função, apenas a função, que receba dois números
inteiros. Ela deve retornar o fatorial do menor número.

Coloque as funções 8A e 8B no main da 7.
*/
#include <stdio.h>
#include <string.h>

#define STRMAX 101

int somatorio(int a, int b) {
	int maior,
		i,
		lim;

	if (a > b) {
		maior = a;
	} else {
		maior = b;
	}
	lim = maior;

	for (i = 1; i < lim; i++) {
		maior += i;
	}

	return maior;
}
int fatorial(int a, int b) {
	int menor,
		i,
		lim;

	if (a < b) {
		menor = a;
	} else {
		menor = b;
	}
	lim = menor;

	for (i = 1; i < lim; i++) {
		menor *= i;
	}

	return menor;
}

main() {
	char st1[STRMAX],
		st2[STRMAX],
		st3[STRMAX * 2];

	printf("Digite a primeira string: ");
	fgets(st1, STRMAX, stdin);
	printf("Digite a segunda string: ");
	fgets(st2, STRMAX, stdin);

	strtok(st1, "\n");
	strtok(st2, "\n");

	if (strncmp(st1, st2, STRMAX) == 0) {
		printf("As duas sao iguais!\n");
	} else if (strncmp(st1, st2, STRMAX) > 0) {
		printf("As duas nao sao iguais!\n");
		printf("\"%s\" eh a maior\n", st1);
		strncpy(st3, st1, STRMAX);
		strncat(st3, st2, STRMAX);
	} else {
		printf("As duas nao sao iguais!\n");
		printf("\"%s\" eh a maior\n", st2);
		strncpy(st3, st2, STRMAX);
		strncat(st3, st1, STRMAX);
	}

	printf("\"%s\" - %d cars\n", st1, strlen(st1));
	printf("\"%s\" - %d cars\n", st2, strlen(st2));
	printf("A string concatenada eh:\n\t\"%s\"\n", st3);

	//=================================
	printf("%d\n", somatorio(5, 4));
	printf("%d\n", fatorial(6, 5));
}
