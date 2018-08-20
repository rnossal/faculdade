/*
Um posto está vendendo combustíveis com a seguinte tabela de descontos:
Álcool : 
	Até 20 litros, desconto de 3% por litro.
	Acima de 20 litros, desconto de 5% por litro.
Gasolina:
	Até 15 litros, desconto de 3,5 % por litro.
	Acima de 15 litros, desconto de 6% por litro. 
Diesel:
	Até 30 litros, desconto de 4% por litro.
	Acima de 30 litros, desconto de 7% por litro.

Escreva um programa em C que lê o número de litros vendidos, o tipo de combustível (codificado da seguinte forma: 1 para álcool, 2 para gasolina e 3 para diesel), calcula e escreve na tela o valor a ser pago pelo cliente, considerando os descontos mencionados e que o preço do litro da gasolina neste posto é R$ 2,749, do álcool é R$ 2,099 e do diesel R$ 1,589. Use switch e faça consistência dos dados de   entrada (exiba mensagens de erro quando dados incorretos forem digitados e só faça os cálculos quando todos os dados digitados forem válidos).
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");

	int tipoComb;
	float litros, total;

	printf("Informe o tipo de combustível conforme a tabela abaixo:\n"
		"1 - Álcool\n"
		"2 - Gasolina\n"
		"3 - Diesel\n");
	scanf("%i", &tipoComb);

	printf("Digite a quantidade de litros vendidos: ");
	scanf("%f", &litros);

	if(litros > 0) {
		switch(tipoComb) {
			case 1:
				total = litros * 2.099;
				if(litros <= 20) {
					total -= total * 0.03;
				} else {
					total -= total * 0.05;
				}
				break;
			case 2:
				total = litros * 2.749;
				if(litros <= 15) {
					total -= total * 0.035;
				} else {
					total -= total * 0.06;
				}
				break;
			case 3:
				total = litros * 1.589;
				if(litros <= 30) {
					total -= total * 0.04;
				} else {
					total -= total * 0.07;
				}
				break;
			default:
				printf("Tipo de combustível inválido.\n");
		}
		printf("Valor a ser pago: %.2f\n", total);
	} else {
		printf("Não existe quantidade de combustível o suficiente para calcular.\n");
	}

	system("pause");
}