/*
A prefeitura de uma cidade fez uma pesquisa entre seus habitantes, coletando dados sobre o salário e número de filhos. A prefeitura deseja saber: 
	a) média do salário da população; 
	b) média do número de filhos; 
	c) maior salário; 
	d) percentual de pessoas com salário até R$1000,00. 
Faça um programa que ajude a prefeitura a contabilizar os dados coletados e calcule e escreva os itens solicitados acima. O final da leitura de dados deve ser com a entrada de um salário negativo.

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");

	float salario = 0,
		maiorSalario = 0,
		totalSalario = 0;
	int contadorHabitantes = 0,
		habitantesAte1000 = 0,
		filhos = 0,
		totalFilhos = 0;

	while (1) {
		printf("Digite o valor do salário do habitante: ");
		scanf("%f", &salario);

		if (salario < 0) {
			break;
		}

		printf("Digite a quantidade de filhos do habitante: ");
		scanf("%i", &filhos);

		totalSalario += salario;
		totalFilhos += filhos;

		if (salario <= 1000) {
			habitantesAte1000++;
		} else if (salario > maiorSalario) {
			maiorSalario = salario;
		}

		contadorHabitantes++;
	}

	printf("Média salarial entre a população: %.2f\n"
			"Média de número de filhos entre a população: %i\n"
			"Maior salário entre os habitantes: %.2f\n"
			"Quantidade percentual de pessoas com salário de até R$ 1000,00: %.2d%%\n", totalSalario / contadorHabitantes, totalFilhos / contadorHabitantes, maiorSalario, (habitantesAte1000 * 100) / contadorHabitantes);

	system("pause");
}