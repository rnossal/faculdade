/*
Considere um main e a declaração dos seguintes vetores:

- três vetores de inteiros
- três vetores de doubles

Todos de TAM tamanho, sendo TAM um define declarado como 10.
Considere que o TAM pode mudar a qualquer momento, e que deve ser
suficiente apenas alterar o define.

Escolha os nomes que quiser. Aqui vamos referenciar como vetor 1, 2 e 3.
Não pode usar variáveis globais. Tudo que a função precisa para funcionar
ou ela cria ou recebe do main por parâmetros.

A) Faça uma função que receba um vetor de inteiros e inicialize todos
os seus elementos (coloque zero dentro). Invoque-a no main para inicializar
os três vetores de inteiros criados.

B) Faça uma função que receba um vetor de doubles e inicialize todos
os seus elementos (coloque zero dentro). Invoque-a no main para inicializar
os três vetores de doubles criados.

C) Faça uma função que receba um vetor de inteiros. A função deve imprimir
uma mensagem solicitando que o usuário digite cada um dos elementos. A função
deve ler estes elementos digitados e colocar no vetor. No main, invoque a
função para dois dos três vetores criados.

D) Faça uma função que receba um vetor de doubles. A função deve imprimir
uma mensagem solicitando que o usuário digite cada um dos elementos. A função
deve ler estes elementos digitados e colocar no vetor. No main, invoque a
função para dois dos três vetores criados.

E) Faça uma função que receba três vetores de inteiros, todos do mesmo
tamanho. Dois dos vetores são os digitados no item C. A função deve colocar
no terceiro vetor o maior elemento, indice a indice, dentre os dois
vetores digitados. Exemplo: para o [0] se um vetor tem o valor 500 nesta
posição e o outro tem 356 na posição [0], o elemento [0] do terceiro vetor
deverá receber 500. A função deve retornar o maior inteiro dentre todos.

F) Faça uma função idêntica ao item E, porém para o caso dos vetores de
doubles. Tudo igual, inclusive retornando o double maior.

G) No main, após todos os itens acima, imprima os elementos do terceiro
vetor de inteiros e do terceiro vetor de doubles, além do que as funções
E e F retornaram.

H) Faça uma função que receba dois vetores inteiros do mesmo tamanho.
Compare cada elemento de um com o mesmo indice do outro ([0] de um vetor
com o [0] do outro). Procure pela primeira ocorrência onde um elemento
for positivo e o outro negativo.
Exemplo:
	vet1[0]=4   vet2[0]=5  => ambos são positivos, então continua procurando
	vet1[1]=-5  vet2[1]=-8 => ambos negativos, então continua procurando
	vet1[2]=10  vet2[2]=-2 => Um positivo e outro negativo. ACHOU

A função deve retornar a media entre estes dois elementos. Caso não encontre
este padrão em nenhum indice, então a função deve retornar a média de
todos os elementos de ambos os vetores.
*/
#include <stdio.h>
#define TAM 10

// Etapa a
iniciaVetI(int vet[], int length) {
	int i;

	for (i = 0; i < length; i++) {
		vet[i] = 0;
	}
}
// Etapa b
iniciaVetD(double vet[], int length) {
	int i;

	for (i = 0; i < length; i++) {
		vet[i] = 0;
	}
}
//Etapa c
preeVetI(int vet[], int length) {
	int i;

	for (i = 0; i < length; i++) {
		printf("Preencha a %d posicao do vetor informado com um numero inteiro: ", i + 1);
		scanf("%i", &vet[i]);
	}
}
//Etapa d
preeVetD(double vet[], int length) {
	int i;

	for (i = 0; i < length; i++) {
		printf("Preencha a %d posicao do vetor informado com um numero double: ", i + 1);
		scanf("%lf", &vet[i]);
	}
}
//Etapa e
int maiorEntreVetI(int vet1[], int vet2[], int vet3[], int length) {
	int i,
		maior;

	maior = vet1[0];

	for (i = 0; i < length; i++) {
		if (vet1[i] > vet2[i]) {
			vet3[i] = vet1[i];
			if (vet1[i] > maior) {
				maior = vet1[i];
			}
		} else {
			vet3[i] = vet2[i];
			if (vet2[i] > maior) {
				maior = vet2[i];
			}
		}
	}

	return maior;
}
//Etapa f
double maiorEntreVetD(double vet1[], double vet2[], double vet3[], int length) {
	int i;
	double maior;

	maior = vet1[0];

	for (i = 0; i < length; i++) {
		if (vet1[i] > vet2[i]) {
			vet3[i] = vet1[i];
			if (vet1[i] > maior) {
				maior = vet1[i];
			}
		} else {
			vet3[i] = vet2[i];
			if (vet2[i] > maior) {
				maior = vet2[i];
			}
		}
	}

	return maior;
}
//Etapa h
double mediaNegPos(int vet1[], int vet2[], int length) {
	int i,
		todos = 0;

	for (i = 0; i < length; i++) {
		if ((vet1[i] < 0 && vet2[i] >= 0) || (vet2[i] < 0 && vet1[i] >= 0)) {
			return ((vet1[i] + vet2[i]) / 2);
		} else {
			todos += vet1[i];
			todos += vet2[i];
		}
	}

	return (todos / (length * 2));
}

main() {
	// Variaveis T22
	int i;
	// Variaveis exercicio
	int vetI1[TAM],
		vetI2[TAM],
		vetI3[TAM];
	double vetD1[TAM],
		vetD2[TAM],
		vetD3[TAM];
	// Variaveis etapa e
	int retMaiorI;
	// Variaveis etapa f
	double retMaiorD;

	// Etapa a
	iniciaVetI(vetI1, TAM);
	iniciaVetI(vetI2, TAM);
	iniciaVetI(vetI3, TAM);
	// Etapa b
	iniciaVetD(vetD1, TAM);
	iniciaVetD(vetD2, TAM);
	iniciaVetD(vetD3, TAM);
	// Etapa c
	preeVetI(vetI1, TAM);
	preeVetI(vetI2, TAM);
	// Etapa d
	preeVetD(vetD1, TAM);
	preeVetD(vetD2, TAM);
	// Etapa e
	retMaiorI = maiorEntreVetI(vetI1, vetI2, vetI3, TAM);
	// Etapa f
	retMaiorD = maiorEntreVetD(vetD1, vetD2, vetD3, TAM);
	// Etapa g
	printf("Os itens do terceiro vetor de inteiros sao:\n");
	for (i = 0; i < TAM; i++) {
		printf("\t%d\n", vetI3[i]);
	}
	printf("Os itens do terceiro vetor de doubles sao:\n");
	for (i = 0; i < TAM; i++) {
		printf("\t%lf\n", vetD3[i]);
	}
	printf("\nA funcao E retornou: %d\n", retMaiorI);
	printf("A funcao F retornou: %lf\n", retMaiorD);
	// Etapa h
	printf("A media gerada eh: %lf\n", mediaNegPos(vetI1, vetI2, TAM));
}
