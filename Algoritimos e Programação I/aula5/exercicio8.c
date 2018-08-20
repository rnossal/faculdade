/*
Uma empresa concederá um aumento especial aos seus funcionários, conforme a 
tabela abaixo. Faça um programa que leia o salário atual, calcule e escreva o valor 
do aumento e novo salario.

Salário Atual		Percentual de Aumento
de 100 a 500		10%
de 501 a 1000		8%
de 1001 a 2000		4,8%
acima de 2000		3,2%

*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");

	float salario, aumento;

	printf("Digite o salário atual: ");
	scanf("%f", &salario);

	if(salario >= 100 && salario <= 500) {
		aumento = salario * 0.1;
	} else if(salario >= 501 && salario <= 1000) {
		aumento = salario * 0.08;
	} else if(salario >= 1001 && salario <= 2000) {
		aumento = salario * 0.048;
	} else if(salario > 2000) {
		aumento = salario * 0.032;
	} else {
		printf("Salário abaixo de R$ 100 não recebe aumento.\n");
	}

	printf("\nSalário atual: %.2f\n"
		"Valor do aumento: %.2f\n"
		"Novo salário: %.2f\n", salario, aumento, salario + aumento);
}