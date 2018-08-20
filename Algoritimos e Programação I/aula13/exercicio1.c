/*
Faça um programa que leia um vetor X apenas com valores inteiros e positivos (garanta isso) e ZERO para finalizar a leitura.
A seguir, solicite um valor N inteiro e positivo ao usuário e: 
	a) verifique se o valor N pertence a X. Exiba uma mensagem indicando a ausência ou presença do vetor. Se o elemento existir,
indique quantas vezes ele ocorre em X e em quais posições; 
	b) calcule quantos elementos em X são maiores que N; 
	c) escreva os elementos de X que são menores que N.
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define QTD_VET 666


main() {
	setlocale(LC_CTYPE, "Portuguese");

	float num;
	int check,
		vet[QTD_VET],
		cont = 0,
		n,
		i,
		qtd_ocorrencias = 0,
		elems_maior = 0;

	while(1) {
		printf("Digite um número inteiro positivo a ser colocado na lista X: ");
		scanf("%f", &num);
		check = num;

		if(num == check && num >= 0) {
			if(num == 0) {
				break;
			} else {
				vet[cont] = num;
				cont++;
			}
		} else {
			printf("Não é um número inteiro e/ou não é positivo!\n");
		}
	}
	while(1) {
		printf("Digite um número N inteiro e positivo para ser validado na lista X: ");
		scanf("%f", &num);
		check = n = num;

		if(num == check && num >= 0) {
			break;
		} else {
			printf("Não é um número inteiro e/ou não é positivo!\n");
		}
	}
	for(i = 0; i < cont; i++) {
		if(n == vet[i]) {
			qtd_ocorrencias++;
		}
		if(vet[i] > n) {
			elems_maior++;
		}
	}
	if(qtd_ocorrencias == 0) {
		printf("Não existem ocorrências do número N inserido na lista X.\n");
	} else {
		printf("Existem %i ocorrências do número N inserido nas posições ", qtd_ocorrencias);
		for(i = 0; i < cont; i++) {
			if(n == vet[i]) {
				printf("%i, ", i);
			}
		}
		printf("da lista X.\n", n);
	}
	printf("Existe(m) %i número(s) na lista X maior(es) que N.\n"
			"O(s) elemento(s) ", elems_maior);
	for(i = 0; i < cont; i++) {
		if(vet[i] < n) {
			printf("%i, ", vet[i]);
		}
	}
	printf("esta(ão) na lista X sendo menor(es) que o número N inserido.\n");
	
	system("pause");
}