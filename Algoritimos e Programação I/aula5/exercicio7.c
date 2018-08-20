/*
Faça um programa que leia o tipo de cômodo de uma casa, as dimensões desse cômodo (comprimento e largura), calcula e escreve a quantidade de lâmpadas de 60 watts necessárias para iluminar esse cômodo adequadamente. 
Use a tabela a seguir no seu programa para calcular a quantidade de lâmpadas. 
Lembre-se que essa quantidade deve ser um valor inteiro.

Tipo	Cômodo			Necessidade de luminosidade em watts por metro quadrado
1		quarto			15
2		cozinha			20
3		banheiro		18
4		escritório		20
5		sala			18
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

main() {
	setlocale(LC_ALL, "Portuguese");

	int comodo;
	float comprimento, largura, metroQuadrado, watts;

	printf("Informe o tipo de cômodo conforme a tabela a seguir:\n"
		"1 - Quarto\n"
		"2 - Cozinha\n"
		"3 - Banheiro\n"
		"4 - Escritório\n"
		"5 - Sala\n");
	scanf("%i", &comodo);

	printf("Informe o comprimento do cômodo: ");
	scanf("%f", &comprimento);

	printf("Informe a largura do cômodo: ");
	scanf("%f", &largura);

	metroQuadrado = comprimento * largura;
	switch(comodo) {
		case 1:
			watts = (metroQuadrado * 15) / 60;
			break;
		case 2:
			watts = (metroQuadrado * 20) / 60;
			break;
		case 3:
			watts = (metroQuadrado * 18) / 60;
			break;
		case 4:
			watts = (metroQuadrado * 20) / 60;
			break;
		case 5:
			watts = (metroQuadrado * 18) / 60;
			break;
		default:
			printf("Tipo de cômodo inválido.\n");
	}

	printf("Quantidade de lâmpadas necessárias: %.0f\n", ceil(watts));

	system("pause");
}