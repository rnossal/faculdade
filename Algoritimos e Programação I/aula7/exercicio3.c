/*
Escreva um programa que leia 10 conjuntos de 2 valores, o primeiro representando o número de um aluno, e o segundo representando a sua altura em centímetros. Encontre o aluno mais alto e o mais baixo. Mostre o número do aluno mais alto e do mais baixo, junto com suas alturas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");

	int contador = 0,
		aluno,
		alunoMaior,
		alunoMenor,
		altura,
		alturaMaior,
		alturaMenor;

	while (contador < 10) {
		printf("Insira o número do aluno: ");
		scanf("%i", &aluno);
		printf("Insira sua altura (em centímetros): ");
		scanf("%i", &altura);

		if (contador != 0) {
			if (altura > alturaMaior) {
				alturaMaior = altura;
				alunoMaior = aluno;
			} else if (altura < alturaMenor) {
				alturaMenor = altura;
				alunoMenor = aluno;
			}
		} else {
			alturaMenor = alturaMaior = altura;
			alunoMenor = alunoMaior = aluno;
		}

		contador++;
	}
	
	printf("Aluno mais alto: %i - %i\n"
			"Aluno mais baixo: %i - %i\n", alunoMaior, alturaMaior, alunoMenor, alturaMenor);

	system("pause");
}