/*
Alcemar tem 1,50 metro e cresce 2 centímetros por ano, enquanto Joselito tem 1,10 metro e cresce 3 centímetros por ano. Construa um programa que calcule e escreva quantos anos serão necessários para que Joselito seja maior que Alcemar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");
	float alcemarAltura = 1.50,
		joselitoAltura = 1.10;
	int anos = 0;

	while (joselitoAltura <= alcemarAltura) {
		alcemarAltura += 0.02;
		joselitoAltura += 0.03;

		anos++;
	}

	printf("Serão necessários %i anos para Joselito ultrapassar a idade de Alcemar.\n", anos);

	system("pause");
}